#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Base/Window.h"
#include "Afferll/Events/KeyCode.h"
#include "Afferll/Platform/OpenGL/OpenGLContext.h"


namespace Afferll
{
	///////////////////////////////////////////////////////////
	// WindowsWindowManager ///////////////////////////////////
	///////////////////////////////////////////////////////////

	class WindowsWindowManager
	{
	public:
		WindowsWindowManager();
		~WindowsWindowManager();

		static WindowsWindowManager* GetInstance();
		void Shutdown();

		const std::string& GetWindowClassName();
		HINSTANCE GetInstanceHandle();
		uint64_t GetWindowCount();
		Window* GetWindow(HWND windowHandle);

		void ProcessMessages();
		void OnWindowCreate(HWND windowHandle, const Window* window);
		void OnWindowClose(HWND windowHandle);

		bool RegisterWindowClass();
		bool UnRegisterWindowClass();
		static LRESULT WINAPI WindowProcDispacher(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		static KeyCode TranslateKeyCode(WPARAM wParam, LPARAM lParam);

	private:
		static WindowsWindowManager* s_Instance;

		HINSTANCE m_InstanceHandle;
		std::string m_WindowClassName;
		bool m_WindowClassRegistered;
		std::unordered_map<HWND, Window*> m_WindowDictionary;
	};


	///////////////////////////////////////////////////////////
	// WindowsWindow //////////////////////////////////////////
	///////////////////////////////////////////////////////////

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow() override;

		virtual void Initialize() override;
		virtual void OnUpdate() override;
		virtual void Shutdown() override;

		virtual const std::string& GetTitle() override;
		virtual uint64_t GetWidth() override;
		virtual uint64_t GetHeight() override;
		virtual void* GetNativeWindow() override;
		virtual Context* GetContext() override;

		virtual void ProcessMessages() override;
		virtual void SetEventCallback(const EventCallback_t& eventCallback) override;
		virtual void DispachEvent(Event& e) override;

	private:
		WindowProperties m_Properties;
		EventCallback_t m_EventCallback;
		HWND m_WindowHandle;
		Context* m_Context;
	};
}