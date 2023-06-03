#include <stdio.h>
#include <Afferll.h>


class TestApp : public Afferll::Application
{
public:
	TestApp()
	{
		printf("Hello World!\n");
	}
	~TestApp()
	{
	}
};

Afferll::Application* Afferll::CreateApplication()
{
	return new TestApp();
}