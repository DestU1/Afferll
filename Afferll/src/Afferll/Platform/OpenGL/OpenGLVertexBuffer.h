#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Renderer/VertexBuffer.h"


namespace Afferll
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint64_t count);
		virtual ~OpenGLVertexBuffer() override;

		virtual void Bind() override;
		virtual void Unbind() override;

	private:
		uint32_t m_RendererId;
	};
}