#pragma once

#include "Lilasoul/Layer.h"

namespace Lilasoul {

    class LILASOUL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& e);
    private:
        float m_Time = 0.0f;

    };

}