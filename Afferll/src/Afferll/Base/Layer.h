#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Events/Events.h"


namespace Afferll
{
	class Layer
	{
	public:
		Layer(bool enabled = true, std::string name = "Layer");
		virtual ~Layer();

		bool Enabled();
		void SetEnabled(bool enabled);
		const std::string& GetName();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnEvent(Event& e);

	private:
		bool m_Enabled;
		std::string m_Name;
	};
}