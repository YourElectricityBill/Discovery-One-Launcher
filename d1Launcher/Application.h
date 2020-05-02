#pragma once

#include "Window.h"

class Application
{
public:
	Application();

	static inline Window& getLauncherWindow() { return Application::m_launcherWindow; }
	static inline const bool launcherIsRunning() { return Application::m_launcherIsRunning; }

	~Application();
private:
	static Window m_launcherWindow;

	static bool m_launcherIsRunning;
};