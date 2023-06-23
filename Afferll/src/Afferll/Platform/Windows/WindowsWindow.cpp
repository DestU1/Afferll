#include "AfrlPch.h"
#include "Afferll/Platform/Windows/WindowsWindow.h"


namespace Afferll
{
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

	const std::string& WindowsWindowManager::GetWindowClassName()
	{
		return m_WindowClassName;
	}
	HINSTANCE WindowsWindowManager::GetInstanceHandle()
	{
		return m_InstanceHandle;
	}
	uint64_t WindowsWindowManager::GetWindowCount()
	{
		return m_WindowDictionary.size();
	}
	Window* WindowsWindowManager::GetWindow(HWND windowHandle)
	{
		return m_WindowDictionary[windowHandle];
	}

	void WindowsWindowManager::OnWindowCreate(HWND windowHandle, Window* window)
	{
		m_WindowDictionary[windowHandle] = window;
	}
	void WindowsWindowManager::OnWindowClose(HWND windowHandle)
	{
		m_WindowDictionary.erase(windowHandle);
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

		static KeyCode lastKey = KeyCode::Invalid;
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
				KeyCode key = TranslateKeyCode(wParam, lParam);
				if (lastKey != key)
				{
					lastKey = key;
					KeyPressEvent e(key);
					window->DispachEvent(e);
					break;
				}

				KeyRepeatEvent e(key);
				window->DispachEvent(e);
				break;
			}
			case WM_KEYUP:
			{
				lastKey = KeyCode::Invalid;
				KeyCode key = TranslateKeyCode(wParam, lParam);
				KeyReleaseEvent e(key);
				window->DispachEvent(e);
				break;
			}
			case WM_CHAR:
			{
				KeyTypeEvent e((char)wParam);
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
				break;
			}
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	KeyCode WindowsWindowManager::TranslateKeyCode(WPARAM wParam, LPARAM lParam)
	{
		bool ex = lParam & (1 << 24);
		switch (wParam)
		{
			case '0':
				return KeyCode::D0;
			case '1':
				return KeyCode::D1;
			case '2':
				return KeyCode::D2;
			case '3':
				return KeyCode::D3;
			case '4':
				return KeyCode::D4;
			case '5':
				return KeyCode::D5;
			case '6':
				return KeyCode::D6;
			case '7':
				return KeyCode::D7;
			case '8':
				return KeyCode::D8;
			case '9':
				return KeyCode::D9;

			case 'A':
				return KeyCode::A;
			case 'B':
				return KeyCode::B;
			case 'C':
				return KeyCode::C;
			case 'D':
				return KeyCode::D;
			case 'E':
				return KeyCode::E;
			case 'F':
				return KeyCode::F;
			case 'G':
				return KeyCode::G;
			case 'H':
				return KeyCode::H;
			case 'I':
				return KeyCode::I;
			case 'J':
				return KeyCode::J;
			case 'K':
				return KeyCode::K;
			case 'L':
				return KeyCode::L;
			case 'M':
				return KeyCode::M;
			case 'N':
				return KeyCode::N;
			case 'O':
				return KeyCode::O;
			case 'P':
				return KeyCode::P;
			case 'Q':
				return KeyCode::Q;
			case 'R':
				return KeyCode::R;
			case 'S':
				return KeyCode::S;
			case 'T':
				return KeyCode::T;
			case 'U':
				return KeyCode::U;
			case 'V':
				return KeyCode::V;
			case 'W':
				return KeyCode::W;
			case 'X':
				return KeyCode::X;
			case 'Y':
				return KeyCode::Y;
			case 'Z':
				return KeyCode::Z;

			case VK_F1:
				return KeyCode::F1;
			case VK_F2:
				return KeyCode::F2;
			case VK_F3:
				return KeyCode::F3;
			case VK_F4:
				return KeyCode::F4;
			case VK_F5:
				return KeyCode::F5;
			case VK_F6:
				return KeyCode::F6;
			case VK_F7:
				return KeyCode::F7;
			case VK_F8:
				return KeyCode::F8;
			case VK_F9:
				return KeyCode::F9;
			case VK_F10:
				return KeyCode::F10;
			case VK_F11:
				return KeyCode::F11;
			case VK_F12:
				return KeyCode::F12;

			case VK_UP:
				return ex ? KeyCode::UpArrow : KeyCode::NumPad8;
			case VK_DOWN:
				return ex ? KeyCode::DownArrow : KeyCode::NumPad2;
			case VK_LEFT:
				return ex ? KeyCode::LeftArrow : KeyCode::NumPad4;
			case VK_RIGHT:
				return ex ? KeyCode::RightArrow : KeyCode::NumPad6;

			case VK_MULTIPLY:
				return KeyCode::NumPadMultiply;
			case VK_ADD:
				return KeyCode::NumPadPlus;
			case VK_SUBTRACT:
				return KeyCode::NumPadMinus;
			case VK_DECIMAL:
				return KeyCode::NumPadPeriod;
			case VK_DIVIDE:
				return KeyCode::NumPadDivide;
			case VK_NUMLOCK:
				return KeyCode::NumLock;
			case VK_NUMPAD0:
				return KeyCode::NumPad0;
			case VK_NUMPAD1:
				return KeyCode::NumPad1;
			case VK_NUMPAD2:
				return KeyCode::NumPad2;
			case VK_NUMPAD3:
				return KeyCode::NumPad3;
			case VK_NUMPAD4:
				return KeyCode::NumPad4;
			case VK_NUMPAD5:
				return KeyCode::NumPad5;
			case VK_NUMPAD6:
				return KeyCode::NumPad6;
			case VK_NUMPAD7:
				return KeyCode::NumPad7;
			case VK_NUMPAD8:
				return KeyCode::NumPad8;
			case VK_NUMPAD9:
				return KeyCode::NumPad9;

			case VK_OEM_3:
				return KeyCode::GraveAccent;
			case VK_OEM_MINUS:
				return KeyCode::Minus;
			case VK_OEM_PLUS:
				return KeyCode::Plus;
			case VK_OEM_4:
				return KeyCode::LeftBracket;
			case VK_OEM_6:
				return KeyCode::RightBracket;
			case VK_OEM_5:
				return KeyCode::BackSlash;
			case VK_OEM_1:
				return KeyCode::SemiColon;
			case VK_OEM_7:
				return KeyCode::Apostrophe;
			case VK_OEM_COMMA:
				return KeyCode::Comma;
			case VK_OEM_PERIOD:
				return KeyCode::Period;
			case VK_OEM_2:
				return KeyCode::Slash;

			case VK_ESCAPE:
				return KeyCode::Escape;
			case VK_BACK:
				return KeyCode::BackScape;
			case VK_RETURN:
				return ex ? KeyCode::NumPadEnter : KeyCode::Enter;
			case VK_SHIFT:
			{
				UINT keyCode = MapVirtualKeyA((lParam & 0x00ff0000) >> 16, MAPVK_VSC_TO_VK_EX);
				return (keyCode == VK_RSHIFT) ? KeyCode::RightShift : KeyCode::LeftShift;
			}
			case VK_CONTROL:
				return ex ? KeyCode::RightControl : KeyCode::LeftControl;
			case VK_APPS:
				return KeyCode::Applications;
			case VK_RWIN:
				return KeyCode::RightMenu;
			case VK_LWIN:
				return KeyCode::LeftMenu;
			case VK_MENU:
				return ex ? KeyCode::RightAlt : KeyCode::LeftAlt;
			case VK_SPACE:
				return KeyCode::Space;
			case VK_CAPITAL:
				return KeyCode::CapsLock;
			case VK_TAB:
				return KeyCode::Tab;

			case VK_SNAPSHOT:
				return KeyCode::PrintScreen;
			case VK_SCROLL:
				return KeyCode::ScrollLock;
			case VK_PAUSE:
				return KeyCode::Pause;
			case VK_INSERT:
				return ex ? KeyCode::Insert : KeyCode::NumPad0;
			case VK_HOME:
				return ex ? KeyCode::Home : KeyCode::NumPad7;
			case VK_PRIOR:
				return ex ? KeyCode::PageUp : KeyCode::NumPad9;
			case VK_DELETE:
				return ex ? KeyCode::Delete : KeyCode::NumPadPeriod;
			case VK_END:
				return ex ? KeyCode::End : KeyCode::NumPad1;
			case VK_NEXT:
				return ex ? KeyCode::PageDown : KeyCode::NumPad3;

			case VK_CLEAR:
				return KeyCode::NumPad5;

			default:
				return KeyCode::Invalid;
		}
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
			WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE | WS_SIZEBOX,
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
	}
}