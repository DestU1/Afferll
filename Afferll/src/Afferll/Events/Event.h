#pragma once
#include "Afferll/Base/Base.h"


namespace Afferll
{
	enum class EventType
	{
		None = 0,
		WindowMove,
		WindowFocus,
		WindowFocusLoss,
		WindowResize,
		WindowClose,
		KeyPress,
		KeyRelease,
		KeyRepeat,
		KeyType,
		MousePress,
		MouseRelease,
		MouseScroll,
		MouseMove
	};
	enum class EventGroup : uint64_t
	{
		None     = 0,
		Window   = BIT(0),
		Keyboard = BIT(1),
		Mouse 	 = BIT(2),
		Input 	 = BIT(3),
		Press 	 = BIT(4),
		Release	 = BIT(5)
	};

	class AFRL_API Event abstract
	{
	public:
		Event();
		virtual ~Event();

		virtual EventType GetType() { return EventType::None; }
		static EventType GetStaticType() { return EventType::None; }
		static EventGroup GetGroups() { return EventGroup::None; }

		bool IsInGroup(EventGroup group);
		bool IsHandled();

		void Resolve();

	protected:
		bool m_Handled;
	};


	class EventDispacher
	{
	public:
		EventDispacher(Event& e);
		~EventDispacher();

		template<class T, typename F>
		bool Dispach(const F& handler);

	private:
		Event& m_Event;
	};

	template<class U, typename F>
	inline bool EventDispacher::Dispach(const F& handler)
	{
		if (m_Event.IsHandled())
			return false;

		if (m_Event.GetType() == U::GetStaticType())
		{
			handler(static_cast<U&>(m_Event));
			return true;
		}

		return false;
	}

}