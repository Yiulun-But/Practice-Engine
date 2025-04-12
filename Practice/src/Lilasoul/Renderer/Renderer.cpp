#include "lspch.h"
#include "Renderer.h"

namespace Lilasoul {
    void Renderer::BeginScene()
    {
    }
    void Renderer::EndScene()
    {
    }
    void Renderer::Submit(const std::shared_ptr<VertexArray> &vertexArray)
    {
        vertexArray->Bind();
        RendererCommand::DrawIndexed(vertexArray);
    }
}