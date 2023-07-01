#include "AfrlPch.h"
#include "Afferll/Base/Application.h"
#include "Afferll/ImGui/ImGuiLayer.h"
#include "Afferll/Base/Input.h"

#include "Glad/include/glad/glad.h"


namespace Afferll
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
		: m_Running(false)
	{
		AFRL_LOG(Info, "Application initialization.");
		s_Instance = this;

		m_Window = Window::Create();
		m_Window->Initialize();
		m_Window->SetEventCallback(AFRL_MEMBER_CALLBACK(OnEvent));

		PushOverlay(new ImGuiLayer());


		AFRL_LOG(Info, "OpenGL Info:");
		AFRL_LOG(Info, ">   Version:  {}.", (char*)glGetString(GL_VERSION));
		AFRL_LOG(Info, ">   Vendor:   {}.", (char*)glGetString(GL_VENDOR));
		AFRL_LOG(Info, ">   Renderer: {}.", (char*)glGetString(GL_RENDERER));


		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		float vertices[] = {
			1.f, 1.f, 0.0f,
			 -1.f,  1.f, 0.0f,
			 1.f, -1.f, 0.0f,
		}; 
		vb = VertexBuffer::Create(vertices, sizeof(vertices) / sizeof(float));
		vb->Bind();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

		uint32_t indecies[] = {
			0, 1, 2
		};
		ib = IndexBuffer::Create(indecies, sizeof(indecies) / sizeof(uint32_t));
		ib->Bind();

		sdr = Shader::Create(
			R"(
				#version 410
					
				layout(location = 0) in vec3 i_Position;
				out vec3 f_Position;

				void main()
				{
					f_Position = i_Position;
					gl_Position = vec4(i_Position, 1.0);
				}
			)",

			R"(
				#version 410
					
				layout(location = 0) out vec4 o_Color;
				in vec3 f_Position;

				void main()
				{
					o_Color = vec4(f_Position, 1.0);
				}
			)"
		);
		sdr->Bind();
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
			m_Window->ProcessMessages();
			m_Window->GetContext()->ClearScreen(0.1f, 0.1f, 0.1f, 1.f);

			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, NULL);


			for (uint64_t i = 0; i < m_LayerStack.GetCount(); ++i)
				m_LayerStack.GetLayer(i)->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		Input::OnEvent(e);


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