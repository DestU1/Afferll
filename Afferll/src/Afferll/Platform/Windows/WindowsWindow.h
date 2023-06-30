#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Base/Window.h"
#include "Afferll/Events/KeyCode.h"


namespace Afferll
{
	class WindowsWindowManager
	{
	public:
		WindowsWindowManager();
		~WindowsWindowManager();

		static WindowsWindowManager* GetInstance();
		void Destroy();

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


		HINSTANCE m_InstanceHandle;
		std::string m_WindowClassName;
		bool m_WindowClassRegistered;
		std::unordered_map<HWND, Window*> m_WindowDictionary;

		static WindowsWindowManager* s_Instance;
	};

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		virtual void OnUpdate();
		virtual void Close();

		virtual const std::string& GetTitle();
		virtual uint64_t GetWidth();
		virtual uint64_t GetHeight();
		virtual void* GetNativeWindow();

		virtual void SetEventCallback(const EventCallback_t& eventCallback);
		virtual void DispachEvent(Event& e);

	private:
		void Initialize();


		WindowProperties m_Properties;
		EventCallback_t m_EventCallback;
		HWND m_WindowHandle;
	};
}