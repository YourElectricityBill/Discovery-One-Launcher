#pragma once

#include "UIElement.h"

#include <string>

class GameName : public UIElement
{
public:
	GameName();

	void display() override;
	void doAction() override;

	~GameName();
private:
	void setGameNamePosition();

	std::string m_gameName;
};