#pragma once
#include "Actor.h"
class Left :
    public Actor
{
public:

    Left(Game* game);

    int mCount;

    void AddCount(int n);

    int GetCount() { return mCount; };

    void DeleteLeft();

private:
    
    void UpdateTexture();
    class SpriteComponent* mSprite;
};

