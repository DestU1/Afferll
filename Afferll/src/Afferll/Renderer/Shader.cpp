#include "AfrlPch.h"
#include "Afferll/Renderer/Shader.h"
#include "Afferll/Renderer/Renderer.h"


#ifdef AFRL_PLATFORM_WINDOWS
#include "Afferll/Platform/OpenGL/OpenGLShader.h"
#endif

namespace Afferll
{
	Shader::~Shader()
	{
	}

	Shader* Shader::Create(std::string vertexSrc, std::string fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::Invalid:
			AFRL_ASSERT(false, "Invalid rendering API!");
			return nullptr;

#ifdef AFRL_PLATFORM_WINDOWS
		case RendererAPI::OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
#endif
		}

		AFRL_ASSERT(false, "Unknown rendering API!");
		return nullptr;
	}
}