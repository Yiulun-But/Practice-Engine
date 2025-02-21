#pragma once
#include "Lilasoul/Log.h"
#include "Lilasoul/Layer.h"
#include "Lilasoul/Events/KeyEvent.h"
#include "Lilasoul/Events/MouseEvent.h"
#include "Lilasoul/Events/ApplicationEvent.h"

namespace Lilasoul
{

    class LILASOUL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

    private:
    private:
        float m_Time = 0.0f;
    };

}