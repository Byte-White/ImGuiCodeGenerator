#include "Viewport.h"

WidgetType GetTypeByName(std::string name)
{
    if(name == "Text") return WidgetType::Text;
    else if(name == "Button") return WidgetType::Button;
    else if(name == "Image") return WidgetType::Image;
    else if(name == "DragFloat") return WidgetType::DragFloat;
    else if(name == "DragInt") return WidgetType::DragInt;
    else if(name == "ColorEdit") return WidgetType::ColorEdit4;
    else if(name == "ColorPicker") return WidgetType::ColorPicker4;
}

Viewport::Viewport()
{
    
}

void Viewport::Render()
{
    for(auto& widget : m_WidgetList)
    {
        if(widget.type == WidgetType::Text)
        {
            ImGui::Text("text");
        }
    }
}

void Viewport::PushData(const char* name, size_t size)
{
    ViewportWidget widget;
    widget.name = name;
    widget.type = GetTypeByName(widget.name);
    m_WidgetList.push_back(widget);
}