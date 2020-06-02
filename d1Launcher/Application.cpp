#include "Application.h"

#include "Log.h"

#include "SDL2/SDL_image.h"

#include <exception>


std::unique_ptr<Window> Application::m_launcherWindow;
SDL_Event Application::m_appEvent;
bool Application::m_launcherIsRunning;

Application::Application()
{
	Log::logInit();

	LN_CORE_TRACE("Starting an application...");


	LN_CORE_TRACE("Initializing SDL 2...");
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		LN_CORE_CRITICAL("Can't load SDL 2, error code: {0}", SDL_GetError());
		throw std::exception();
	}
	else
	{
		SDL_version sdl2Version;
		SDL_VERSION(&sdl2Version);

		LN_CORE_INFO("SDL 2 initialized succesfully, version {0}.{1}, patch {2}.", sdl2Version.major, sdl2Version.minor, sdl2Version.patch);
	}

	LN_CORE_TRACE("Initializing IMG Init...");
	if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & IMG_INIT_PNG | IMG_INIT_JPG)) 
	{
		LN_CORE_CRITICAL("Can't load SDL IMG library, error code: {0}", IMG_GetError());
		throw std::exception();
	}
	else
	{
		SDL_version imgVersion;
		SDL_IMAGE_VERSION(&imgVersion);

		LN_CORE_INFO("SDL 2 IMG initialized succesfully, version {0}.{1}, patch {2}", imgVersion.major, imgVersion.minor, imgVersion.patch);
	}

	LN_CORE_TRACE("Initializing SDL 2 TTF...");

	if (TTF_Init() != 0)
	{
		LN_CORE_CRITICAL("Can't load SDL 2 TTF, error code: {0}", TTF_GetError());
		throw std::exception();
	}
	else
	{
		SDL_version ttfVersion;
		SDL_TTF_VERSION(&ttfVersion);

		LN_CORE_INFO("SDL 2 TTF initialized succesfully, version {0}.{1}, patch {2}", ttfVersion.major, ttfVersion.minor, ttfVersion.patch);
	}


	Application::m_launcherWindow = std::make_unique<Window>(WindowType::LAUNCHER);
	Application::loadRenderer();

	Application::m_launcherWindow->currentScene().setSceneType(SceneType::MAIN);
	Application::m_launcherWindow->currentScene().setSceneUp();

	Application::m_launcherIsRunning = true;
}

void Application::run()
{
	const int frameDelay = 1000 / Application::m_FPS;

	Uint32 frameStart;
	int frameTime;

	while (Application::m_launcherIsRunning)
	{
		frameStart = SDL_GetTicks();

		m_launcherWindow->currentScene().display();

		Application::handleEvents();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

Application::~Application()
{
	SDL_DestroyRenderer(m_applicationRenderer);
	SDL_DestroyWindow(m_launcherWindow->window());
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Application::loadRenderer()
{
	m_applicationRenderer = SDL_CreateRenderer(m_launcherWindow->window(), NULL, SDL_RENDERER_ACCELERATED);
}

void Application::handleEvents()
{
	while (SDL_PollEvent(&m_appEvent))
	{
		static bool dragging;
		int cursorX, cursorY, windowPosX, windowPosY;
		static int xWindowSizeOffset, yWindowSizeOffset;
		SDL_GetMouseState(&cursorX, &cursorY);
		switch (m_appEvent.type)
		{
		case SDL_QUIT:
			Application::m_launcherIsRunning = false;
			break;
		case SDLK_ESCAPE:
			if (Application::m_launcherWindow->currentScene().sceneType() == SceneType::MAIN)
			{
				Application::m_launcherIsRunning = false;
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			dragging = true;
			SDL_GetWindowPosition(Application::m_launcherWindow->window(), &windowPosX, &windowPosY);

			SDL_GetMouseState(&xWindowSizeOffset, &yWindowSizeOffset);

			if (m_appEvent.button.button == SDL_BUTTON_LEFT)
			{
				for (auto& uiElement : Application::m_launcherWindow->currentScene().uiVector())
				{
					if (uiElement->intersects(cursorX, cursorY))
					{
						uiElement->doAction();
						break;
					}
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			dragging = false;
		case SDL_MOUSEMOTION:
			if (dragging)
			{
				int newWindowX, newWindowY;
				SDL_GetWindowPosition(Application::m_launcherWindow->window(), &newWindowX, &newWindowY);

				newWindowX = newWindowX + cursorX - xWindowSizeOffset;
				newWindowY = newWindowY + cursorY - yWindowSizeOffset;

				MoveWindow(Application::m_launcherWindow->windowHandle(), newWindowX, newWindowY, Application::m_launcherWindow->windowWidth(), Application::m_launcherWindow->windowHeight(), TRUE);

				Application::m_launcherWindow->setWindowX(newWindowX);
				Application::m_launcherWindow->setWindowY(newWindowY);
			}
			break;
		default:
			break;
		}
	}
}

