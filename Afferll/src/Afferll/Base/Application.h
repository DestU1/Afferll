#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Base/Window.h"
#include "Afferll/Base/LayerStack.h"
#include "Afferll/Renderer/VertexBuffer.h"
#include "Afferll/Renderer/IndexBuffer.h"
#include "Afferll/Renderer/Shader.h"


namespace Afferll
{
	class AFRL_API Application
	{
	public:
		Application();
		virtual ~Application();

		static Application* Create();

		static Application* GetInstance();
		Window* GetWindow();

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

		static Application* s_Instance;


		unsigned int m_VertexArray;
		VertexBuffer* vb;
		IndexBuffer* ib;
		Shader* sdr;
	};
}