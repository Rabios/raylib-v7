/*******************************************************************************************
*
*   raylib [shapes] example - rectangle scaling by mouse
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Vlad Adrian (@demizdor) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2018 Vlad Adrian (@demizdor) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var MOUSE_SCALE_MARK_SIZE = 12;
    var screenWidth = 800;
    var screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - rectangle scaling mouse");

    var rec = new Rectangle(100, 100, 200, 80);

    var mousePosition = new Vector2();

    var mouseScaleReady = false;
    var mouseScaleMode = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, rec) &&
            CheckCollisionPointRec(mousePosition, new Rectangle(rec.x + rec.width - MOUSE_SCALE_MARK_SIZE, rec.y + rec.height - MOUSE_SCALE_MARK_SIZE, MOUSE_SCALE_MARK_SIZE, MOUSE_SCALE_MARK_SIZE)))
        {
            mouseScaleReady = true;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) mouseScaleMode = true;
        }
        else mouseScaleReady = false;

        if (mouseScaleMode)
        {
            mouseScaleReady = true;

            rec.width = (mousePosition.x - rec.x);
            rec.height = (mousePosition.y - rec.y);

            if (rec.width < MOUSE_SCALE_MARK_SIZE) rec.width = MOUSE_SCALE_MARK_SIZE;
            if (rec.height < MOUSE_SCALE_MARK_SIZE) rec.height = MOUSE_SCALE_MARK_SIZE;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) mouseScaleMode = false;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Scale rectangle dragging from bottom-right corner!", 10, 10, 20, GRAY);

            DrawRectangleRec(rec, Fade(GREEN, 0.5));

            if (mouseScaleReady)
            {
                DrawRectangleLinesEx(rec, 1, RED);
                DrawTriangle(new Vector2(rec.x + rec.width - MOUSE_SCALE_MARK_SIZE, rec.y + rec.height),
                             new Vector2(rec.x + rec.width, rec.y + rec.height),
                             new Vector2(rec.x + rec.width, rec.y + rec.height - MOUSE_SCALE_MARK_SIZE), RED);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();
