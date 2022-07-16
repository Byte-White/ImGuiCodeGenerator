#pragma once

#include "Appazoid/Appazoid.h"
#include "Layers/EditorLayer.h"

class MyApplication :public az::Application
{
public:
	MyApplication();
	void MenubarCallback();
};
