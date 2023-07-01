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

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent(Event& e) = 0;

	private:
		bool m_Enabled;
		std::string m_Name;
	};
}