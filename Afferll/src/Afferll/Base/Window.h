#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Events/Events.h"


namespace Afferll
{
	class AFRL_API WindowProperties
	{
	public:
		WindowProperties(const std::string& title = "Afferll Engine", uint64_t width = 1600, uint64_t height = 900);
		~WindowProperties();

		std::string m_Title;
		uint64_t m_Width;
		uint64_t m_Height;
	};

	class AFRL_API Window
	{
	public:
		using EventCallback_t = std::function<void(Event&)>;

		virtual ~Window();

		virtual void OnUpdate() = 0;
		virtual void Close() = 0;

		virtual const std::string& GetTitle() = 0;
		virtual uint64_t GetWidth() = 0;
		virtual uint64_t GetHeight() = 0;
		virtual void* GetNativeWindow() = 0;

		virtual void SetEventCallback(const EventCallback_t& eventCallback) = 0;
		virtual void DispachEvent(Event& e) = 0;

		static Window* Create(const WindowProperties& properties = WindowProperties());
	};
}