#pragma once

#include "Lilasoul/Core.h"
#include "Lilasoul/Events/Event.h"

namespace Lilasoul {

    class LILASOUL_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {};
        virtual void OnDetach() {};
        virtual void OnUpdate() {};
        virtual void OnImGuiRender() {};
        virtual void OnEvent(Event& event) {};

        inline const std::string& GetName() const { return m_DebugName; };
    protected:
        std::string m_DebugName;
    };

}