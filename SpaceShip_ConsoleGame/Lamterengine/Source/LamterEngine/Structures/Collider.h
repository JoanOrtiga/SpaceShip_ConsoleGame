#pragma once

#include "../Classes/COORD.h"
#include "GameObject.h"

namespace Lamter
{
	class Collider
	{
	private:
		
	public:
		virtual ~Collider() = default;
		virtual void IsColliding(GameObject& me, GameObject& other)
		{
			if(me.position == other.position)
				OnCollision(other);
		}
		virtual void OnCollision(GameObject& other) = 0;

		template <class T>
		static bool TryGetCollider(T* src, Collider*& collider)
		{

			collider = dynamic_cast<Collider*>(src);
			return collider != nullptr;
		}
	};
}

