#include "Window.h"

Window::Window(WindowType p_windowType)
{
	m_windowType = p_windowType;
	if (m_windowType == WindowType::LAUNCHER)
	{
		SDL_CreateWindow(u8"Discovery One Launcher", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 680, 460, SDL_WINDOW_BORDERLESS);
	}
	else
	{
		// Error message
	}

}

Window::~Window()
{
	SDL_DestroyWindow(m_window);
}
