#include "AfrlPch.h"
#include "Afferll/Renderer/VertexBuffer.h"
#include "Afferll/Renderer/Renderer.h"


#ifdef AFRL_PLATFORM_WINDOWS
	#include "Afferll/Platform/OpenGL/OpenGLVertexBuffer.h"
#endif

namespace Afferll
{
	VertexBuffer::~VertexBuffer()
	{
	}

	VertexBuffer* VertexBuffer::Create(float* vertices, uint64_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::Invalid:
				AFRL_ASSERT(false, "Invalid rendering API!");
				return nullptr;

#ifdef AFRL_PLATFORM_WINDOWS
			case RendererAPI::OpenGL:
				return new OpenGLVertexBuffer(vertices, count);
#endif
		}

		AFRL_ASSERT(false, "Unknown rendering API!");
		return nullptr;
	}
}