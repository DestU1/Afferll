#include "AfrlPch.h"
#include "Afferll/Platform/OpenGL/OpenGLContext.h"


namespace Afferll
{
	OpenGLContext::OpenGLContext()
		: m_Context()
	{
	}
	OpenGLContext::~OpenGLContext()
	{
		Shutdown();
	}

	void OpenGLContext::Initialize()
	{
		Window* window = Application::GetInstance()->GetWindow();

#ifdef AFRL_PLATFORM_WINDOWS
		PIXELFORMATDESCRIPTOR pfd = { };
		pfd.nSize = sizeof(pfd);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 32;

		HWND hWNd = (HWND)window->GetNativeWindow();
		HDC hDc = GetDC(hWNd);
		AFRL_ASSERT(hDc, "On OpenGLContext::Init(), GetDC() failed.");

		int pf = ChoosePixelFormat(hDc, &pfd);
		SetPixelFormat(hDc, pf, &pfd);

		m_Context = wglCreateContext(hDc);
		AFRL_ASSERT(m_Context, "On OpenGLContext::Init(), wglCreateContext() failed.");
		wglMakeCurrent(hDc, m_Context);

		ReleaseDC(hWNd, hDc);
#else 
	#error "Unsupported platform!"
#endif
	}
	void OpenGLContext::SwapBuffers()
	{
		Window* window = Application::GetInstance()->GetWindow();
		HWND hWnd = (HWND)window->GetNativeWindow();
		HDC hDc = GetDC(hWnd);
		::SwapBuffers(hDc);
		ReleaseDC(hWnd, hDc);
	}
	void OpenGLContext::Shutdown()
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_Context);
	}

	void OpenGLContext::ClearScreen(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}