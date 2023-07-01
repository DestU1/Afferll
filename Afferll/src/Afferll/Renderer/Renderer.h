#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	enum class RendererAPI
	{
		Invalid = -1,
		OpenGL
	};

	class Renderer
	{
	public:
		static RendererAPI GetAPI();

	private:
		static RendererAPI s_RendererAPI;
	};
}