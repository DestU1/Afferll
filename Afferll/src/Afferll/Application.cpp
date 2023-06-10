#include "Application.h"
#include "Logger.h"


namespace Afferll
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		// tests
		Logger log = Logger();
		log.Massage("123", 1, 2.0, '3', true, "56");
		log.Massage("321");
		log.Massage("{}");
	}
}