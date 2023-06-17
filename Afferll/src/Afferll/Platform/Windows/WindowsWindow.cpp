#include "AfrlPch.h"
#include "Afferll/Platform/Windows/WindowsWindow.h"


namespace Afferll
{
	WindowsWindowManager::WindowDictionary::WindowDictionary(HWND windowHandle, Window* associatedWindow)
		: m_WindowHandle(windowHandle), m_AssociatedWindow(associatedWindow)
	{
	}


	WindowsWindowManager* WindowsWindowManager::s_Instance = new WindowsWindowManager();

	WindowsWindowManager::WindowsWindowManager()
		: m_InstanceHandle(GetModuleHandle(NULL)), m_WindowClassName("AfferllWindow"), m_WindowClassRegistered(false), m_WindowDictionary()
	{
		RegisterWindowClass();
	}
	WindowsWindowManager::~WindowsWindowManager()
	{
		UnRegisterWindowClass();
		s_Instance = nullptr;
	}

	WindowsWindowManager* WindowsWindowManager::GetInstance()
	{
		return s_Instance;
	}
	void WindowsWindowManager::Destroy()
	{
		delete s_Instance;
	}

	void WindowsWindowManager::ProcessMessages()
	{
		MSG msg = { };
		while (PeekMessageA(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
	}

	uint64_t WindowsWindowManager::GetWindowCount()
	{
		return m_WindowDictionary.size();
	}
	Window* WindowsWindowManager::GetWindow(HWND windowHandle)
	{
		for (WindowDictionary i : m_WindowDictionary)
			if (i.m_WindowHandle == windowHandle)
				return i.m_AssociatedWindow;

		return nullptr;
	}
	HWND WindowsWindowManager::GetWindowHandle(Window* window)
	{
		for (WindowDictionary i : m_WindowDictionary)
			if (i.m_AssociatedWindow == window)
				return i.m_WindowHandle;

		return NULL;
	}
	const std::string& WindowsWindowManager::GetWindowClassName()
	{
		return m_WindowClassName;
	}
	HINSTANCE WindowsWindowManager::GetInstanceHandle()
	{
		return m_InstanceHandle;
	}

	void WindowsWindowManager::OnWindowCreate(HWND windowHandle, Window* window)
	{
		m_WindowDictionary.push_back(WindowDictionary(windowHandle, window));
	}
	void WindowsWindowManager::OnWindowClose(HWND windowHandle)
	{
		for (uint64_t i = 0; i < m_WindowDictionary.size(); ++i)
		{
			if (m_WindowDictionary[i].m_WindowHandle == windowHandle)
			{
				m_WindowDictionary.erase(m_WindowDictionary.begin() + i);
				return;
			}
		}
	}
	void WindowsWindowManager::OnWindowClose(Window* window)
	{
		for (uint64_t i = 0; i < m_WindowDictionary.size(); ++i)
		{
			if (m_WindowDictionary[i].m_AssociatedWindow == window)
			{
				m_WindowDictionary.erase(m_WindowDictionary.begin() + i);
				return;
			}
		}
	}
	void WindowsWindowManager::OnQuitMessage()
	{
		for (WindowDictionary i : m_WindowDictionary)
			i.m_AssociatedWindow->Close();

		Destroy();
	}

	bool WindowsWindowManager::RegisterWindowClass()
	{
		if (m_WindowClassRegistered)
			return true;

		WNDCLASSEXA wndClass = { };
		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.hInstance = m_InstanceHandle;
		wndClass.lpszClassName = m_WindowClassName.c_str();
		wndClass.lpfnWndProc = DefWindowProc;
		wndClass.style = CS_OWNDC;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hCursor = NULL;
		wndClass.hIcon = NULL;
		wndClass.hIconSm = NULL;
		wndClass.hbrBackground = NULL;
		wndClass.lpszMenuName = NULL;

		m_WindowClassRegistered = RegisterClassExA(&wndClass);
		return m_WindowClassRegistered;
	}
	bool WindowsWindowManager::UnRegisterWindowClass()
	{
		if (!m_WindowClassRegistered)
			return true;

		m_WindowClassRegistered = !UnregisterClassA(m_WindowClassName.c_str(), m_InstanceHandle);
		return !m_WindowClassRegistered;
	}
	LRESULT __stdcall WindowsWindowManager::WindowProcDispacher(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Window* window = s_Instance->GetWindow(hWnd);
		if (!window)
			return DefWindowProc(hWnd, msg, wParam, lParam);

		static int lastKey = -1;
		switch (msg)
		{
		case WM_LBUTTONDOWN:
		{
			MousePressEvent e(MouseButton::Left);
			window->DispachEvent(e);
			break;
		}
		case WM_LBUTTONUP:
		{
			MouseReleaseEvent e(MouseButton::Left);
			window->DispachEvent(e);
			break;
		}
		case WM_RBUTTONDOWN:
		{
			MousePressEvent e(MouseButton::Right);
			window->DispachEvent(e);
			break;
		}
		case WM_RBUTTONUP:
		{
			MouseReleaseEvent e(MouseButton::Right);
			window->DispachEvent(e);
			break;
		}
		case WM_MBUTTONDOWN:
		{
			MousePressEvent e(MouseButton::Middle);
			window->DispachEvent(e);
			break;
		}
		case WM_MBUTTONUP:
		{
			MouseReleaseEvent e(MouseButton::Middle);
			window->DispachEvent(e);
			break;
		}
		case WM_XBUTTONDOWN:
		{
			// wParam's upper word holds the xbutton number (1 for x1, 2 for x2) add 2 to get 3 for x1 and 4 for x2
			// ((wParam >> 48) | XBUTTON1) * 3 + ((wParam >> 48) | XBUTTON2) * 4
			MousePressEvent e((MouseButton)((wParam >> 48) + 2));
			window->DispachEvent(e);
			break;
		}
		case WM_XBUTTONUP:
		{
			MouseReleaseEvent e((MouseButton)((wParam >> 48) + 2));
			window->DispachEvent(e);
			break;
		}

		case WM_MOUSEMOVE:
		{
			POINTS mousePoint = MAKEPOINTS(lParam);
			MouseMoveEvent e(mousePoint.x, mousePoint.y);
			window->DispachEvent(e);
			break;
		}

		case WM_MOUSEWHEEL:
		{
			MouseScrollEvent e(0, GET_WHEEL_DELTA_WPARAM(wParam));
			window->DispachEvent(e);
			break;
		}
		case WM_MOUSEHWHEEL:
		{
			MouseScrollEvent e(GET_WHEEL_DELTA_WPARAM(wParam), 0);
			window->DispachEvent(e);
			break;
		}

		case WM_KEYDOWN:
		{
			if (lastKey != wParam)
			{
				lastKey = (uint8_t)wParam;
				KeyPressEvent e((uint8_t)wParam);
				window->DispachEvent(e);
				break;
			}

			KeyRepeatEvent e((uint8_t)wParam);
			window->DispachEvent(e);
			break;
		}
		case WM_KEYUP:
		{
			lastKey = -1;
			KeyReleaseEvent e((uint8_t)wParam);
			window->DispachEvent(e);
			break;
		}
		case WM_CHAR:
		{
			KeyTypeEvent e((uint8_t)wParam);
			window->DispachEvent(e);
			break;
		}


		case WM_SETFOCUS:
		{
			WindowFocusEvent e;
			window->DispachEvent(e);
			break;
		}
		case WM_KILLFOCUS:
		{
			WindowFocusLossEvent e;
			window->DispachEvent(e);
			break;
		}
		case WM_SIZE:
		{
			WindowResizeEvent e(LOWORD(lParam), HIWORD(lParam));
			window->DispachEvent(e);
			break;
		}
		case WM_MOVE:
		{
			WindowMoveEvent e((int64_t)(short)LOWORD(lParam), (int64_t)(short)HIWORD(lParam));
			window->DispachEvent(e);
			break;
		}
		case WM_CLOSE:
		{
			WindowCloseEvent e;
			window->DispachEvent(e);
			window->Close();
			break;
		}

		case WM_QUIT:
		{
			s_Instance->OnQuitMessage();
			break;
		}
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}


	WindowsWindow::WindowsWindow(const WindowProperties& properties)
		: m_Properties(properties), m_WindowHandle(NULL), m_EventCallback(nullptr)
	{
		Initialize();
	}
	WindowsWindow::~WindowsWindow()
	{
		Close();
	}

	void WindowsWindow::OnUpdate()
	{
		WindowsWindowManager::GetInstance()->ProcessMessages();
	}
	void WindowsWindow::Close()
	{
		if (m_WindowHandle != NULL)
		{
			WindowsWindowManager::GetInstance()->OnWindowClose(m_WindowHandle);
			DestroyWindow(m_WindowHandle);
			m_WindowHandle = NULL;
		}
	}

	const std::string& WindowsWindow::GetTitle()
	{
		return m_Properties.m_Title;
	}
	uint64_t WindowsWindow::GetWidth()
	{
		return m_Properties.m_Width;
	}
	uint64_t WindowsWindow::GetHeight()
	{
		return m_Properties.m_Height;
	}

	void WindowsWindow::SetEventCallback(const EventCallback_t& eventCallback)
	{
		m_EventCallback = eventCallback;
	}
	void WindowsWindow::DispachEvent(Event& e)
	{
		if (m_EventCallback)
			m_EventCallback(e);
	}

	void WindowsWindow::Initialize()
	{
		RECT rect = { 0, 0, (LONG)m_Properties.m_Width, (LONG)m_Properties.m_Height };
		bool ret = AdjustWindowRect(&rect, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, false);
		AFRL_ASSERT(ret, "AdjustWindowRect() failed.");

		m_WindowHandle = CreateWindowExA(
			NULL,
			WindowsWindowManager::GetInstance()->GetWindowClassName().c_str(),
			NULL,
			WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			rect.right - rect.left,
			rect.bottom - rect.top,
			NULL,
			NULL,
			WindowsWindowManager::GetInstance()->GetInstanceHandle(),
			NULL
		);
		AFRL_ASSERT(m_WindowHandle, "CreateWindowExA() failed.");

		WindowsWindowManager::GetInstance()->OnWindowCreate(m_WindowHandle, this);
		SetWindowLongPtrA(m_WindowHandle, GWLP_WNDPROC, (LONG_PTR)WindowsWindowManager::GetInstance()->WindowProcDispacher);

		ret = SetWindowTextA(m_WindowHandle, m_Properties.m_Title.c_str());
		AFRL_ASSERT(ret, "SetWindowTextA() failed.");

		ShowWindow(m_WindowHandle, SW_SHOW);
	}
}