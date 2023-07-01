#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Events/Events.h"
#include "Afferll/Events/KeyCode.h"


namespace Afferll
{
	struct MousePos
	{
		int64_t X, Y;
	};

	class Input
	{
		friend class Application;

	public:
		static bool GetKey(KeyCode key);
		static bool GetMouse(MouseButton button);
		static MousePos GetMousePos();
		static int64_t GetMouseX();
		static int64_t GetMouseY();

	private:
		static void OnEvent(Event& e);
		static void OnKeyPress(KeyPressEvent& e);
		static void OnKeyRelease(KeyReleaseEvent& e);
		static void OnMousePress(MousePressEvent& e);
		static void OnMouseRelease(MouseReleaseEvent& e);
		static void OnMouseMove(MouseMoveEvent& e);

		static std::unordered_map<KeyCode, bool> m_KeyStates;
		static std::unordered_map<MouseButton, bool> m_MouseStates;
		static MousePos m_MousePos;
	};
}