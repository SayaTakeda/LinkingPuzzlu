#include "Left.h"
#include "SpriteComponent.h"
#include "Game.h"
#include <string>

Left::Left(class Game* game)
	:Actor(game)
	, mSprite(nullptr)
	, mCount(0)
{
	mSprite = new SpriteComponent(this);
	UpdateTexture();
}

void Left::AddCount(int n)
{
	mCount = n;

	UpdateTexture();
}

void Left::UpdateTexture()
{
	std::string text;
	text = "Assets/left_"+ std::to_string(mCount) +".png";

	mSprite->SetTexture(GetGame()->GetTexture(text));
}

void Left::DeleteLeft()
{
	std::string text;
	text = "Assets/left_empty.png";

	mSprite->SetTexture(GetGame()->GetTexture(text));
}