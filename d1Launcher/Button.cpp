#include "Button.h"

#include "TextureManager.h"

#include "Application.h"

Button::Button(ButtonType&& p_buttonType)
{
	m_buttonType = p_buttonType;

	if (m_buttonType == ButtonType::EXIT)
	{
		m_uiElementTexture = TextureManager::loadImage("Contents/Buttons/Exit.png");

		m_uiElementDimension.w = static_cast<int>(Application::getLauncherWindow()->windowWidth() * 0.03f);
		m_uiElementDimension.h = m_uiElementDimension.w;
		m_uiElementDimension.x = static_cast<int>(((Application::getLauncherWindow()->windowWidth() * 0.99f) - (m_uiElementDimension.w * 0.99f)));
		m_uiElementDimension.y = static_cast<int>(((Application::getLauncherWindow()->windowHeight() * 0.025f)));
	}
	else if (m_buttonType == ButtonType::MINIMIZE)
	{

	}
	else if (m_buttonType == ButtonType::GAME)
	{

	}
	else if (m_buttonType == ButtonType::NEWS)
	{

	}
	else if (m_buttonType == ButtonType::CHARACTERS)
	{

	}
	else if (m_buttonType == ButtonType::SETTINGS)
	{

	}
	else if (m_buttonType == ButtonType::CREDITS)
	{

	}
	else
	{
		
	}
}

void Button::display()
{
	if (m_buttonType == ButtonType::EXIT)
	{
		SDL_RenderCopy(Application::applicationRenderer(), m_uiElementTexture, NULL, &m_uiElementDimension);
	}
}

void Button::doAction()
{
	if (m_buttonType == ButtonType::EXIT)
	{
		Application::changeRunningState(false);
	}
}

Button::~Button()
{

}
