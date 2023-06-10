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

Afferll::Application* Afferll::CreateApplication()
{
	return new TestApp();
}