#pragma once
#include "Actor.h"
#include <string>
class Button :
    public Actor
{
public:
    Button(class Game* game);

    bool ProcessClick(int x, int y);

    void SetSprite(std::string sp);
    void SetButtonPosition(const Vector2& pos);

private:
    void UpdateTexture();
    class SpriteComponent* mSprite;
    std::string mText;

    // 画像の大きさ
    int picX;
    int picY;

    // 画像の中心
    int centerX;
    int centerY;

};

