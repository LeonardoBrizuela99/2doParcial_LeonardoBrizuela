#include "Entity2D.h"

Entity2D::Entity2D() : Entity()
{

}

bool Entity2D::CheckCollisionAABB(Entity2D& vs)
{
	if (canCollision && vs.canCollision)
	{
		if (position.x < vs.position.x + vs.localScale[0] &&
			position.x + localScale[0] > vs.position.x &&
			position.y < vs.position.y + vs.localScale[1] &&
			position.y + localScale[1] > vs.position.y)
		{
			if (vs.weight < strength)
			{			
				vs.SetPosition(vs.GetPositionX() + (position.x - lastPosition.x),
					vs.GetPositionY() + (position.y - lastPosition.y),
					vs.GetPositionZ());			
			}
			else
			{

				position = lastPosition;
			}			return true;
		}
	}
	return false;
}