#pragma once

#include "Event.h"

#include <sstream>

namespace Uncharted
{

	class UNCHARTED_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const
		{
			return m_Width;
		}

		inline unsigned int Getheight() const
		{
			return m_Height;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width;
		unsigned int m_Height;
	};

	class UNCHARTED_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	class UNCHARTED_API AppTickEvent : public Event
	{
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class UNCHARTED_API AppUpdateEvent : public Event
	{
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class UNCHARTED_API AppRenderEvent : public Event
	{
		AppRenderEvent() {}
		
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}
