#include "AfrlPch.h"
#include "Afferll/ImGui/ImGuiLayer.h"
#include "ImGui/ImGui.h"
#include "ImGui/Backend/imgui_impl_opengl3.h"
#include "Afferll/Base/Timer.h"
#include "Afferll/Base/Application.h"
#include "Afferll/Base/Window.h"
#include "Afferll/Events/Events.h"



namespace Afferll
{
	ImGuiLayer::ImGuiLayer()
		: Layer(true, "ImGui"), m_GlContext()
	{
	}
	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		Window* window = Application::GetInstance()->GetWindow();
		io.DisplaySize = ImVec2((float)window->GetWidth(), (float)window->GetHeight());
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;


		io.KeyMap[ImGuiKey_0] = (int)KeyCode::D0;
		io.KeyMap[ImGuiKey_1] = (int)KeyCode::D1;
		io.KeyMap[ImGuiKey_2] = (int)KeyCode::D2;
		io.KeyMap[ImGuiKey_3] = (int)KeyCode::D3;
		io.KeyMap[ImGuiKey_4] = (int)KeyCode::D4;
		io.KeyMap[ImGuiKey_5] = (int)KeyCode::D5;
		io.KeyMap[ImGuiKey_6] = (int)KeyCode::D6;
		io.KeyMap[ImGuiKey_7] = (int)KeyCode::D7;
		io.KeyMap[ImGuiKey_8] = (int)KeyCode::D8;
		io.KeyMap[ImGuiKey_9] = (int)KeyCode::D9;

		io.KeyMap[ImGuiKey_A] = (int)KeyCode::A;
		io.KeyMap[ImGuiKey_B] = (int)KeyCode::B;
		io.KeyMap[ImGuiKey_C] = (int)KeyCode::C;
		io.KeyMap[ImGuiKey_D] = (int)KeyCode::D;
		io.KeyMap[ImGuiKey_E] = (int)KeyCode::E;
		io.KeyMap[ImGuiKey_F] = (int)KeyCode::F;
		io.KeyMap[ImGuiKey_G] = (int)KeyCode::G;
		io.KeyMap[ImGuiKey_H] = (int)KeyCode::H;
		io.KeyMap[ImGuiKey_I] = (int)KeyCode::I;
		io.KeyMap[ImGuiKey_J] = (int)KeyCode::J;
		io.KeyMap[ImGuiKey_K] = (int)KeyCode::K;
		io.KeyMap[ImGuiKey_L] = (int)KeyCode::L;
		io.KeyMap[ImGuiKey_M] = (int)KeyCode::M;
		io.KeyMap[ImGuiKey_N] = (int)KeyCode::N;
		io.KeyMap[ImGuiKey_O] = (int)KeyCode::O;
		io.KeyMap[ImGuiKey_P] = (int)KeyCode::P;
		io.KeyMap[ImGuiKey_Q] = (int)KeyCode::Q;
		io.KeyMap[ImGuiKey_R] = (int)KeyCode::R;
		io.KeyMap[ImGuiKey_S] = (int)KeyCode::S;
		io.KeyMap[ImGuiKey_T] = (int)KeyCode::T;
		io.KeyMap[ImGuiKey_U] = (int)KeyCode::U;
		io.KeyMap[ImGuiKey_V] = (int)KeyCode::V;
		io.KeyMap[ImGuiKey_W] = (int)KeyCode::W;
		io.KeyMap[ImGuiKey_X] = (int)KeyCode::X;
		io.KeyMap[ImGuiKey_Y] = (int)KeyCode::Y;
		io.KeyMap[ImGuiKey_Z] = (int)KeyCode::Z;

		io.KeyMap[ImGuiKey_F1]  = (int)KeyCode::F1;
		io.KeyMap[ImGuiKey_F2]  = (int)KeyCode::F2;
		io.KeyMap[ImGuiKey_F3]  = (int)KeyCode::F3;
		io.KeyMap[ImGuiKey_F4]  = (int)KeyCode::F4;
		io.KeyMap[ImGuiKey_F5]  = (int)KeyCode::F5;
		io.KeyMap[ImGuiKey_F6]  = (int)KeyCode::F6;
		io.KeyMap[ImGuiKey_F7]  = (int)KeyCode::F7;
		io.KeyMap[ImGuiKey_F8]  = (int)KeyCode::F8;
		io.KeyMap[ImGuiKey_F9]  = (int)KeyCode::F9;
		io.KeyMap[ImGuiKey_F10] = (int)KeyCode::F10;
		io.KeyMap[ImGuiKey_F11] = (int)KeyCode::F11;
		io.KeyMap[ImGuiKey_F12] = (int)KeyCode::F12;

		io.KeyMap[ImGuiKey_UpArrow]    = (int)KeyCode::UpArrow;
		io.KeyMap[ImGuiKey_DownArrow]  = (int)KeyCode::DownArrow;
		io.KeyMap[ImGuiKey_LeftArrow]  = (int)KeyCode::LeftArrow;
		io.KeyMap[ImGuiKey_RightArrow] = (int)KeyCode::RightArrow;

		io.KeyMap[ImGuiKey_KeypadMultiply] = (int)KeyCode::NumPadMultiply;
		io.KeyMap[ImGuiKey_KeypadAdd]      = (int)KeyCode::NumPadAdd;
		io.KeyMap[ImGuiKey_KeypadSubtract] = (int)KeyCode::NumPadSubtract;
		io.KeyMap[ImGuiKey_KeypadDecimal]  = (int)KeyCode::NumPadDecimal;
		io.KeyMap[ImGuiKey_KeypadDivide]   = (int)KeyCode::NumPadDivide;
		io.KeyMap[ImGuiKey_KeypadEnter]    = (int)KeyCode::NumPadEnter;
		io.KeyMap[ImGuiKey_NumLock]        = (int)KeyCode::NumLock;
		io.KeyMap[ImGuiKey_Keypad0]        = (int)KeyCode::NumPad0;
		io.KeyMap[ImGuiKey_Keypad1]        = (int)KeyCode::NumPad1;
		io.KeyMap[ImGuiKey_Keypad2]        = (int)KeyCode::NumPad2;
		io.KeyMap[ImGuiKey_Keypad3]        = (int)KeyCode::NumPad3;
		io.KeyMap[ImGuiKey_Keypad4]        = (int)KeyCode::NumPad4;
		io.KeyMap[ImGuiKey_Keypad5]        = (int)KeyCode::NumPad5;
		io.KeyMap[ImGuiKey_Keypad6]        = (int)KeyCode::NumPad6;
		io.KeyMap[ImGuiKey_Keypad7]        = (int)KeyCode::NumPad7;
		io.KeyMap[ImGuiKey_Keypad8]        = (int)KeyCode::NumPad8;
		io.KeyMap[ImGuiKey_Keypad9]        = (int)KeyCode::NumPad9;

		io.KeyMap[ImGuiKey_GraveAccent]  = (int)KeyCode::GraveAccent;
		io.KeyMap[ImGuiKey_Minus]        = (int)KeyCode::Minus;
		io.KeyMap[ImGuiKey_Equal]        = (int)KeyCode::Equal;
		io.KeyMap[ImGuiKey_LeftBracket]  = (int)KeyCode::LeftBracket;
		io.KeyMap[ImGuiKey_RightBracket] = (int)KeyCode::RightBracket;
		io.KeyMap[ImGuiKey_Backslash]    = (int)KeyCode::Backslash;
		io.KeyMap[ImGuiKey_Semicolon]    = (int)KeyCode::Semicolon;
		io.KeyMap[ImGuiKey_Apostrophe]   = (int)KeyCode::Apostrophe;
		io.KeyMap[ImGuiKey_Comma]        = (int)KeyCode::Comma;
		io.KeyMap[ImGuiKey_Period]       = (int)KeyCode::Period;
		io.KeyMap[ImGuiKey_Slash]        = (int)KeyCode::Slash;

		io.KeyMap[ImGuiKey_Escape]       = (int)KeyCode::Escape;
		io.KeyMap[ImGuiKey_Backspace]    = (int)KeyCode::Backspace;
		io.KeyMap[ImGuiKey_Enter]        = (int)KeyCode::Enter;
		io.KeyMap[ImGuiKey_RightShift]   = (int)KeyCode::RightShift;
		io.KeyMap[ImGuiKey_RightCtrl]    = (int)KeyCode::RightControl;
		io.KeyMap[ImGuiKey_Menu]         = (int)KeyCode::Menu;
		io.KeyMap[ImGuiKey_RightSuper]   = (int)KeyCode::RightSuper;
		io.KeyMap[ImGuiKey_RightAlt]     = (int)KeyCode::RightAlt;
		io.KeyMap[ImGuiKey_Space]        = (int)KeyCode::Space;
		io.KeyMap[ImGuiKey_LeftAlt]      = (int)KeyCode::LeftAlt;
		io.KeyMap[ImGuiKey_LeftSuper]    = (int)KeyCode::LeftSuper;
		io.KeyMap[ImGuiKey_LeftCtrl]     = (int)KeyCode::LeftControl;
		io.KeyMap[ImGuiKey_LeftShift]    = (int)KeyCode::LeftShift;
		io.KeyMap[ImGuiKey_CapsLock]     = (int)KeyCode::CapsLock;
		io.KeyMap[ImGuiKey_Tab]          = (int)KeyCode::Tab;

		io.KeyMap[ImGuiKey_PrintScreen]  = (int)KeyCode::PrintScreen;
		io.KeyMap[ImGuiKey_ScrollLock]   = (int)KeyCode::ScrollLock;
		io.KeyMap[ImGuiKey_Pause]        = (int)KeyCode::Pause;
		io.KeyMap[ImGuiKey_Insert]       = (int)KeyCode::Insert;
		io.KeyMap[ImGuiKey_Home]         = (int)KeyCode::Home;
		io.KeyMap[ImGuiKey_PageUp]       = (int)KeyCode::PageUp;
		io.KeyMap[ImGuiKey_Delete]       = (int)KeyCode::Delete;
		io.KeyMap[ImGuiKey_End]          = (int)KeyCode::End;
		io.KeyMap[ImGuiKey_PageDown]     = (int)KeyCode::PageDown;


		ImGui_ImplOpenGL3_Init("#version 410");
	}
	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}
	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();

		static Timer t;
		static float time;
		float newTime = t.Elapsed();
		float dt = newTime - time;
		time = newTime;
		io.DeltaTime = dt;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	void ImGuiLayer::OnEvent(Event& e)
	{
		EventDispacher dispacher(e);
		dispacher.Dispach<KeyPressEvent>(AFRL_MEMBER_CALLBACK(OnKeyPress));
		dispacher.Dispach<KeyReleaseEvent>(AFRL_MEMBER_CALLBACK(OnKeyRelease));
		dispacher.Dispach<KeyTypeEvent>(AFRL_MEMBER_CALLBACK(OnKeyType));
		dispacher.Dispach<MousePressEvent>(AFRL_MEMBER_CALLBACK(OnMousePress));
		dispacher.Dispach<MouseReleaseEvent>(AFRL_MEMBER_CALLBACK(OnMouseRelease));
		dispacher.Dispach<MouseMoveEvent>(AFRL_MEMBER_CALLBACK(OnMouseMove));
		dispacher.Dispach<MouseScrollEvent>(AFRL_MEMBER_CALLBACK(OnMouseScroll));
		dispacher.Dispach<WindowResizeEvent>(AFRL_MEMBER_CALLBACK(OnWindowResize));
	}

	void ImGuiLayer::OnKeyPress(KeyPressEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[(uint64_t)e.GetKeyCode()] = true;
	}
	void ImGuiLayer::OnKeyRelease(KeyReleaseEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[(uint64_t)e.GetKeyCode()] = false;
	}
	void ImGuiLayer::OnKeyType(KeyTypeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.AddInputCharacter(e.GetChar());
	}
	void ImGuiLayer::OnMousePress(MousePressEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[(uint64_t)e.GetMouseButton()] = true;
	}
	void ImGuiLayer::OnMouseRelease(MouseReleaseEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[(uint64_t)e.GetMouseButton()] = false;
	}
	void ImGuiLayer::OnMouseMove(MouseMoveEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2((float)e.GetXPos(), (float)e.GetYPos());
	}
	void ImGuiLayer::OnMouseScroll(MouseScrollEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel = e.GetYOffset() / 120.f;
		io.MouseWheelH = e.GetXOffset() / 120.f;
	}
	void ImGuiLayer::OnWindowResize(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)e.GetWidth(), (float)e.GetHeight());
	}
}