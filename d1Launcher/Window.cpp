#include "Window.h"

#include "Log.h"

#include <exception>

Window::Window(WindowType p_windowType)
{
	m_window = nullptr;
	m_windowType = p_windowType;


	if (m_windowType == WindowType::LAUNCHER)
	{
		m_windowWidth = 860;
		m_windowHeight = 460;
		m_window = SDL_CreateWindow(u8"Discovery One Launcher", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowWidth, m_windowHeight, SDL_WINDOW_BORDERLESS);
		Log::validateObject(m_window);

		SDL_VERSION(&m_windowInfo.version);
		SDL_GetWindowWMInfo(m_window, &m_windowInfo);
		m_windowHandle = m_windowInfo.info.win.window;
	}
	else
	{
		Log::coreLogger()->critical("Error creating window. Unknown type");
		throw "Unknown window type!";
	}

}

void Window::changeScene()
{
	m_currentScene.cleanSceneUp();
	m_currentScene.setSceneUp();
}

Window::~Window()
{
	SDL_DestroyWindow(m_window);
}
