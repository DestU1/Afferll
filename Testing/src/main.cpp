#include <Afferll.h>


class TestApp : public Afferll::Application
{
public:
	TestApp()
	{
	}
	~TestApp()
	{
	}
};

Afferll::Application* Afferll::Application::Create()
{
	return new TestApp();
}