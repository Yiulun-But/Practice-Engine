#include "lspch.h"
#include "Renderer.h"
#include "Lilasoul/Log.h"

// #define GLM_ENABLE_EXPERIMENTAL
// #include <glm/gtx/string_cast.hpp>


namespace Lilasoul {

    Renderer::SceneData* Renderer::s_SceneData = new Renderer::SceneData();

    void Renderer::BeginScene(OrthographicCamera& camera)
    {
        s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
    }
    void Renderer::EndScene()
    {
    }
    void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray> &vertexArray)
    {
        shader->Bind();
        shader->SetUniformMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
        // LS_CORE_INFO("View Projection Matrix: {0}", glm::to_string(s_SceneData->ViewProjectionMatrix));
        vertexArray->Bind();
        RendererCommand::DrawIndexed(vertexArray);
    }
}