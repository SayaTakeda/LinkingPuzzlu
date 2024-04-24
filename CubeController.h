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
    
    // 行・列
    const size_t rows = 5;
    const size_t cols = 4;

    // cubeの配置
    int mNunbers[28];

    // 各列の画面外のcubeの数
    std::vector<class Left*> mLeft;

    // 左下のcubeの位置
    const float StartX = 72.0f;
    const float StartY = 298.0f;

    // cudeの画像サイズ
    const float CubeSize = 48.0f;
};

