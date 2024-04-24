#include "Cube.h"
#include "SpriteComponent.h"
#include "Game.h"

Cube::Cube(class Game* game)
:Actor(game)
, mSpriteCube(nullptr)
, mSpriteSelect(nullptr)
, mCubeType(Empty)
, mSelected(false)
{
	mSpriteCube = new SpriteComponent(this);
	mSpriteSelect = new SpriteComponent(this);
	UpdateTexture();
}

void Cube::SetNumber(int number)
{
	if (number == 1) { mCubeType = Cube1;}
	else if (number == 2) { mCubeType = Cube2;}
	else if (number == 3) { mCubeType = Cube3; }
	else if (number == 4) { mCubeType = Cube4; }
	else if (number == 5) { mCubeType = Cube5; }
	else if (number == 6) { mCubeType = Cube6; }
	else { mCubeType = Empty; }

	UpdateTexture();
}

void Cube::ToggleSelect()
{
	mSelected = !mSelected;
	//空のキューブは選択状態にしない
	if (mCubeType == Empty && mSelected)
	{
		mSelected = false;
	}	
	UpdateTexture();
}



void Cube::UpdateTexture()
{
	std::string text;
	switch (mCubeType)
	{
		case Cube1:
		default:
			text = "Assets/cube_1.png";
			break;
		case Cube2:
			text = "Assets/cube_2.png";
			break;
		case Cube3:
			text = "Assets/cube_3.png";
			break;
		case Cube4:
			text = "Assets/cube_4.png";
			break;
		case Cube5:
			text = "Assets/cube_5.png";
			break;
		case Cube6:
			text = "Assets/cube_6.png";
			break;
		case Empty:
			text = "Assets/empty.png";
			break;
	}

	mSpriteCube->SetTexture(GetGame()->GetTexture(text));

	if (mSelected)
	{
		text = "Assets/select.png";
		
	}
	else
	{
		text = "Assets/empty.png";
	}
	mSpriteSelect->SetTexture(GetGame()->GetTexture(text));
}