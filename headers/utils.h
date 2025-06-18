#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"
/** 
 * DrawSmoothCircleLines takes as input
 * @param Vector2 type for the center location
 * @param float type for the radius wanted
 * @param Color type for the color wanted
 * @param int type for number of segments wanted

 @return Draws a circle with n segments
*/
void DrawSmoothCircleLines(Vector2 center, float radius, Color color, int segments);

#endif