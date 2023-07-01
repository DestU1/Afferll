#include "AfrlPch.h"
#include "Afferll/Base/LayerStack.h"


namespace Afferll
{
	LayerStack::LayerStack()
		: m_Stack(), m_OverlayBegin()
	{
	}
	LayerStack::~LayerStack()
	{
		for (uint64_t i = 0; i < GetCount(); ++i)
		{
			delete m_Stack[i];
			m_Stack.erase(m_Stack.begin() + i);
		}
	}

	Layer* LayerStack::GetLayer(uint64_t i)
	{
		return m_Stack[i];
	}
	uint64_t LayerStack::GetCount()
	{
		return m_Stack.size();
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Stack.emplace(m_Stack.begin() + m_OverlayBegin, layer);
		++m_OverlayBegin;
		layer->OnAttach();
	}
	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Stack.emplace_back(overlay);
		overlay->OnAttach();
	}
	void LayerStack::PopLayer(Layer* layer)
	{
		for (uint64_t i = 0; i < m_OverlayBegin; ++i)
		{
			if (m_Stack[i] == layer)
			{
				m_Stack.erase(m_Stack.begin() + i);
				layer->OnDetach();
				--m_OverlayBegin;
				return;
			}
		}
	}
	void LayerStack::PopOverlay(Layer* overlay)
	{
		for (uint64_t i = m_OverlayBegin; i < GetCount(); ++i)
		{
			if (m_Stack[i] == overlay)
			{
				m_Stack.erase(m_Stack.begin() + i);
				overlay->OnDetach();
				return;
			}
		}
	}
}