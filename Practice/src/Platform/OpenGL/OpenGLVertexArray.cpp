#include "lspch.h"
#include "OpenGLVertexArray.h"
#include "glad/glad.h"

namespace Lilasoul {

    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
		switch (type)
		{
            case Lilasoul::ShaderDataType::None:	return GL_NONE;
            case Lilasoul::ShaderDataType::Float:	return GL_FLOAT;
            case Lilasoul::ShaderDataType::Float2:	return GL_FLOAT;
            case Lilasoul::ShaderDataType::Float3:	return GL_FLOAT;
            case Lilasoul::ShaderDataType::Float4:	return GL_FLOAT;
            case Lilasoul::ShaderDataType::Mat3:	return GL_FLOAT;
            case Lilasoul::ShaderDataType::Mat4:	return GL_FLOAT;
            case Lilasoul::ShaderDataType::Int:		return GL_INT;
            case Lilasoul::ShaderDataType::Int2:	return GL_INT;
            case Lilasoul::ShaderDataType::Int3:	return GL_INT;
            case Lilasoul::ShaderDataType::Int4:	return GL_INT;
            case Lilasoul::ShaderDataType::Bool:	return GL_BOOL;
            default:
                break;
		}
		LS_CORE_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
	}

    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &m_RendererID);

    }
    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }
    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer)
    {
        LS_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout!");
        glBindVertexArray(m_RendererID);
        vertexBuffer->Bind();


        uint32_t index = 0;
		const auto& elements = vertexBuffer->GetLayout();
		for (const auto& element : elements)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type), 
				element.Normalized? GL_TRUE : GL_FALSE, 
				elements.GetStride(), 
				(const void*)element.Offset);
			index++;
		}
        m_VertexBuffers.push_back(vertexBuffer);

    }
    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
    {
        glBindVertexArray(m_RendererID);
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
    }

}