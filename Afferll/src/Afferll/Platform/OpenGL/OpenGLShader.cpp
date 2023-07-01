#include "AfrlPch.h"
#include "Afferll/Platform/OpenGL/OpenGLShader.h"
#include "Glad/include/glad/glad.h"


namespace Afferll
{
	OpenGLShader::OpenGLShader(std::string vertexSrc, std::string fragmentSrc)
	{
		m_VertexRendererId = glCreateShader(GL_VERTEX_SHADER);
		const char* src = vertexSrc.c_str();
		glShaderSource(m_VertexRendererId, 1, &src, 0);
		glCompileShader(m_VertexRendererId);

		int32_t compiled = 0;
		glGetShaderiv(m_VertexRendererId, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			int32_t maxLength = 0;
			glGetShaderiv(m_VertexRendererId, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(m_VertexRendererId, maxLength, &maxLength, infoLog.data());

			glDeleteShader(m_VertexRendererId);
			AFRL_ASSERT(false, "Unsuccessful vertex shader compilation:\n\n{}", (char*)infoLog.data());
			return;
		}


		m_FragmentRendererId = glCreateShader(GL_FRAGMENT_SHADER);
		src = fragmentSrc.c_str();
		glShaderSource(m_FragmentRendererId, 1, &src, 0);
		glCompileShader(m_FragmentRendererId);

		compiled = 0;
		glGetShaderiv(m_FragmentRendererId, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			int32_t maxLength = 0;
			glGetShaderiv(m_FragmentRendererId, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(m_FragmentRendererId, maxLength, &maxLength, infoLog.data());

			glDeleteShader(m_VertexRendererId);
			glDeleteShader(m_FragmentRendererId);
			AFRL_ASSERT(false, "Unsuccessful fragment shader compilation:\n\n{}", (char*)infoLog.data());
			return;
		}


		m_ProgramRendererId = glCreateProgram();
		glAttachShader(m_ProgramRendererId, m_VertexRendererId);
		glAttachShader(m_ProgramRendererId, m_FragmentRendererId);
		glLinkProgram(m_ProgramRendererId);

		int32_t linked = 0;
		glGetProgramiv(m_ProgramRendererId, GL_LINK_STATUS, &linked);
		if (linked == GL_FALSE)
		{
			int32_t maxLength = 0;
			glGetProgramiv(m_ProgramRendererId, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<char> infoLog(maxLength);
			glGetProgramInfoLog(m_ProgramRendererId, maxLength, &maxLength, infoLog.data());

			glDeleteProgram(m_ProgramRendererId);
			glDeleteShader(m_VertexRendererId);
			glDeleteShader(m_FragmentRendererId);
			AFRL_ASSERT(false, "Unsuccessful shader linkage:\n\n{}", (char*)infoLog.data());
			return;
		}

		glDetachShader(m_ProgramRendererId, m_VertexRendererId);
		glDetachShader(m_ProgramRendererId, m_FragmentRendererId);
	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_ProgramRendererId);
		glDeleteShader(m_VertexRendererId);
		glDeleteShader(m_FragmentRendererId);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(m_ProgramRendererId);
	}
	void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}
}