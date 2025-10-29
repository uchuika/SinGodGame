#pragma once

namespace SinGame
{
	template <typename _T>
	class Singleton {

	protected:
		Singleton() = default;
		virtual ~Singleton() = default;
		Singleton(const Singleton& r) = default;
		Singleton& operator=(const Singleton& r) = default;

	public:
		static _T* Instance() {
			static _T inst;
			return &inst;
		};
	};
}
