#include <AfrlPch.h>
#include "Application.h"
#include "Logger.h"

#include <thread>


namespace Afferll
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void fn(int i, const Logger& l)
	{
		l.Massage("Hey! {}", i);
		l.Massage("Hey! {}", i);
		l.Debug	 ("Hey! {}", i);
		l.Info	 ("Hey! {}", i);
		l.Success("Hey! {}", i);
		l.Warning("Hey! {}", i);
		l.Error	 ("Hey! {}", i);
		l.Fatal	 ("Hey! {}", i);
	}			 

	void Application::Run()
	{
		// tests
		Logger log = Logger("Logger");

		std::thread threads[100];
		for (int i = 0; i < 100; ++i)
			threads[i] = std::thread(fn, i, log);

		for (int i = 0; i < 100; ++i)
			threads[i].join();

		log.Massage("\x1B[0mint: {}, float: {}, double: {}, bool: {}, char: {}, str: {}, empty: {{}}, random: {{}}}}{{}}{{{{}}", 1, 2.0002f, 3.0003, true, '!', "Hello!");
		log.Debug  ("int: {}, float: {}, double: {}, bool: {}, char: {}, str: {}, empty: {{}}, random: {{}}}}{{}}{{{{}}", 1, 2.0002f, 3.0003, true, '!', "Hello!");
		log.Info   ("int: {}, float: {}, double: {}, bool: {}, char: {}, str: {}, empty: {{}}, random: {{}}}}{{}}{{{{}}", 1, 2.0002f, 3.0003, true, '!', "Hello!");
		log.Success("int: {}, float: {}, double: {}, bool: {}, char: {}, str: {}, empty: {{}}, random: {{}}}}{{}}{{{{}}", 1, 2.0002f, 3.0003, true, '!', "Hello!");
		log.Warning("int: {}, float: {}, double: {}, bool: {}, char: {}, str: {}, empty: {{}}, random: {{}}}}{{}}{{{{}}", 1, 2.0002f, 3.0003, true, '!', "Hello!");
		log.Error  ("int: {}, float: {}, double: {}, bool: {}, char: {}, str: {}, empty: {{}}, random: {{}}}}{{}}{{{{}}", 1, 2.0002f, 3.0003, true, '!', "Hello!");
		log.Fatal  ("int: {}, float: {}, double: {}, bool: {}, char: {}, str: {}, empty: {{}}, random: {{}}}}{{}}{{{{}}", 1, 2.0002f, 3.0003, true, '!', "Hello!");
	}
}