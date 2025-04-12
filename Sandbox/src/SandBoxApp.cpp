#include <Lilasoul.h>

class ExampleLayer : public Lilasoul::Layer
{
public:
	ExampleLayer()
		: Layer("Example"),
		  m_Camera(-1.6f, 1.6f, -0.9f, 0.9f),
		  m_CameraPosition(0.0f),
		  m_CameraRotation(0.0f)
	{
		m_VertexArray.reset(Lilasoul::VertexArray::Create());

		float vertices[7 * 3] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f};

		std::shared_ptr<Lilasoul::VertexBuffer> m_VertexBuffer;
		m_VertexBuffer.reset(Lilasoul::VertexBuffer::Create(vertices, sizeof(vertices)));

		Lilasoul::BufferLayout layout = {
			{Lilasoul::ShaderDataType::Float3, "a_Position"},
			{Lilasoul::ShaderDataType::Float4, "a_Color"}};

		m_VertexBuffer->SetLayout(layout);

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		uint32_t indices[3] = {0, 1, 2};
		std::shared_ptr<Lilasoul::IndexBuffer> m_IndexBuffer;
		m_IndexBuffer.reset(Lilasoul::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec4 vColor;

			void main()
			{
				vColor = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec4 vColor;

			void main()
			{
				color = vColor;
			}
		)";

		m_Shader.reset(new Lilasoul::Shader(vertexSrc, fragmentSrc));
	}

	void OnUpdate() override
	{
		if (Lilasoul::Input::IsKeyPressed(LS_KEY_RIGHT))
		{
			m_CameraPosition.x += m_CameraMoveSpeed;
		}
		else if (Lilasoul::Input::IsKeyPressed(LS_KEY_LEFT))
		{
			m_CameraPosition.x -= m_CameraMoveSpeed;
		}
		if (Lilasoul::Input::IsKeyPressed(LS_KEY_UP))
		{
			m_CameraPosition.y += m_CameraMoveSpeed;
		}
		else if (Lilasoul::Input::IsKeyPressed(LS_KEY_DOWN))
		{
			m_CameraPosition.y -= m_CameraMoveSpeed;
		}

		if (Lilasoul::Input::IsKeyPressed(LS_KEY_A))
		{
			m_CameraRotation += m_CameraRotationSpeed;
		}
		else if (Lilasoul::Input::IsKeyPressed(LS_KEY_S))
		{
			m_CameraRotation -= m_CameraRotationSpeed;
		}
		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Lilasoul::RendererCommand::SetClearColor({0.1, 0.1, 0.1, 1});
		Lilasoul::RendererCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);

		Lilasoul::Renderer::BeginScene(m_Camera);

		Lilasoul::Renderer::Submit(m_Shader, m_VertexArray);

		Lilasoul::Renderer::EndScene();
	}

	void OnEvent(Lilasoul::Event &event) override
	{
		// Lilasoul::EventDispatcher dispatcher(event);
		// dispatcher.Dispatch<Lilasoul::KeyPressedEvent>(LS_BIND_EVENT_FN(ExampleLayer::OnKeyPressEvent));
	}

	bool OnKeyPressEvent(Lilasoul::KeyPressedEvent &event)
	{
		if (event.GetKeyCode() == LS_KEY_LEFT)
		{
			m_CameraPosition.x -= m_CameraMoveSpeed;
		}
		else if (event.GetKeyCode() == LS_KEY_RIGHT)
		{
			m_CameraPosition.x += m_CameraMoveSpeed;
		}
		if (event.GetKeyCode() == LS_KEY_UP)
		{
			m_CameraPosition.y += m_CameraMoveSpeed;
		}
		else if (event.GetKeyCode() == LS_KEY_DOWN)
		{
			m_CameraPosition.y -= m_CameraMoveSpeed;
		}
		m_Camera.SetPosition(m_CameraPosition);

		return false;
	}

private:
	std::shared_ptr<Lilasoul::Shader> m_Shader;
	std::shared_ptr<Lilasoul::VertexArray> m_VertexArray;

	Lilasoul::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraRotation = 0.0f;
	float m_CameraMoveSpeed = 0.05f;
	float m_CameraRotationSpeed = 1.0f;
};

class Sandbox : public Lilasoul::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

Lilasoul::Application *Lilasoul::CreateApplication()
{
	return new Sandbox();
}