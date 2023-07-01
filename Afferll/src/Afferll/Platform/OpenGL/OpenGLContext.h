#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Renderer/Context.h"
#include "Afferll/Base/Application.h"

#pragma comment(lib, "opengl32.lib")
#include "Glad/include/glad/glad.h"


namespace Afferll
{
	class OpenGLContext : public Context
	{
	public:
		OpenGLContext();
		virtual ~OpenGLContext() override;

		virtual void Initialize() override;
		virtual void SwapBuffers() override;
		virtual void Shutdown() override;

		virtual void ClearScreen(float r, float g, float b, float a) override;

	private:
		HGLRC m_Context;
	};
}