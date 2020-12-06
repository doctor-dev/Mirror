#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Mirror {

	class MIRROR_API Layer
	{
	public:
		//Layer();
		Layer(const std::string& name = "Layer");
		
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
		inline const std::string* GetName() const { return m_DebugName; }
	protected:
		const std::string* m_DebugName;
	};

}