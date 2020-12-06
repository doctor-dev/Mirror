#include "Mirror.h"


class ExampleLayer : public Mirror::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//MR_CORE_TRACE("ExampleLayer::Update");
	}

	void OnEvent(Mirror::Event& event) override
	{
		std::cout << "eventa";
		//MR_CORE_TRACE("He kay challay");
		//MR_TRACE("{%f}", event);
	}

};


class Interface : public Mirror::Application
{
public:
	
	ExampleLayer* test;
    Interface() 
    {
		PushLayer(new ExampleLayer());
		//MR_TRACE("Example layer jaunde");
    };
    ~Interface() {
		
    };
	
	
};

Mirror::Application* Mirror::CreateApplication() {
    return new Interface();
}