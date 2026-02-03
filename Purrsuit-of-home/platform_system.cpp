/**
 * @file platform_system.cpp
 * @author Ashley Low
 * @brief Moving platform collision logic.
 *
 * Handles player overlap and
 * platform state detection.
 */

constexpr int grid_size_with_border = 64;

struct Platform
{
    int pos_x;
    int pos_y;
};

bool on_platform = false;

bool PlatformCollisionCheck(const Platform& platform,
                            int playerX, int playerY)
{
    int half = grid_size_with_border / 2;

    bool withinX =
        playerX >= platform.pos_x - half &&
        playerX <= platform.pos_x + half;

    bool sameRow =
        playerY == platform.pos_y;

    if (withinX && sameRow)
    {
        on_platform = true;
        return true;
    }

    return false;
}
