#pragma once

#include "Window.h"

#include "SDL2/SDL_ttf.h"

#include <memory>

class Application
{
public:
	Application();

	static void run();

	static inline std::unique_ptr<Window>& getLauncherWindow() { return Application::m_launcherWindow; }
	static inline SDL_Renderer*& applicationRenderer() { return Application::m_applicationRenderer; }
	static inline const bool launcherIsRunning() { return Application::m_launcherIsRunning; }

	static inline void changeRunningState(bool&& p_runningState) { m_launcherIsRunning = p_runningState; }
	
	static TTF_Font* m_launcherFonts;

	~Application();
private:
	static void loadRenderer();
	static void handleEvents();

	static std::unique_ptr<Window> m_launcherWindow;

	static SDL_Renderer* m_applicationRenderer;
	static SDL_Event m_appEvent;


	static bool m_launcherIsRunning;
	static const int m_FPS = 60;

};