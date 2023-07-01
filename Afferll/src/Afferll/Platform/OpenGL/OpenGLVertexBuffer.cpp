#include "AfrlPch.h"
#include "Afferll/Platform/OpenGL/OpenGLVertexBuffer.h"
#include "Glad/include/glad/glad.h"


namespace Afferll
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint64_t count)
	{
		glCreateBuffers(1, &m_RendererId);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), vertices, GL_STATIC_DRAW);
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererId);
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
	}
	void OpenGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}