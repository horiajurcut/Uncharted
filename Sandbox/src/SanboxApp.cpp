#include <Uncharted.h>

class Sandbox : public Uncharted::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Uncharted::Application* Uncharted::CreateApplication()
{
	return new Sandbox();
}