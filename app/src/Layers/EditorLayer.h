#pragma once
#include "Appazoid/Appazoid.h"
#include "Panels/Tools.h"
#include "Panels/Viewport.h"

class EditorLayer : public az::Layer
{
public:
	EditorLayer();

	void OnConstruction();

	void OnEvent(az::Event& e) override;

	void OnUIRender() override;
private:
	Viewport m_Viewport;
	ToolsPanel m_ToolsPanel;
};