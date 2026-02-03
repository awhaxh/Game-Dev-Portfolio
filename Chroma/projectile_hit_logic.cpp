/**
 * @file projectile_hit_logic.cpp
 * @author Ashley Low
 * @brief Projectile hit logic.
 *
 * Handles color checks
 * and hit detection.
 */

#include <iostream>

enum class Color {
    Red,
    Blue,
    Green
};

struct GameObject {
    Color color;
    bool active = true;
};

struct Projectile {
    Color color;
    bool collided = false;
};

void HandleProjectileHit(Projectile& proj, GameObject& target) {
    if (!target.active || proj.collided)
        return;

    if (proj.color == target.color) {
        std::cout << "Color match! Object activated.\n";
        target.active = false; // example rule
    } else {
        std::cout << "Color mismatch. No effect.\n";
    }

    proj.collided = true;
}
