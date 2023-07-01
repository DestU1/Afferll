#pragma once


#ifdef AFRL_PLATFORM_WINDOWS
	int main(int argc, char** argv)
	{
		Afferll::Application* app = Afferll::Application::Create();
		app->Run();
		delete app;
	}
#else 
	#error "Unsupported platform!"
#endif