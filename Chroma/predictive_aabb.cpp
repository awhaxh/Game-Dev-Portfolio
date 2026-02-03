/**
 * @file predictive_aabb.cpp
 * @author Ashley Low
 * @brief Predictive AABB collision logic.
 *
 * Handles collision prediction
 * and basic resolution.
 */

#include <cmath>

struct Vec2 {
    float x, y;
};

struct AABB {
    Vec2 center;
    Vec2 half;
};

struct Body {
    Vec2 position;
    Vec2 velocity;
    AABB box;
    bool grounded = false;
};

bool CheckAABB(const AABB& a, const AABB& b) {
    return std::abs(a.center.x - b.center.x) <= (a.half.x + b.half.x) &&
           std::abs(a.center.y - b.center.y) <= (a.half.y + b.half.y);
}

void ResolveCollision(Body& player, const AABB& obstacle, float dt) {
    // Predict next position
    Vec2 nextPos {
        player.position.x + player.velocity.x * dt,
        player.position.y + player.velocity.y * dt
    };

    AABB predicted = player.box;
    predicted.center = nextPos;

    if (!CheckAABB(predicted, obstacle))
        return;

    float dx = obstacle.center.x - predicted.center.x;
    float px = (obstacle.half.x + predicted.half.x) - std::abs(dx);

    float dy = obstacle.center.y - predicted.center.y;
    float py = (obstacle.half.y + predicted.half.y) - std::abs(dy);

    // Resolve on smallest penetration axis
    if (px < py) {
        player.velocity.x = 0;
        player.position.x += (dx > 0 ? -px : px);
    } else {
        player.velocity.y = 0;
        player.position.y += (dy > 0 ? -py : py);

        if (dy > 0)
            player.grounded = true;
    }
}
