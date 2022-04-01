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
		virtual bool IsColliding(GameObject& me, GameObject& other, Collider* otherCollider)
		{
			if(me.position == other.position)
			{
				//Send collision for myself
				OnCollision(other);

				//Send collision for other
				RaiseOnCollisionEvent(otherCollider, me);

				return true;
			}

			return false;
		}
		virtual void OnCollision(GameObject& other) = 0;

		static void RaiseOnCollisionEvent(Collider* otherCollider, GameObject& reference)
		{
			otherCollider->OnCollision(reference);
		}
		

		template <class T>
		static bool TryGetCollider(T* src, Collider*& collider)
		{
			collider = dynamic_cast<Collider*>(src);
			return collider != nullptr;
		}
	};
}

