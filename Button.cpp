#include "Button.h"
#include "SpriteComponent.h"
#include "Game.h"
#include <string>

Button::Button(class Game* game)
	:Actor(game)
	, mSprite(nullptr)
	, mText("empty")
	, picX(0)
	, picY(0)
	,centerX(0)
	,centerY(0)
{
	mSprite = new SpriteComponent(this);
	UpdateTexture();
}

bool Button::ProcessClick(int x, int y)
{
	x -= centerX - picX / 2;
	y -= centerY - picY / 2;

	if (x >= 0 && x < picX && y >= 0 && y <= picY)
	{
		return true;
	}

	return false;
}

void Button::SetButtonPosition(const Vector2& pos)
{
	centerX = pos.x;
	centerY = pos.y;

	this->SetPosition(pos);
}

void Button::UpdateTexture()
{
	mSprite->SetTexture(GetGame()->GetTexture(mText));
}

void Button::SetSprite(std::string sp)
{
	mText = "Assets/" + sp + ".png";

	UpdateTexture();

	picX = mSprite->GetTexWidth();
	picY = mSprite->GetTexHeight();

}