#include "Application.h"
#include "Lilasoul/Events/ApplicationEvent.h"
#include "Lilasoul/Log.h"

namespace Lilasoul {


	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() 
	{
		WindowResizeEvent e(1200, 720);
		LS_TRACE(e);

		while (true);
	}

}