#include "AfrlPch.h"
#include "Afferll/Renderer/IndexBuffer.h"
#include "Afferll/Renderer/Renderer.h"


#ifdef AFRL_PLATFORM_WINDOWS
#include "Afferll/Platform/OpenGL/OpenGLIndexBuffer.h"
#endif

namespace Afferll
{
	IndexBuffer::~IndexBuffer()
	{
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::Invalid:
			AFRL_ASSERT(false, "Invalid rendering API!");
			return nullptr;

#ifdef AFRL_PLATFORM_WINDOWS
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
#endif
		}

		AFRL_ASSERT(false, "Unknown rendering API!");
		return nullptr;
	}
}