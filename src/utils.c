#include "raylib.h"
#include "math.h"
#include "../headers/utils.h"


void DrawSmoothCircleLines(Vector2 center, float radius, Color color, int segments)
{
    for (int i = 0; i < segments; i++)
    {
        float theta1 = (2 * PI * i) / segments;
        float theta2 = (2 * PI * (i + 1)) / segments;

        Vector2 p1 = { center.x + cosf(theta1) * radius, center.y + sinf(theta1) * radius };
        Vector2 p2 = { center.x + cosf(theta2) * radius, center.y + sinf(theta2) * radius };

        DrawLineV(p1, p2, color);
    }
}
