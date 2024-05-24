#include <Lilasoul.h>

class Sandbox : public Lilasoul::Application 
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Lilasoul::Application* Lilasoul::CreateApplication()
{
	return new Sandbox();
}