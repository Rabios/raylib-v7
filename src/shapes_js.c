#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <shapes_js.h>

static inline enum v7_err js_draw_pixel(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    Color color = js_get_color(v7, 2);
    DrawPixel(x, y, color);
    return V7_OK;
}

static inline enum v7_err js_draw_pixel_v(struct v7* v7) {
    Vector2 pos = js_get_vec2(v7, 0);
    Color color = js_get_color(v7, 1);
    DrawPixelV(pos, color);
    return V7_OK;
}

static inline enum v7_err js_draw_line(struct v7* v7) {
    int x1 = v7_get_int(v7, v7_arg(v7, 0));
    int y1 = v7_get_int(v7, v7_arg(v7, 1));
    int x2 = v7_get_int(v7, v7_arg(v7, 2));
    int y2 = v7_get_int(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawLine(x1, y1, x2, y2, color);
    return V7_OK;
}

static inline enum v7_err js_draw_line_v(struct v7* v7) {
    Vector2 pos1 = js_get_vec2(v7, 0);
    Vector2 pos2 = js_get_vec2(v7, 1);
    Color color = js_get_color(v7, 2);
    DrawLineV(pos1, pos2, color);
    return V7_OK;
}

static inline enum v7_err js_draw_line_ex(struct v7* v7) {
    Vector2 pos1 = js_get_vec2(v7, 0);
    Vector2 pos2 = js_get_vec2(v7, 1);
    float thick = (float)v7_get_double(v7, v7_arg(v7, 2));
    Color color = js_get_color(v7, 3);
    DrawLineEx(pos1, pos2, thick, color);
    return V7_OK;
}

static inline enum v7_err js_draw_line_bezier(struct v7* v7) {
    Vector2 pos1 = js_get_vec2(v7, 0);
    Vector2 pos2 = js_get_vec2(v7, 1);
    float thick = (float)v7_get_double(v7, v7_arg(v7, 2));
    Color color = js_get_color(v7, 3);
    DrawLineBezier(pos1, pos2, thick, color);
    return V7_OK;
}

static inline enum v7_err js_draw_line_strip(struct v7* v7) {
    v7_val_t arrarg = v7_arg(v7, 0);
    int count = v7_get_int(v7, v7_arg(v7, 1));
    Color color = js_get_color(v7, 2);
    DrawLineStrip((Vector2*)arrarg, count, color);
    return V7_OK;
}

static inline enum v7_err js_draw_circle(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    float radius = (float)v7_get_double(v7, v7_arg(v7, 2));
    Color color = js_get_color(v7, 3);
    DrawCircle(x, y, radius, color);
    return V7_OK;
}

static inline enum v7_err js_draw_circle_sector(struct v7* v7) {
    Vector2 center = js_get_vec2(v7, 0);
    float radius = (float)v7_get_double(v7, v7_arg(v7, 1));
    int startAngle = v7_get_int(v7, v7_arg(v7, 2));
    int endAngle = v7_get_int(v7, v7_arg(v7, 3));
    int segments = v7_get_int(v7, v7_arg(v7, 4));
    Color color = js_get_color(v7, 5);
    DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
    return V7_OK;
}

static inline enum v7_err js_draw_circle_sector_lines(struct v7* v7) {
    Vector2 center = js_get_vec2(v7, 0);
    float radius = (float)v7_get_double(v7, v7_arg(v7, 1));
    int startAngle = v7_get_int(v7, v7_arg(v7, 2));
    int endAngle = v7_get_int(v7, v7_arg(v7, 3));
    int segments = v7_get_int(v7, v7_arg(v7, 4));
    Color color = js_get_color(v7, 5);
    DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
    return V7_OK;
}

static inline enum v7_err js_draw_circle_gradient(struct v7* v7) {
    int centerX = v7_get_int(v7, v7_arg(v7, 0));
    int centerY = v7_get_int(v7, v7_arg(v7, 1));
    float radius = (float)v7_get_double(v7, v7_arg(v7, 2));
    Color color1 = js_get_color(v7, 3);
    Color color2 = js_get_color(v7, 4);
    DrawCircleGradient(centerX, centerY, radius, color1, color2);
    return V7_OK;
}

static inline enum v7_err js_draw_circle_v(struct v7* v7) {
    Vector2 center = js_get_vec2(v7, 0);
    float radius = (float)v7_get_double(v7, v7_arg(v7, 1));
    Color color = js_get_color(v7, 2);
    DrawCircleV(center, radius, color);
    return V7_OK;
}

static inline enum v7_err js_draw_circle_lines(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    float radius = (float)v7_get_double(v7, v7_arg(v7, 2));
    Color color = js_get_color(v7, 3);
    DrawCircleLines(x, y, radius, color);
    return V7_OK;
}

static inline enum v7_err js_draw_ellipse(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    float radiusH = (float)v7_get_double(v7, v7_arg(v7, 2));
    float radiusV = (float)v7_get_double(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawEllipse(x, y, radiusH, radiusV, color);
    return V7_OK;
}

static inline enum v7_err js_draw_ellipse_lines(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    float radiusH = (float)v7_get_double(v7, v7_arg(v7, 2));
    float radiusV = (float)v7_get_double(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawEllipseLines(x, y, radiusH, radiusV, color);
    return V7_OK;
}

static inline enum v7_err js_draw_ring(struct v7* v7) {
    Vector2 center = js_get_vec2(v7, 0);
    float innerRadius = (float)v7_get_double(v7, v7_arg(v7, 1));
    float outerRadius = (float)v7_get_double(v7, v7_arg(v7, 2));
    int startAngle = v7_get_int(v7, v7_arg(v7, 3));
    int endAngle = v7_get_int(v7, v7_arg(v7, 4));
    int segments = v7_get_int(v7, v7_arg(v7, 5));
    Color color = js_get_color(v7, 6);
    DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
    return V7_OK;
}

static inline enum v7_err js_draw_ring_lines(struct v7* v7) {
    Vector2 center = js_get_vec2(v7, 0);
    float innerRadius = (float)v7_get_double(v7, v7_arg(v7, 1));
    float outerRadius = (float)v7_get_double(v7, v7_arg(v7, 2));
    int startAngle = v7_get_int(v7, v7_arg(v7, 3));
    int endAngle = v7_get_int(v7, v7_arg(v7, 4));
    int segments = v7_get_int(v7, v7_arg(v7, 5));
    Color color = js_get_color(v7, 6);
    DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    int w = v7_get_int(v7, v7_arg(v7, 2));
    int h = v7_get_int(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawRectangle(x, y, w, h, color);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_v(struct v7* v7) {
    Vector2 pos = js_get_vec2(v7, 0);
    Vector2 size = js_get_vec2(v7, 1);
    Color color = js_get_color(v7, 2);
    DrawRectangleV(pos, size, color);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_rec(struct v7* v7) {
    Rectangle rec = js_get_rect(v7, 0);
    Color color = js_get_color(v7, 1);
    DrawRectangleRec(rec, color);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_pro(struct v7* v7) {
    Rectangle rec = js_get_rect(v7, 0);
    Vector2 origin = js_get_vec2(v7, 1);
    float rotation = (float)v7_get_double(v7, v7_arg(v7, 2));
    Color color = js_get_color(v7, 3);
    DrawRectanglePro(rec, origin, rotation, color);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_gradient_v(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    int w = v7_get_int(v7, v7_arg(v7, 2));
    int h = v7_get_int(v7, v7_arg(v7, 3));
    Color color1 = js_get_color(v7, 4);
    Color color2 = js_get_color(v7, 5);
    DrawRectangleGradientV(x, y, w, h, color1, color2);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_gradient_h(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    int w = v7_get_int(v7, v7_arg(v7, 2));
    int h = v7_get_int(v7, v7_arg(v7, 3));
    Color color1 = js_get_color(v7, 4);
    Color color2 = js_get_color(v7, 5);
    DrawRectangleGradientH(x, y, w, h, color1, color2);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_gradient_ex(struct v7* v7) {
    Rectangle rec = js_get_rect(v7, 0);
    Color col1 = js_get_color(v7, 1);
    Color col2 = js_get_color(v7, 2);
    Color col3 = js_get_color(v7, 3);
    Color col4 = js_get_color(v7, 4);
    DrawRectangleGradientEx(rec, col1, col2, col3, col4);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_lines(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    int w = v7_get_int(v7, v7_arg(v7, 2));
    int h = v7_get_int(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawRectangleLines(x, y, w, h, color);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_lines_ex(struct v7* v7) {
    Rectangle rec = js_get_rect(v7, 0);
    int thick = v7_get_int(v7, v7_arg(v7, 1));
    Color color = js_get_color(v7, 2);
    DrawRectangleLinesEx(rec, thick, color);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_rounded(struct v7* v7) {
    Rectangle rec = js_get_rect(v7, 0);
    float roundness = (float)v7_get_double(v7, v7_arg(v7, 1));
    int segments = v7_get_int(v7, v7_arg(v7, 2));
    Color color = js_get_color(v7, 3);
    DrawRectangleRounded(rec, roundness, segments, color);
    return V7_OK;
}

static inline enum v7_err js_draw_rectangle_rounded_lines(struct v7* v7) {
    Rectangle rec = js_get_rect(v7, 0);
    float roundness = (float)v7_get_double(v7, v7_arg(v7, 1));
    int segments = v7_get_int(v7, v7_arg(v7, 2));
    int lineThick = v7_get_int(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawRectangleRoundedLines(rec, roundness, segments, lineThick, color);
    return V7_OK;
}

static inline enum v7_err js_draw_triangle(struct v7* v7) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    Vector2 v3 = js_get_vec2(v7, 2);
    Color color = js_get_color(v7, 3);
    DrawTriangle(v1, v2, v3, color);
    return V7_OK;
}

static inline enum v7_err js_draw_triangle_lines(struct v7* v7) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    Vector2 v3 = js_get_vec2(v7, 2);
    Color color = js_get_color(v7, 3);
    DrawTriangleLines(v1, v2, v3, color);
    return V7_OK;
}

static inline enum v7_err js_draw_triangle_fan(struct v7* v7) {
    v7_val_t arrarg = v7_arg(v7, 0);
    int pointsCount = v7_get_int(v7, v7_arg(v7, 1));
    Color color = js_get_color(v7, 2);
    DrawTriangleFan((Vector2*)arrarg, pointsCount, color);
    return V7_OK;
}

static inline enum v7_err js_draw_triangle_strip(struct v7* v7) {
    v7_val_t arrarg = v7_arg(v7, 0);
    int pointsCount = v7_get_int(v7, v7_arg(v7, 1));
    Color color = js_get_color(v7, 2);
    DrawTriangleStrip((Vector2*)arrarg, pointsCount, color);
    return V7_OK;
}

static inline enum v7_err js_draw_poly(struct v7* v7) {
    Vector2 center = js_get_vec2(v7, 0);
    int sides = v7_get_int(v7, v7_arg(v7, 1));
    float radius = (float)v7_get_double(v7, v7_arg(v7, 2));
    float rotation = (float)v7_get_double(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawPoly(center, sides, radius, rotation, color);
    return V7_OK;
}

static inline enum v7_err js_draw_poly_lines(struct v7* v7) {
    Vector2 center = js_get_vec2(v7, 0);
    int sides = v7_get_int(v7, v7_arg(v7, 1));
    float radius = (float)v7_get_double(v7, v7_arg(v7, 2));
    float rotation = (float)v7_get_double(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawPolyLines(center, sides, radius, rotation, color);
    return V7_OK;
}

static inline enum v7_err js_check_collision_recs(struct v7* v7, v7_val_t* res) {
    Rectangle rec1 = js_get_rect(v7, 0);
    Rectangle rec2 = js_get_rect(v7, 1);
    *res = v7_mk_boolean(v7, (int)CheckCollisionRecs(rec1, rec2));
    return V7_OK;
}

static inline enum v7_err js_check_collision_circles(struct v7* v7, v7_val_t* res) {
    Vector2 center1 = js_get_vec2(v7, 0);
    float radius1 = (float)v7_get_double(v7, v7_arg(v7, 1));
    Vector2 center2 = js_get_vec2(v7, 2);
    float radius2 = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_boolean(v7, (int)CheckCollisionCircles(center1, radius1, center2, radius2));
    return V7_OK;
}

static inline enum v7_err js_check_collision_circle_rec(struct v7* v7, v7_val_t* res) {
    Vector2 center = js_get_vec2(v7, 0);
    float radius = (float)v7_get_double(v7, v7_arg(v7, 1));
    Rectangle rec = js_get_rect(v7, 2);
    *res = v7_mk_boolean(v7, (int)CheckCollisionCircleRec(center, radius, rec));
    return V7_OK;
}

static inline enum v7_err js_check_collision_point_rec(struct v7* v7, v7_val_t* res) {
    Vector2 point = js_get_vec2(v7, 0);
    Rectangle rec = js_get_rect(v7, 1);
    *res = v7_mk_boolean(v7, (int)CheckCollisionPointRec(point, rec));
    return V7_OK;
}

static inline enum v7_err js_check_collision_point_circle(struct v7* v7, v7_val_t* res) {
    Vector2 point = js_get_vec2(v7, 0);
    Vector2 center = js_get_vec2(v7, 1);
    float radius = (float)v7_get_double(v7, v7_arg(v7, 2));
    *res = v7_mk_boolean(v7, (int)CheckCollisionPointCircle(point, center, radius));
    return V7_OK;
}

static inline enum v7_err js_check_collision_point_triangle(struct v7* v7, v7_val_t* res) {
    Vector2 point = js_get_vec2(v7, 0);
    Vector2 p1 = js_get_vec2(v7, 1);
    Vector2 p2 = js_get_vec2(v7, 2);
    Vector2 p3 = js_get_vec2(v7, 3);
    *res = v7_mk_boolean(v7, (int)CheckCollisionPointTriangle(point, p1, p2, p3));
    return V7_OK;
}

static inline enum v7_err js_check_collision_lines(struct v7* v7, v7_val_t* res) {
    Vector2 startPos1 = js_get_vec2(v7, 0);
    Vector2 endPos1 = js_get_vec2(v7, 1);
    Vector2 startPos2 = js_get_vec2(v7, 2);
    Vector2 endPos2 = js_get_vec2(v7, 3);
    Vector2 collisionPoint = js_get_vec2(v7, 4);
    *res = v7_mk_boolean(v7, (int)CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, &collisionPoint));
    return V7_OK;
}

static inline enum v7_err js_get_collision_rec(struct v7* v7, v7_val_t* res) {
    Rectangle rec1 = js_get_rect(v7, 0);
    Rectangle rec2 = js_get_rect(v7, 1);
    js_return_rect(v7, res, GetCollisionRec(rec1, rec2));
    return V7_OK;
}

void raylib_v7_load_shapes(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "DrawPixel", &js_draw_pixel);
    v7_set_method(v7, v7_get_global(v7), "DrawPixelV", &js_draw_pixel_v);
    v7_set_method(v7, v7_get_global(v7), "DrawLine", &js_draw_line);
    v7_set_method(v7, v7_get_global(v7), "DrawLineV", &js_draw_line_v);
    v7_set_method(v7, v7_get_global(v7), "DrawLineEx", &js_draw_line_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawLineBezier", &js_draw_line_bezier);
    v7_set_method(v7, v7_get_global(v7), "DrawLineStrip", &js_draw_line_strip);
    v7_set_method(v7, v7_get_global(v7), "DrawCircle", &js_draw_circle);
    v7_set_method(v7, v7_get_global(v7), "DrawCircleSector", &js_draw_circle_sector);
    v7_set_method(v7, v7_get_global(v7), "DrawCircleSectorLines", &js_draw_circle_sector_lines);
    v7_set_method(v7, v7_get_global(v7), "DrawCircleGradient", &js_draw_circle_gradient);
    v7_set_method(v7, v7_get_global(v7), "DrawCircleV", &js_draw_circle_v);
    v7_set_method(v7, v7_get_global(v7), "DrawCircleLines", &js_draw_circle_lines);
    v7_set_method(v7, v7_get_global(v7), "DrawEllipse", &js_draw_ellipse);
    v7_set_method(v7, v7_get_global(v7), "DrawEllipseLines", &js_draw_ellipse_lines);
    v7_set_method(v7, v7_get_global(v7), "DrawRing", &js_draw_ring);
    v7_set_method(v7, v7_get_global(v7), "DrawRingLines", &js_draw_ring_lines);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangle", &js_draw_rectangle);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleV", &js_draw_rectangle_v);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleRec", &js_draw_rectangle_rec);
    v7_set_method(v7, v7_get_global(v7), "DrawRectanglePro", &js_draw_rectangle_pro);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleGradientV", &js_draw_rectangle_gradient_v);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleGradientH", &js_draw_rectangle_gradient_h);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleGradientEx", &js_draw_rectangle_gradient_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleLines", &js_draw_rectangle_lines);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleLinesEx", &js_draw_rectangle_lines_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleRounded", &js_draw_rectangle_rounded);
    v7_set_method(v7, v7_get_global(v7), "DrawRectangleRoundedLines", &js_draw_rectangle_rounded_lines);
    v7_set_method(v7, v7_get_global(v7), "DrawTriangle", &js_draw_triangle);
    v7_set_method(v7, v7_get_global(v7), "DrawTriangleLines", &js_draw_triangle_lines);
    v7_set_method(v7, v7_get_global(v7), "DrawTriangleFan", &js_draw_triangle_fan);
    v7_set_method(v7, v7_get_global(v7), "DrawTriangleStrip", &js_draw_triangle_strip);
    v7_set_method(v7, v7_get_global(v7), "DrawPoly", &js_draw_poly);
    v7_set_method(v7, v7_get_global(v7), "DrawPolyLines", &js_draw_poly_lines);

    v7_set_method(v7, v7_get_global(v7), "CheckCollisionRecs", &js_check_collision_recs);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionCircles", &js_check_collision_circles);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionCircleRec", &js_check_collision_circle_rec);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionPointRec", &js_check_collision_point_rec);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionPointCircle", &js_check_collision_point_circle);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionPointTriangle", &js_check_collision_point_triangle);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionLines", &js_check_collision_lines);
    v7_set_method(v7, v7_get_global(v7), "GetCollisionRec", &js_get_collision_rec);
}
