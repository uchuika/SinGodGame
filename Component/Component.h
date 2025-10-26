#pragma once

namespace SinGame
{
	class Component
	{
	public:
		//コンストラクタ
		//(更新順序が低いほど、コンポーネントは早く更新される)
		Component(class Actor* owner, int updateOrder = 100);

		//デストラクタ
		virtual ~Component();

		//このコンポーネントをデルタタイムで更新
		virtual void Update(double deltaTime);

		//更新順序を返す
		int GetUpdateOrder() const { return mUpdateOrder; }

	protected:
		//アクターのオーナー
		class Actor* mOwner;

		//コンポーネントの順序を更新する
		int mUpdateOrder;
	};
}
