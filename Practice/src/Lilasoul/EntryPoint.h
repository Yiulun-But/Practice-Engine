#pragma once

#ifdef LS_PLATFORM_WINDOWS

extern Lilasoul::Application* Lilasoul::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lilasoul::CreateApplication();
	app->Run();
	delete app;
}

#endif 
