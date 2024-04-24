#include "CubeController.h"
#include "Cube.h"
#include "Left.h"
#include <random>

CubeController::CubeController(class Game* game)
    :Actor(game)
{
    InitializeCube();
}

void CubeController::InitializeCube()
{
    mCubes.resize(rows);
    for (size_t i = 0; i < mCubes.size(); i++)
    {
        mCubes[i].resize(cols);
    }

    // cube�̏����z�u
    SetNumber();

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            mCubes[i][j] = new Cube(GetGame());
            mCubes[i][j]->SetNumber(mNunbers[i * cols + j]);
            mNunbers[i * cols + j] = 0;
            if (i < rows)
            {
                mCubes[i][j]->SetPosition(Vector2(StartX + j * CubeSize, StartY - i * CubeSize));
            }

        }
    }

    mLeft.resize(cols);
    for (size_t i = 0; i < cols; i++)
    {
        mLeft[i] = new Left(GetGame());
    }
    CountLeft();
}

void CubeController::SetNumber()
{
    // ����������̍쐬
    std::random_device rd;
    std::mt19937 gen(rd()); // �����Z���k�E�c�C�X�^�@��p��������������

    // �z�u�p�^�[����
    int patternCount = 5;

    // �����͈̔͂�ݒ�
    std::uniform_int_distribution<> dis(1, patternCount); // 1����5�܂ł̈�l���z

    int random_number = dis(gen);

    if (random_number == 1)
    {
        int temp[28] = { 1,2,1,6,2,3,2,1,1,2,3,2,1,1,4,3,1,4,3,5,1,3,2,2,2,4,1,1 };
        std::copy(std::begin(temp), std::end(temp), std::begin(mNunbers));
    }
    else if (random_number == 2)
    {
        int temp[28] = { 6,1,4,3,1,2,5,1,2,3,6,2,2,5,2,2,2,4,3,1,1,1,2,1,3,1,3,1 };
        std::copy(std::begin(temp), std::end(temp), std::begin(mNunbers));
    }
    else if (random_number == 3)
    {
        int temp[28] = { 3,2,1,1,4,2,3,2,2,1,4,2,1,5,1,1,2,1,3,2,2,6,1,3,1,4,1,2 };
        std::copy(std::begin(temp), std::end(temp), std::begin(mNunbers));
    }
    else if (random_number == 4)
    {
        int temp[28] = { 1,2,3,2,6,3,1,3,1,2,4,1,1,1,3,2,2,5,2,2,4,1,1,3,3,2,1,4 };
        std::copy(std::begin(temp), std::end(temp), std::begin(mNunbers));
    }
    else
    {
        int temp[28] = { 1,1,3,2,2,4,2,1,2,3,3,4,1,3,1,5,5,4,6,1,6,2,4,2,3,1,3,1 };
        std::copy(std::begin(temp), std::end(temp), std::begin(mNunbers));
    }
}

void CubeController::SelectCube(size_t row, size_t col)
{
    
    Cube* clickedCube = mCubes[row][col];

    if (clickedCube != mSelectedCube && mCubes[row][col])
    {
        Cube::CubeType ctype = mCubes[row][col]->GetCubeType();

        if (ctype == Cube::Cube1)
        {
            // �I������Ă���cube������ꍇ�A�I����ԉ���
            if (mSelectedCube)
            {
                for (size_t i = 0; i < 5; i++)
                {
                    if (mLastSelectedCube[i])
                    {
                        mLastSelectedCube[i]->ToggleSelect();
                        mLastSelectedCube[i] = nullptr;
                    }
                }
                mSelectedCube->ToggleSelect();
            }
            mSelectedCube = mCubes[row][col];
            mLastCol = col;
            mLastRow = row;
            mSelectedCube->ToggleSelect();
        }
        else
        {
            Cube::CubeType lastCtype = mSelectedCube->GetCubeType();
            // ���O�ɑI�����ꂽcube�̏㉺���E�̂ݑI���\
            if ((row == mLastRow - 1 && col == mLastCol) ||  // ��
                (row == mLastRow + 1 && col == mLastCol) ||  // ��
                (row == mLastRow && col == mLastCol - 1) ||  // ��
                (row == mLastRow && col == mLastCol + 1))   // �E
            {
                // �A������cube�̂ݑI���\
                if (ctype == lastCtype + 1) {
                    mLastSelectedCube[lastCtype - Cube::Cube1] = mSelectedCube;
                    mSelectedCube = mCubes[row][col];
                    mSelectedCube->ToggleSelect();
                    mLastCol = col;
                    mLastRow = row;
                   }
            }            
        }
        
    }
    // ����cube��A���őI������ƍ폜
    else if(clickedCube == mSelectedCube)
    {
        DeleteCube();    
        FillEmptySpacesDownward();
        AddToEmptyCube();
    }
}

void CubeController::ProcessClick(int x, int y)
{
    x -= static_cast<int>(StartX - CubeSize / 2);
    y -= static_cast<int>(StartY - CubeSize / 2 - CubeSize * (rows-1));
    if (y >= 0 && x >= 0)
    {
        x /= static_cast<int>(CubeSize);
        y /= static_cast<int>(CubeSize);
        if (x >= 0 && x < static_cast<int>(cols) && y >= 0 && y < static_cast<int>(rows))
        {
            SelectCube((rows - 1) - y, x);
        }
    }
}

void CubeController::DeleteCube()
{
    // �I������Ă���cube���폜���A�I������
    for (size_t i = 0; i < 5; i++)
    {
        if (mLastSelectedCube[i])
        {
            mLastSelectedCube[i]->ToggleSelect();
            mLastSelectedCube[i]->SetNumber(0);
        }
    }
    mSelectedCube->ToggleSelect();
    mSelectedCube->SetNumber(0);
}

void CubeController::FillEmptySpacesDownward()
{
    for (int j = 0; j < cols; j++)
    {
        // �ŏ�i����i������A�ォ�牺��
        for (int i = rows - 2; i >= 0; i--)
        {
            // ��̃L���[�u�͉��ɋl�߂�
            if (!mCubes[i][j] || mCubes[i][j]->GetCubeType() == Cube::Empty)
            {
                // ����ɃR�s�[
                for (int k = i; k < rows - 1; k++)
                {
                    mCubes[k][j] = mCubes[k + 1][j];
                    if (mCubes[k][j])
                    {
                        mCubes[k][j]->SetPosition(Vector2(StartX + j * CubeSize, StartY - k * CubeSize));
                    }
                }
                // �Ō�̍s����ɂ���
                mCubes[rows - 1][j] = nullptr;
            }
        }
    }
}

void CubeController::CountLeft()
{
    for (size_t j = 0; j < cols; j++)
    {
        int temp = 0;
        for (size_t i = rows; i < rows + 2; i++)
        {
            if (mNunbers[i * cols + j] != 0)
            {
                temp++;
            }
        }
        mLeft[j]->AddCount(temp);
        mLeft[j]->SetPosition(Vector2(StartX + j * CubeSize, StartY - rows * CubeSize + 10));
    }
}

void CubeController::AddToEmptyCube()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if ((!mCubes[i][j] || mCubes[i][j]->GetCubeType() == Cube::Empty) && mLeft[j]->GetCount() != 0)
            {
                for (int k = rows; k < rows + 2; k++)
                {
                    if (mNunbers[k * cols + j] != 0)
                    {
                        if (mCubes[i][j] == nullptr)
                        {
                            mCubes[i][j] = new Cube(GetGame());
                        }
                        mCubes[i][j]->SetNumber(mNunbers[k * cols + j]);
                        mCubes[i][j]->SetPosition(Vector2(StartX + j * CubeSize, StartY - i * CubeSize));

                        mNunbers[k * cols + j] = 0;

                        break;
                    }
                }
            }
        }
    }

    CountLeft();
}

bool CubeController::IsFinish()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (mCubes[i][j] && mCubes[i][j]->GetCubeType() == Cube::Cube1)
            {
                return false;
            }
        }
    }
    return true;
}


bool CubeController::IsClear()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (mCubes[i][j])
            {
                return false;
            }
        }
    }
    return true;

}

void CubeController::Restart()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mCubes[i][j])
            {
                mCubes[i][j]->SetNumber(0);
            }            
        }
    }

    for (int i = 0; i < cols; i++)
    {
        mLeft[i]->DeleteLeft();
    }
    
    InitializeCube();
}