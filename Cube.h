#pragma once
#include "Actor.h"
class Cube :
    public Actor
{
public:
    enum CubeType
    {
        Cube1,
        Cube2,
        Cube3,
        Cube4,
        Cube5,
        Cube6,
        Empty
    };

    Cube(Game* game);

    void SetNumber(int number);
    CubeType GetCubeType() const {return mCubeType;}
    void ToggleSelect();
    
private:
    void UpdateTexture();
    class SpriteComponent* mSpriteCube;
    class SpriteComponent* mSpriteSelect;
    CubeType mCubeType;
    bool mSelected;

};

