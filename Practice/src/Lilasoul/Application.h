#pragma once
#include "Core.h"

#include "Events/Event.h"
#include "lspch.h"
#include "Window.h"
#include "Lilasoul/Events/ApplicationEvent.h"
#include "Lilasoul/LayerStack.h"

#include "Lilasoul/ImGui/ImGuiLayer.h"

#include "Lilasoul/Renderer/Shader.h"
#include "Lilasoul/Renderer/Buffer.h"
#include "Lilasoul/Renderer/VertexArray.h"

namespace Lilasoul {

	class LILASOUL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; };
		inline Window& GetWindow() { return *m_Window; };

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;


		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::shared_ptr<VertexArray> m_VertexArray;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

