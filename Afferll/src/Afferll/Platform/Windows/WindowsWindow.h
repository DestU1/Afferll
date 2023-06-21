#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Base/Window.h"


namespace Afferll
{
	// TODO: use unorderd maps
	class WindowsWindowManager
	{
	private:
		class WindowDictionary
		{
		public:
			WindowDictionary(HWND windowHandle, Window* associatedWindow);

			HWND m_WindowHandle;
			Window* m_AssociatedWindow;
		};

	public:
		WindowsWindowManager();
		~WindowsWindowManager();

		static WindowsWindowManager* GetInstance();
		void Destroy();

		uint64_t GetWindowCount();
		Window* GetWindow(HWND windowHandle);
		HWND GetWindowHandle(Window* window);
		const std::string& GetWindowClassName();
		HINSTANCE GetInstanceHandle();

		void ProcessMessages();
		void OnWindowCreate(HWND windowHandle, Window* window);
		void OnWindowClose(HWND windowHandle);
		void OnWindowClose(Window* window);
		void OnQuitMessage();

		bool RegisterWindowClass();
		bool UnRegisterWindowClass();
		static LRESULT WINAPI WindowProcDispacher(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		static KeyCode GetKeyCodeByVk(WPARAM wParam, LPARAM lParam);


		static WindowsWindowManager* s_Instance;
		HINSTANCE m_InstanceHandle;
		std::string m_WindowClassName;
		bool m_WindowClassRegistered;
		std::vector<WindowDictionary> m_WindowDictionary;
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

		virtual void SetEventCallback(const EventCallback_t& eventCallback);
		virtual void DispachEvent(Event& e);

	private:
		void Initialize();


		WindowProperties m_Properties;
		EventCallback_t m_EventCallback;
		HWND m_WindowHandle;
	};
}