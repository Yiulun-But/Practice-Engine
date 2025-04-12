#include "lspch.h"
#include "VertexArray.h"

#include "Lilasoul/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Lilasoul {
    VertexArray* VertexArray::Create() {
        switch(Renderer::GetAPI()) 
        {
            case RendererAPI::API::None:      LS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:    return new OpenGLVertexArray();
        }

        LS_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}