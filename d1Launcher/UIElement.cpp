#include "UIElement.h"

bool UIElement::intersects(int& p_cursorX, int& p_cursorY)
{
	if (!(p_cursorX < m_uiElementDimension.x) &&
		!(p_cursorX > m_uiElementDimension.x + m_uiElementDimension.w) &&
		!(p_cursorY < m_uiElementDimension.y) &&
		!(p_cursorY > m_uiElementDimension.y + m_uiElementDimension.h))
	{
		return true;
	}
	else
	{
		return false;
	}
}

UIElement::~UIElement()
{
	SDL_DestroyTexture(m_uiElementTexture);
}
