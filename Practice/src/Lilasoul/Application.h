#pragma once
#include "Core.h"

namespace Lilasoul {

	class LILASOUL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

