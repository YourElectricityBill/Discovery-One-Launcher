#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"

#include "Scene.h"

enum class WindowType
{
	LAUNCHER,
};

class Window
{
public:
	Window(WindowType p_windowType);

	void changeScene();

	inline SDL_Window*& window() { return m_window; }
	inline HWND& windowHandle() { return m_windowHandle; }
	inline Scene& currentScene() { return m_currentScene; }

	inline int windowX() const { return m_windowX; }
	inline int windowY() const { return m_windowY; }
	inline int windowWidth() const { return m_windowWidth; }
	inline int windowHeight() const { return m_windowHeight; }

	inline void setWindowX(int& p_windowX) { m_windowX = p_windowX; }
	inline void setWindowY(int& p_windowY) { m_windowY = p_windowY; }

	~Window();
private:
	SDL_Window* m_window;
	WindowType m_windowType;
	SDL_SysWMinfo m_windowInfo;
	HWND m_windowHandle;

	Scene m_currentScene;

	int m_windowX;
	int m_windowY;
	int m_windowWidth;
	int m_windowHeight;
};