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

    // ‰æ‘œ‚Ì‘å‚«‚³
    int picX;
    int picY;

    // ‰æ‘œ‚Ì’†S
    int centerX;
    int centerY;

};

