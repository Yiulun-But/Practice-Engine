#include "lspch.h"
#include "Buffer.h"
#include "Lilasoul/Log.h"

#include "Lilasoul/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Lilasoul {
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch(Renderer::GetAPI()) 
        {
            case RendererAPI::None:      LS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::OpenGL:    return new OpenGLVertexBuffer(vertices, size);
        }

        LS_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch(Renderer::GetAPI()) 
        {
            case RendererAPI::None:      LS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::OpenGL:    return new OpenGLIndexBuffer(indices, size);
        }

        LS_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}