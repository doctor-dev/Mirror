#pragma once
#include "Mirror/Core.h"
#include <string>
#include <functional>

namespace Mirror {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WIndowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed,KeyReleased,
		MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse  =BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}\
	                           virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override {return ##type;}


}