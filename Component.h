#pragma once
class Component
{
public:
	// コンストラクター
	// updateOrderが小さいほど早く更新される
	Component(class Actor* owner, int updateOrder = 100);
	// デストラクタｰ
	virtual ~Component();
	// このコンポーネントでデルタタイムを更新
	virtual void Update(float deltaTime);

	int GetUpdateOrder() const { return mUpdateOrder; }
protected:
	// 所有アクター
	class Actor* mOwner;
	// コンポーネントの更新順序
	int mUpdateOrder;
};

