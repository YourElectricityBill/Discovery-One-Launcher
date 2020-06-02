#include "GameName.h"

#include "Application.h"

#include "Log.h"

TTF_Font* Application::m_launcherFonts;

GameName::GameName()
{
	m_gameName = "Discovery One: World of Freelancer";

	Application::m_launcherFonts = nullptr;
	Application::m_launcherFonts = TTF_OpenFont("Contents/Fonts/AgencyFB.ttf", 36);
	Log::validateObject(Application::m_launcherFonts);

	SDL_Surface* inscriptionSurface = nullptr;
	inscriptionSurface = TTF_RenderText_Blended(Application::m_launcherFonts, m_gameName.c_str(), { 217, 221, 250 });
	Log::validateObject(inscriptionSurface);

	m_uiElementTexture = SDL_CreateTextureFromSurface(Application::applicationRenderer(), inscriptionSurface);
	Log::validateObject(m_uiElementTexture);

	SDL_FreeSurface(inscriptionSurface);
	TTF_CloseFont(Application::m_launcherFonts);

	setGameNamePosition();
}

void GameName::display()
{
	SDL_RenderCopy(Application::applicationRenderer(), m_uiElementTexture, NULL, &m_uiElementDimension);
}

void GameName::doAction()
{

}

GameName::~GameName()
{
	m_gameName.clear();
}

void GameName::setGameNamePosition()
{
	int inscriptionWidth, inscriptionHeight;
	inscriptionWidth = inscriptionHeight = 0;

	SDL_QueryTexture(m_uiElementTexture, NULL, NULL, &inscriptionWidth, &inscriptionHeight);

	m_uiElementDimension.w = inscriptionWidth;
	m_uiElementDimension.h = inscriptionHeight;

	m_uiElementDimension.x = static_cast<int>(((Application::getLauncherWindow()->windowWidth() / 2) - (m_uiElementDimension.w / 2)));
	m_uiElementDimension.y = static_cast<int>(((Application::getLauncherWindow()->windowHeight() * 0.025f)));
}
