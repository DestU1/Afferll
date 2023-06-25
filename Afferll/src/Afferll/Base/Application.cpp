#include "AfrlPch.h"
#include "Afferll/Base/Application.h"
#include "Afferll/Base/Window.h"
#include "Afferll/ImGui/ImGuiLayer.h"


namespace Afferll
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
		: m_Running(false)
	{
		AFRL_LOG(Info, "Application initialization.");
		s_Instance = this;
		m_Window = Window::Create();
		m_Window->SetEventCallback(AFRL_MEMBER_CALLBACK(OnEvent));

		PushOverlay(new ImGuiLayer());
	}
	Application::~Application()
	{
		delete m_Window;
	}

	Application* Application::GetInstance()
	{
		return s_Instance;
	}
	Window* Application::GetWindow()
	{
		return m_Window;
	}
	
	void Application::Run()
	{
		m_Running = true;
		while (m_Running)
		{
			m_Window->OnUpdate();

			for (uint64_t i = 0; i < m_LayerStack.GetCount(); ++i)
				m_LayerStack.GetLayer(i)->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispacher dispacher(e);
		dispacher.Dispach<WindowCloseEvent>(AFRL_MEMBER_CALLBACK(OnWindowClose));

		if (e.IsHandled())
			return;


		for (uint64_t i = m_LayerStack.GetCount(); i > 0; --i)
		{
			m_LayerStack.GetLayer(i - 1)->OnEvent(e);
			if (e.IsHandled())
				return;
		}
	}
	void Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		e.Resolve();
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}
	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
	}
	void Application::PopOverlay(Layer* overlay)
	{
		m_LayerStack.PopOverlay(overlay);
	}
}