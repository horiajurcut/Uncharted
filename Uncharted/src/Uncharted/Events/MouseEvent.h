#pragma once

#include "Event.h"

#include <sstream>

namespace Uncharted
{

	class UNCHARTED_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const
		{
			return m_MouseX;
		}

		inline float GetY() const
		{
			return m_MouseY;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX;
		float m_MouseY;
	};

	class UNCHARTED_API MouseScrolledEvent : public Event
	{

	};

	class UNCHARTED_API MouseButtonEvent : public Event
	{

	};

	class UNCHARTED_API MousePressedButtonEvent : public MouseButtonEvent
	{

	};

	class UNCHARTED_API MouseReleasedButtonEvent : public MouseButtonEvent
	{

	};
}
