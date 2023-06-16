#include "AfrlPch.h"
#include "Afferll/Base/Application.h"
#include "Afferll/Base/Logger.h"
#include "Afferll/Events/Events.h"

#include <thread>


namespace Afferll
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void fn(MousePressEvent& e)
	{
		Logger l("log");
		l.Success("successful dispach");
	}	

	void Application::Run()
	{
		// tests
		MousePressEvent e(MouseButton::Left); 
		EventDispacher dispacher(e);
		dispacher.Dispach<MouseReleaseEvent>(fn);
		dispacher.Dispach<MouseMoveEvent>(fn);
		dispacher.Dispach<MousePressEvent>(fn);
	}
}