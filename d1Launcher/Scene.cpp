#include "Scene.h"

#include "TextureManager.h"	

#include "Application.h"

#include "Button.h"

Scene::Scene()
{
	m_sceneIsEmpty = true;
}

void Scene::setSceneUp()
{
	if (m_sceneType == SceneType::MAIN)
	{
		setMainSceneUp();
	}
}

void Scene::cleanSceneUp()
{
	if (m_sceneIsEmpty == false)
	{

	}
	else
	{

	}
}

void Scene::display()
{
	SDL_RenderCopy(Application::applicationRenderer(), m_sceneBackground, NULL, NULL);

	for (auto& currentUIElement : m_uiElementVector)
	{
		currentUIElement->display();
	}

	SDL_RenderPresent(Application::applicationRenderer());
	SDL_RenderClear(Application::applicationRenderer());
}

Scene::~Scene()
{

}

void Scene::setMainSceneUp()
{
	m_sceneIsEmpty = false;
	m_sceneBackground = TextureManager::loadImage("Contents/Texture/LauncherBackground.jpg");
	m_uiElementVector.emplace_back(std::make_unique<GameName>());
	m_uiElementVector.emplace_back(std::make_unique<Button>(ButtonType::EXIT));
}
