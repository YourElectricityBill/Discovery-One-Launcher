#pragma once

#include <string>

#include "SDL2/SDL.h"

#include "SDL2/SDL_ttf.h"

class TextureManager
{
public:
	static SDL_Texture* loadImage(std::string&& p_textureLocation);

private:
};