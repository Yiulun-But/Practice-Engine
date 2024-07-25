#pragma once
#include "Log.h"

#ifdef LS_PLATFORM_WINDOWS

extern Lilasoul::Application* Lilasoul::CreateApplication();

int main(int argc, char** argv)
{
	Lilasoul::Log::Init();

	auto app = Lilasoul::CreateApplication();
	app->Run();
	delete app;
}

#endif 
