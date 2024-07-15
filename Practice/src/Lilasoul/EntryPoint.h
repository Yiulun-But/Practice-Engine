#pragma once
#include "Log.h"

#ifdef LS_PLATFORM_WINDOWS

extern Lilasoul::Application* Lilasoul::CreateApplication();

int main(int argc, char** argv)
{
	Lilasoul::Log::Init();
	LS_CORE_WARN("Initialized Log!");
	int a = 7;
	LS_INFO("Hello! Var={0}", a);

	auto app = Lilasoul::CreateApplication();
	app->Run();
	delete app;
}

#endif 
