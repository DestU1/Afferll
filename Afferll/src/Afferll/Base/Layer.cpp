#include "AfrlPch.h"
#include "Layer.h"


namespace Afferll
{
	Layer::Layer(bool enabled, std::string name)
		: m_Enabled(enabled), m_Name(name)
	{
	}
	Layer::~Layer()
	{
	}

	bool Layer::Enabled()
	{
		return m_Enabled;
	}
	void Layer::SetEnabled(bool enabled)
	{
		m_Enabled = enabled;
	}
	const std::string& Layer::GetName()
	{
		return m_Name;
	}

	void Layer::OnAttach()
	{
	}
	void Layer::OnDetach()
	{
	}
	void Layer::OnUpdate()
	{
	}
	void Layer::OnEvent(Event& e)
	{
	}
}