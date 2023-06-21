#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Base/Layer.h"


namespace Afferll
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		Layer* GetLayer(uint64_t i);
		uint64_t GetCount();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

	private:
		std::vector<Layer*> m_Stack;
		std::vector<Layer*>::iterator m_OverlayBegin;
	};
}