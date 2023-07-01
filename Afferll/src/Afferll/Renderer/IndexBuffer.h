#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer();

		static IndexBuffer* Create(uint32_t* indices, uint32_t count);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual uint32_t GetCount() = 0;
	};
}