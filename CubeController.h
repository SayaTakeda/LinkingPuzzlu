#pragma once
#include "Actor.h"
class CubeController :
    public Actor
{
public:
    CubeController(class Game* game);

    void ProcessClick(int x, int y);

    bool IsFinish();

    bool IsClear();

    void Restart();
    
private:
    void InitializeCube();

    void SelectCube(size_t row, size_t col);

    void DeleteCube();

    void FillEmptySpacesDownward();

    void CountLeft();

    void AddToEmptyCube();

    void SetNumber();

    std::vector<std::vector<class Cube*>> mCubes;

    class Cube* mSelectedCube;

    class Cube* mLastSelectedCube[5];
    size_t mLastRow = -1;
    size_t mLastCol = -1;
    
    // �s�E��
    const size_t rows = 5;
    const size_t cols = 4;

    // cube�̔z�u
    int mNunbers[28];

    // �e��̉�ʊO��cube�̐�
    std::vector<class Left*> mLeft;

    // ������cube�̈ʒu
    const float StartX = 72.0f;
    const float StartY = 298.0f;

    // cude�̉摜�T�C�Y
    const float CubeSize = 48.0f;
};

