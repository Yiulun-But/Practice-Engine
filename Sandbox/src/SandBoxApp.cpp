#include <Lilasoul.h>

class ExampleLayer : public Lilasoul::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		LS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Lilasoul::Event& event) override
	{
		LS_TRACE(event.ToString());
	}
};


class Sandbox : public Lilasoul::Application 
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Lilasoul::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Lilasoul::Application* Lilasoul::CreateApplication()
{
	return new Sandbox();
}