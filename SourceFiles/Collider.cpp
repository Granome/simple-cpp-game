#include <Collider.hpp>

Collider::Collider(sf::FloatRect _bounds)
{
    bounds = _bounds;
}

sf::FloatRect Collider::getBounds()
{
    return bounds;
}

void Collider::setBounds(sf::FloatRect _bounds)
{
    bounds = _bounds;
}

bool Collider::checkCollision(Collider otherCollider)
// AABB algorithm for 2D collision detection
{
    sf::FloatRect otherColliderBounds = otherCollider.bounds;
        if (bounds.left < otherColliderBounds.left + otherColliderBounds.width && 
            bounds.left + bounds.width > otherColliderBounds.left &&
            bounds.top < otherColliderBounds.top + otherColliderBounds.height && 
            bounds.top + bounds.height > otherColliderBounds.top)
            {
                return true;
            }
        else
        {
            return false;
        }
}