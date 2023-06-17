#include "AfrlPch.h"
#include "Afferll/Base/Window.h"


#ifdef AFRL_PLATFORM_WINDOWS
	#include "Afferll/Platform/Windows/WindowsWindow.h"
#endif

namespace Afferll
{
	WindowProperties::WindowProperties(const std::string& title, uint64_t width, uint64_t height)
		: m_Title(title), m_Width(width), m_Height(height)
	{
	}
	WindowProperties::~WindowProperties()
	{
	}


	Window::~Window()
	{
	}

	Window* Window::Create(const WindowProperties& properties)
	{
		AFRL_LOG(Info, "Creating a window, title: \"{}\", width: {}, height: {}.", properties.m_Title, properties.m_Width, properties.m_Height);

#ifdef AFRL_PLATFORM_WINDOWS
		return new WindowsWindow(properties);
#else
		AFRL_ASSERT(false, "Wtf");
		return nullptr;
#endif
	}
}