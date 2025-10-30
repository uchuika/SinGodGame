#include "Parameter.h"

using namespace SinGame;

//パラメータのセット
void Parameter::set(std::string key, int val)
{
	_map[key] = val;
}


//パラメータの取得
int Parameter::get(std::string key) const
{
	auto it = _map.find(key);//指定キーを取得
	if (_map.end() == it) {//無かったら
		return Error;//エラー
	}
	else {
		return it->second;//あったら値を返す
	}
}
