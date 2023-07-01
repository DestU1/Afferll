#pragma once
#include "Afferll/Base/Layer.h"
#include "Afferll/Events/Events.h"


namespace Afferll
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& e) override;

	private:
		void OnKeyPress(KeyPressEvent& e);
		void OnKeyRelease(KeyReleaseEvent& e);
		void OnKeyType(KeyTypeEvent& e);
		void OnMousePress(MousePressEvent& e);
		void OnMouseRelease(MouseReleaseEvent& e);
		void OnMouseMove(MouseMoveEvent& e);
		void OnMouseScroll(MouseScrollEvent& e);
		void OnWindowResize(WindowResizeEvent& e);

		void* m_GlContext;
	};
}