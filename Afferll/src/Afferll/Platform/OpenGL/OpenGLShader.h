#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Renderer/Shader.h"


namespace Afferll
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(std::string vertexSrc, std::string fragmentSrc);
		virtual ~OpenGLShader() override;

		virtual void Bind() override;
		virtual void Unbind() override;

	private:
		uint32_t m_VertexRendererId;
		uint32_t m_FragmentRendererId;
		uint32_t m_ProgramRendererId;
	};
}