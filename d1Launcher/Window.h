#pragma once

#include "SDL2/SDL.h"

enum class WindowType
{
	LAUNCHER,
};

class Window
{
public:
	Window(WindowType p_windowType);

	~Window();
private:
	SDL_Window* m_window;
	WindowType m_windowType;
};