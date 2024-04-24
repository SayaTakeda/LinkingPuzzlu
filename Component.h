#pragma once
class Component
{
public:
	// �R���X�g���N�^�[
	// updateOrder���������قǑ����X�V�����
	Component(class Actor* owner, int updateOrder = 100);
	// �f�X�g���N�^�
	virtual ~Component();
	// ���̃R���|�[�l���g�Ńf���^�^�C�����X�V
	virtual void Update(float deltaTime);

	int GetUpdateOrder() const { return mUpdateOrder; }
protected:
	// ���L�A�N�^�[
	class Actor* mOwner;
	// �R���|�[�l���g�̍X�V����
	int mUpdateOrder;
};

