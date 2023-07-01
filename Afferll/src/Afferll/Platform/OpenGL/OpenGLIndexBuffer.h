#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Renderer/IndexBuffer.h"


namespace Afferll
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer() override;

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual uint32_t GetCount() override;

	private:
		uint32_t m_RendererId;
		uint32_t m_Count;
	};
}