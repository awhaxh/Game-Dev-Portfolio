/**
 * @file moving_platform.cpp
 * @author Ashley Low
 * @brief Moving platform logic.
 *
 * Handles platform movement
 * and player carry.
 */

struct Platform {
    float x;
    float leftLimit;
    float rightLimit;
    float speed;
    bool movingRight = true;
};

struct Player {
    float x;
    bool onPlatform = false;
};

void UpdatePlatform(Platform& p, float dt) {
    float move = p.speed * dt;

    if (p.movingRight) {
        p.x += move;
        if (p.x >= p.rightLimit) {
            p.x = p.rightLimit;
            p.movingRight = false;
        }
    } else {
        p.x -= move;
        if (p.x <= p.leftLimit) {
            p.x = p.leftLimit;
            p.movingRight = true;
        }
    }
}

void ApplyPlatformCarry(Player& pl, const Platform& p, float dt) {
    if (!pl.onPlatform) return;

    float move = p.speed * dt;
    pl.x += (p.movingRight ? move : -move);
}
