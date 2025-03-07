#include "lspch.h"
#include "Lilasoul/Log.h"
#include "OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Lilasoul {
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandler(windowHandle)
    {
        LS_CORE_ASSERT(m_WindowHandler, "Window handle is null!");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandler);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        LS_CORE_ASSERT(status, "Failed to initialized glad!");

        LS_CORE_INFO("  Vender:   {0}", (char*)glGetString(GL_VENDOR));
        LS_CORE_INFO("  Renderer: {0}", (char*)glGetString(GL_RENDERER));
        LS_CORE_INFO("  Version:  {0}", (char*)glGetString(GL_VERSION));
    }
    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandler);
    }
}