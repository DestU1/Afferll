#include "AfrlPch.h"
#include "Afferll/Base/Application.h"
#include "Afferll/Base/Window.h"


namespace Afferll
{
	Application::Application()
		: m_Running(false)
	{
		AFRL_LOG(Debug, "Application initialization.");
	}
	Application::~Application()
	{
	}

	void kp(KeyPressEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}).", e.GetType(), e.GetKeyCode());
	}
	void kr(KeyReleaseEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}).", e.GetType(), e.GetKeyCode());
	}
	void krp(KeyRepeatEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}).", e.GetType(), e.GetKeyCode());
	}
	void kt(KeyTypeEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}).", e.GetType(), e.GetChar());
	}
	void mp(MousePressEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}).", e.GetType(), e.GetMouseButton());
	}
	void mr(MouseReleaseEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}).", e.GetType(), e.GetMouseButton());
	}
	void ms(MouseScrollEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}, {}).", e.GetType(), e.GetXOffset(), e.GetYOffset());
	}
	void wm(WindowMoveEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}, {}).", e.GetType(), e.GetLeft(), e.GetTop());
	}
	void wf(WindowFocusEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}", e.GetType());
	}
	void wfl(WindowFocusLossEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}", e.GetType());
	}
	void wr(WindowResizeEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}, ({}, {})", e.GetType(), e.GetWidth(), e.GetHeight());
	}
	void wc(WindowCloseEvent& e)
	{
		AFRL_LOG(Debug, "Type: {}", e.GetType());
	}
	

	void Application::OnEvent(Event& e)
	{
		EventDispacher fetcher(e);
		fetcher.Dispach<KeyPressEvent>(kp);
		fetcher.Dispach<KeyReleaseEvent>(kr);
		fetcher.Dispach<KeyRepeatEvent>(krp);
		fetcher.Dispach<KeyTypeEvent>(kt);
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
		window->SetEventCallback((Window::EventCallback_t&)std::bind(&Application::OnEvent, this));

		m_Running = true;
		while (m_Running)
		{
			window->OnUpdate();
		}

		delete window;
	}
}