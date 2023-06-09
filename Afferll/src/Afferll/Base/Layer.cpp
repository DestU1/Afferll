#include "AfrlPch.h"
#include "Afferll/Base/Layer.h"


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
}