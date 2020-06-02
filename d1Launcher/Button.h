#pragma once

#include "UIElement.h"

enum class ButtonType
{
	EXIT,
	MINIMIZE,
	GAME,
	NEWS,
	CHARACTERS,
	SETTINGS,
	CREDITS
};

struct ButtonTexture
{
	SDL_Texture* m_buttonFrame;
	SDL_Texture* m_buttonText;
};

class Button : public UIElement
{
public:
	Button(ButtonType&& p_buttonType);

	void display() override;
	void doAction() override;

	static SDL_Texture* loadButtonText(); // For buttons that have a text in them

	~Button();
private:
	ButtonType m_buttonType;
};