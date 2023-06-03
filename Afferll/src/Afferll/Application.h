#pragma once
#include "Base.h"


namespace Afferll
{
	class AFRL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}