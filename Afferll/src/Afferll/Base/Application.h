#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Base/Window.h"
#include "Afferll/Events/Events.h"
#include "Afferll/Base/LayerStack.h"


namespace Afferll
{
	class AFRL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void OnWindowClose(WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

	private:
		bool m_Running;
		Window* m_Window;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}