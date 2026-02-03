/**
 * @file collision_system.cpp
 * @author Ashley Low
 * @brief Grid-based player–obstacle collision.
 *
 * Demonstrates simple AABB-style checks
 * and death-state triggering for tile games.
 */

#include <vector>

constexpr int grid_size_with_border = 64;

bool alive = true;

void OnDeath()
{
    alive = false;
}

// Checks collision between player and obstacle on grid.
void CheckObstacleCollision(int obstacleX, int obstacleY,
                            int playerX, int playerY)
{
    int half = grid_size_with_border / 2;

    bool overlapY =
        playerY <= obstacleY + half &&
        playerY >= obstacleY - half;

    bool overlapX =
        playerX >= obstacleX - half &&
        playerX <= obstacleX + half;

    if (overlapX && overlapY)
    {
        OnDeath();
    }
}
