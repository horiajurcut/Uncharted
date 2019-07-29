#pragma once

#ifdef UNCHARTED_PLATFORM_WINDOWS

extern Uncharted::Application* Uncharted::CreateApplication();

int main(int argc, char** argv)
{
	printf("Uncharted Game Engine!\n");
	auto app = Uncharted::CreateApplication();
	app->Run();
	delete app;
}

#endif
