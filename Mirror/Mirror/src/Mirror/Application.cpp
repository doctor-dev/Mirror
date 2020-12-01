#include "mrpch.h"
#include "Application.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include <iostream>
namespace Mirror {
	void Application::Run(){
		
		WindowResizeEvent e(1920, 1080);
		std::string test = e.ToString();
		std::cout << test;
		while (true) {
			
		};
	};
	
}