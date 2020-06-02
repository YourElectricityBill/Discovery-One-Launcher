#pragma once

#include "SDL2/SDL.h"

class UIElement
{
public:
	UIElement() = default;

	virtual void display() = 0;
	virtual void doAction() = 0;

	virtual bool intersects(int& p_cursorX, int& p_cursorY);

	inline SDL_Texture*& uiElementTexture() { return m_uiElementTexture; }

	virtual ~UIElement();
protected:
	SDL_Texture* m_uiElementTexture;
	SDL_Rect m_uiElementDimension;
};