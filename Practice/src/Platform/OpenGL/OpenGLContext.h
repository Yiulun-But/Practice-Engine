#pragma once
#include "Lilasoul/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Lilasoul {
    class OpenGLContext : public GraphicsContext {
    public:
        OpenGLContext(GLFWwindow* windowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow* m_WindowHandler;
    };
}