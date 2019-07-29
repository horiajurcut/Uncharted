#pragma once

#include "Core.h"

namespace Uncharted {

	class UNCHARTED_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
