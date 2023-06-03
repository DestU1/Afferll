#pragma once


extern Afferll::Application* Afferll::CreateApplication();

#ifdef AFRL_PLATFORM_WINDOWS
	int main(int argc, char** argv)
	{
		Afferll::Application* app = Afferll::CreateApplication();
		app->Run();
		delete app;
	}
#endif