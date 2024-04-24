#include "Result.h"
#include "SpriteComponent.h"
#include "Game.h"

Result::Result(class Game* game)
	:Actor(game)
	, mSprite(nullptr)
{
	mText = "Assets/empty.png";
	mSprite = new SpriteComponent(this);

	UpdateTexture();
}

void Result::IsClear(bool res)
{
	if (res) 
	{
		mText = "clear";
	}
	else 
	{
		mText = "gameover";
	}

	UpdateTexture();
}

void Result::DeleteResult()
{
	mText = "empty";

	UpdateTexture();
	
}

void Result::UpdateTexture()
{
	std::string text;

	text = "Assets/" + mText + ".png";

	mSprite->SetTexture(GetGame()->GetTexture(text));
}