
#pragma once
#include <vector>
#include "Math.h"
class Actor
{
public:
	enum State
	{
		EActive,
		EPaused,
	};

	Actor(class Game* game);
	virtual ~Actor();

	// �Q�[������Ăяo�����X�V�֐�
	void Update(float deltaTime);
	// �A�N�^�[�����كR���|�[�l���g���X�V
	void UpdateComponents(float deltaTime);
	// �A�N�^�[�Ǝ��̍X�V����
	virtual void UpdateActor(float deltaTime);

	// �Q�b�^�[ / �Z�b�^�[
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	class Game* GetGame() { return mGame; }


	// �R���|�[�l���g�̒ǉ� / �폜
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

private:
	// �A�N�^�[�̏��
	State mState;

	// ���W�ϊ�
	Vector2 mPosition;	// �A�N�^�[�̒��S�ʒu
	float mScale;		// �A�N�^�[�̃X�P�[�� (1.0f��100%)
	float mRotation;	// ��]�̊p�x (���W�A��)
	// �A�N�^�[�����R���|�[�l���g
	std::vector<class Component*> mComponents;
	class Game* mGame;
};
