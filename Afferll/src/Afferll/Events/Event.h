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

	class Event abstract
	{
	public:
		Event();
		virtual ~Event();

		static constexpr EventType GetType();
		static constexpr EventGroup GetGroups();

		bool IsInGroup(EventGroup group);
		bool IsHandled();

		void Resolve();

	protected:
		bool m_Handled;
	};


	template <class T>
	class EventDispacher
	{
	public:
		EventDispacher(T& e);
		~EventDispacher();

		template<class T, typename F>
		bool Dispach(const F& handler);

	private:
		Event& m_Event;
	};

	template<class T>
	inline EventDispacher<T>::EventDispacher(T& e)
		: m_Event(e)
	{
	}
	template<class T>
	inline EventDispacher<T>::~EventDispacher()
	{
	}

	template<class T>
	template<class U, typename F>
	inline bool EventDispacher<T>::Dispach(const F& handler)
	{
		if (m_Event.IsHandled())
			return false;

		if constexpr (T::GetType() == U::GetType())
			handler(static_cast<U&>(m_Event));
		if constexpr (T::GetType() == U::GetType())
			return true;

		return false;
	}

}