#include "TextureManager.h"

#include "SDL2/SDL_image.h"

#include "Application.h"

#include "Log.h"

SDL_Renderer* Application::m_applicationRenderer;

SDL_Texture* TextureManager::loadImage(std::string&& p_textureLocation)
{
	SDL_Texture* resultingTexture = nullptr;
	SDL_Surface* tempSurface = nullptr;

	tempSurface = IMG_Load(p_textureLocation.c_str());
	Log::validateObject(tempSurface);

	resultingTexture = SDL_CreateTextureFromSurface(Application::applicationRenderer(), tempSurface);
	Log::validateObject(resultingTexture);

	SDL_FreeSurface(tempSurface);
	
	return resultingTexture;
}
