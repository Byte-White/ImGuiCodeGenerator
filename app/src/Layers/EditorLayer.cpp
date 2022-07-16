#include "EditorLayer.h"

EditorLayer::EditorLayer()
{

}

void EditorLayer::OnConstruction()
{

}

void EditorLayer::OnEvent(az::Event& e)
{
	az::EventDispatcher dispatcher(e);
}


void EditorLayer::OnUIRender()
{
	ImGui::Begin("Tools");
	m_ToolsPanel.Render();
	ImGui::End();
	
	ImGui::Begin("Viewport");
	ImGui::BeginChild("viewport_child");
	m_Viewport.Render();
	ImGui::EndChild();
	if(ImGui::BeginDragDropTarget()) // Drag drop on the whole window
    {
        if(const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("TOOL_ITEM"))
        {
            const char* data = (const char*)payload->Data;
            az::Log::Info("data: {0}",data);
			m_Viewport.PushData(data,payload->DataSize);
        }
        ImGui::EndDragDropTarget();
    }
	ImGui::End();

	ImGui::Begin("Properties");
	ImGui::End();

	ImGui::Begin("Widget View");
	for(auto& widget : m_Viewport.GetWidgetList())
	{
		ImGui::ArrowButton((widget.name+"_arrowbtn").c_str(),ImGuiDir_Left);
		ImGui::SameLine();
		ImGui::Text("%s",widget.name.c_str());
	}
	ImGui::End();
	
}