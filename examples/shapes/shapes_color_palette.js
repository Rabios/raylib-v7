/*******************************************************************************************
*
*   raylib [shapes] example - Colors palette
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014-2019 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var MAX_COLORS_COUNT = 21;

    var screenWidth = 800;
    var screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - colors palette");

    var colors = [
        DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, DARKBROWN,
        GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK, YELLOW,
        GREEN, SKYBLUE, PURPLE, BEIGE ];

    var colorNames = [
        "DARKGRAY", "MAROON", "ORANGE", "DARKGREEN", "DARKBLUE", "DARKPURPLE",
        "DARKBROWN", "GRAY", "RED", "GOLD", "LIME", "BLUE", "VIOLET", "BROWN",
        "LIGHTGRAY", "PINK", "YELLOW", "GREEN", "SKYBLUE", "PURPLE", "BEIGE" ];

    var colorsRecs = [];     // Rectangles array

    // Fills colorsRecs data (for every rectangle)
    for (var i = 0; i < MAX_COLORS_COUNT; i++)
    {
        colorsRecs[i] = new Rectangle(20 + 100*(i%7) + 10*(i%7), 80 + 100*(i/7) + 10*(i/7), 100, 100);
    }

    var colorState = [];           // Color state: 0-DEFAULT, 1-MOUSE_HOVER

    var mousePoint = new Vector2(0, 0);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePoint = GetMousePosition();

        for (var i = 0; i < MAX_COLORS_COUNT; i++)
        {
            if (CheckCollisionPointRec(mousePoint, colorsRecs[i])) colorState[i] = 1;
            else colorState[i] = 0;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("raylib colors palette", 28, 42, 20, BLACK);
            DrawText("press SPACE to see all colors", GetScreenWidth() - 180, GetScreenHeight() - 40, 10, GRAY);

            for (var i = 0; i < MAX_COLORS_COUNT; i++)    // Draw all rectangles
            {
                DrawRectangleRec(colorsRecs[i], Fade(colors[i], colorState[i]? 0.6 : 1.0));

                if (IsKeyDown(KEY_SPACE) || colorState[i])
                {
                    DrawRectangle(colorsRecs[i].x, colorsRecs[i].y + colorsRecs[i].height - 26, colorsRecs[i].width, 20, BLACK);
                    DrawRectangleLinesEx(colorsRecs[i], 6, Fade(BLACK, 0.3));
                    DrawText(colorNames[i], colorsRecs[i].x + colorsRecs[i].width - MeasureText(colorNames[i], 10) - 12,
                             colorsRecs[i].y + colorsRecs[i].height - 20, 10, colors[i]);
                }
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();