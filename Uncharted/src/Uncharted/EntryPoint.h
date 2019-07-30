#pragma once

#ifdef UNCHARTED_PLATFORM_WINDOWS

extern Uncharted::Application* Uncharted::CreateApplication();

int main(int argc, char** argv)
{
	Uncharted::Log::Init();
	
	UNCHARTED_CORE_WARN("Initialized Logger");
	int a = 4;
	UNCHARTED_INFO("Hello world! Var = {0}", a);

	auto app = Uncharted::CreateApplication();
	app->Run();
	delete app;
}

#endif
