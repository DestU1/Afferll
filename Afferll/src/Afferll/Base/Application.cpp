#include "AfrlPch.h"
#include "Afferll/Base/Application.h"
#include "Afferll/Base/Window.h"


namespace Afferll
{
	Application::Application()
	{
		AFRL_LOG(Debug, "Application initialization.");
	}
	Application::~Application()
	{
	}

	void kp(KeyPressEvent& e)
	{
		AFRL_LOG(Debug, "Key press {}.", e.GetKeyCode());
	}
	void kr(KeyReleaseEvent& e)
	{
		AFRL_LOG(Debug, "Key release {}.", e.GetKeyCode());
	}
	void krp(KeyRepeatEvent& e)
	{
		AFRL_LOG(Debug, "Key repeat {}.", e.GetKeyCode());
	}
	void kt(KeyTypeEvent& e)
	{
		AFRL_LOG(Debug, "Key type {}.", (char)e.GetCharCode());
	}
	void mm(MouseMoveEvent& e)
	{
		AFRL_LOG(Debug, "Mouse move {}, {}.", e.GetXPos(), e.GetYPos());
	}
	void mp(MousePressEvent& e)
	{
		AFRL_LOG(Debug, "Mouse press {}.", (int)e.GetMouseButton());
	}
	void mr(MouseReleaseEvent& e)
	{
		AFRL_LOG(Debug, "Mouse release {}.", (int)e.GetMouseButton());
	}
	void ms(MouseScrollEvent& e)
	{
		AFRL_LOG(Debug, "Mouse scroll {}, {}.", e.GetXOffset(), e.GetYOffset());
	}
	void wm(WindowMoveEvent& e)
	{
		AFRL_LOG(Debug, "Window move {}, {}.", e.GetLeft(), e.GetTop());
	}
	void wf(WindowFocusEvent& e)
	{
		AFRL_LOG(Debug, "Window focus");
	}
	void wfl(WindowFocusLossEvent& e)
	{
		AFRL_LOG(Debug, "Window focus loss");
	}
	void wr(WindowResizeEvent& e)
	{
		AFRL_LOG(Debug, "Window resize {}, {}", e.GetWidth(), e.GetHeight());
	}
	void wc(WindowCloseEvent& e)
	{
		AFRL_LOG(Debug, "Window close");
	}

	void fetch(Event& e)
	{
		EventDispacher fetcher(e);
		fetcher.Dispach<KeyPressEvent>(kp);
		fetcher.Dispach<KeyReleaseEvent>(kr);
		fetcher.Dispach<KeyRepeatEvent>(krp);
		fetcher.Dispach<KeyTypeEvent>(kt);
		fetcher.Dispach<MouseMoveEvent>(mm);
		fetcher.Dispach<MousePressEvent>(mp);
		fetcher.Dispach<MouseReleaseEvent>(mr);
		fetcher.Dispach<MouseScrollEvent>(ms);
		fetcher.Dispach<WindowMoveEvent>(wm);
		fetcher.Dispach<WindowFocusEvent>(wf);
		fetcher.Dispach<WindowFocusLossEvent>(wfl);
		fetcher.Dispach<WindowResizeEvent>(wr);
		fetcher.Dispach<WindowCloseEvent>(wc);
	}

	void Application::Run()
	{
		Window* window = Window::Create();
		window->SetEventCallback(fetch);

		while (!GetAsyncKeyState(VK_END))
		{
			window->OnUpdate();
			continue;
		}

		delete window;
	}
}