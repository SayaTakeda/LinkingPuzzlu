#pragma once
#include "Actor.h"
#include <string>
class Result :    
    public Actor
{
public:
    Result(Game* game);
    void IsClear(bool res);
    void DeleteResult();

private:
    class SpriteComponent* mSprite;
    std::string mText;

    void UpdateTexture();
};

