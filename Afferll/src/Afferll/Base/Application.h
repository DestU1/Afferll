#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Events/Events.h"


namespace Afferll
{
	class AFRL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool m_Running;
	};

	Application* CreateApplication();
}