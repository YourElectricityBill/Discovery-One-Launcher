#pragma once

#include "SDL2/SDL.h"

#include "GameName.h"

#include <vector>

enum class SceneType
{
	MAIN,
};

class Scene
{
public:
	Scene();

	void setSceneUp();
	void cleanSceneUp();

	void display();

	inline SceneType& sceneType() { return m_sceneType; }
	inline std::vector<std::unique_ptr<UIElement>>& uiVector() { return m_uiElementVector; }

	inline void setSceneType(SceneType&& p_sceneType) { m_sceneType = p_sceneType; }

	~Scene();
private:
	void setMainSceneUp();

	SceneType m_sceneType;
	SDL_Texture* m_sceneBackground;

	std::vector<std::unique_ptr<UIElement>> m_uiElementVector;
	//std::vector<std::unique_ptr<Entity>> m_entityVector;

	bool m_sceneIsEmpty;
};