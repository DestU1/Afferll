#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer();

		static VertexBuffer* Create(float* vertices, uint64_t count);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};
}