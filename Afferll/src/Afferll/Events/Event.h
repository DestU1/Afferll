#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	enum class EventType
	{
		Invalid = -1,
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

		virtual EventType GetType() { return EventType::Invalid; }
		static EventType GetStaticType() { return EventType::Invalid; }
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


	template<>
	inline AFRL_API std::string ToString(EventType _Val)
	{
		switch (_Val)
		{
			case EventType::WindowMove:
				return std::string("Window Move");
			case EventType::WindowFocus:
				return std::string("Window Focus");
			case EventType::WindowFocusLoss:
				return std::string("Window Focus Loss");
			case EventType::WindowResize:
				return std::string("Window Resize");
			case EventType::WindowClose:
				return std::string("Window Close");
			case EventType::KeyPress:
				return std::string("Key Press");
			case EventType::KeyRelease:
				return std::string("Key Release");
			case EventType::KeyRepeat:
				return std::string("Key Repeat");
			case EventType::KeyType:
				return std::string("Key Type");
			case EventType::MousePress:
				return std::string("Mouse Press");
			case EventType::MouseRelease:
				return std::string("Mouse Release");
			case EventType::MouseScroll:
				return std::string("Mouse Scroll");
			case EventType::MouseMove:
				return std::string("Mouse Move");

			default:
				return std::string("Unknown Event Type");
		}
	}
}