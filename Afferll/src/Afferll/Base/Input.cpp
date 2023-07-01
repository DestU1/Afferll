#include "AfrlPch.h"
#include "Afferll/Base/Input.h"


namespace Afferll
{
	std::unordered_map<KeyCode, bool> Input::m_KeyStates;
	std::unordered_map<MouseButton, bool> Input::m_MouseStates;
	MousePos Input::m_MousePos;

	bool Input::GetKey(KeyCode key)
	{
		return m_KeyStates[key];
	}
	bool Input::GetMouse(MouseButton button)
	{
		return m_MouseStates[button];
	}
	MousePos Input::GetMousePos()
	{
		return m_MousePos;
	}
	int64_t Input::GetMouseX()
	{
		return m_MousePos.X;
	}
	int64_t Input::GetMouseY()
	{
		return m_MousePos.Y;
	}

	void Input::OnEvent(Event& e)
	{
		EventDispacher dispacher(e);
		dispacher.Dispach<KeyPressEvent>(OnKeyPress);
		dispacher.Dispach<KeyReleaseEvent>(OnKeyRelease);
		dispacher.Dispach<MousePressEvent>(OnMousePress);
		dispacher.Dispach<MouseReleaseEvent>(OnMouseRelease);
		dispacher.Dispach<MouseMoveEvent>(OnMouseMove);
	}
	void Input::OnKeyPress(KeyPressEvent& e)
	{
		m_KeyStates[e.GetKeyCode()] = true;
	}
	void Input::OnKeyRelease(KeyReleaseEvent& e)
	{
		m_KeyStates[e.GetKeyCode()] = false;
	}
	void Input::OnMousePress(MousePressEvent& e)
	{
		m_MouseStates[e.GetMouseButton()] = true;
	}
	void Input::OnMouseRelease(MouseReleaseEvent& e)
	{
		m_MouseStates[e.GetMouseButton()] = false;
	}
	void Input::OnMouseMove(MouseMoveEvent& e)
	{
		m_MousePos.X = e.GetXPos();
		m_MousePos.X = e.GetYPos();
	}
}