/**
 * @file obstacle_movement.cpp
 * @author Ashley Low
 * @brief Frame-independent obstacle movement.
 *
 * Shows dt-based updates and looping
 * behavior for endless lanes.
 */

#include <vector>

constexpr int grid_size_with_border = 64;
constexpr int kObstacleLoopTiles = 14;

struct Obstacle
{
    int pos_x;
    int pos_y;
    float velocity;
    int distance = 0;
};

void HandleVerticalObstacles(std::vector<Obstacle>& obstacles,
                             float dt)
{
    int loopDistance = kObstacleLoopTiles * grid_size_with_border;

    for (auto& obstacle : obstacles)
    {
        int move = static_cast<int>(obstacle.velocity * dt);

        obstacle.pos_x -= move;
        obstacle.distance += move;

        if (obstacle.distance >= loopDistance)
        {
            obstacle.pos_x += loopDistance;
            obstacle.distance = 0;
        }
    }
}
