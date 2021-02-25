/*******************************************************************************************
*
*   raylib [shapes] example - draw ring (with gui options)
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
    var screenWidth = 800;
    var screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - draw ring");

    var center = new Vector2((GetScreenWidth() - 300)/2, GetScreenHeight()/2);

    var innerRadius = 80.0;
    var outerRadius = 190.0;

    var startAngle = 0;
    var endAngle = 360;
    var segments = 0;

    var drawRing = true;
    var drawRingLines = false;
    var drawCircleLines = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // NOTE: All variables update happens inside GUI control functions
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawLine(500, 0, 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.6));
            DrawRectangle(500, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3));

            if (drawRing) DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(MAROON, 0.3));
            if (drawRingLines) DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(BLACK, 0.4));
            if (drawCircleLines) DrawCircleSectorLines(center, outerRadius, startAngle, endAngle, segments, Fade(BLACK, 0.4));

            // Draw GUI controls
            //------------------------------------------------------------------------------
            startAngle = GuiSliderBar(new Rectangle(600, 40, 120, 20), "StartAngle", null, startAngle, -450, 450);
            endAngle = GuiSliderBar(new Rectangle(600, 70, 120, 20), "EndAngle", null, endAngle, -450, 450);

            innerRadius = GuiSliderBar(new Rectangle(600, 140, 120, 20), "InnerRadius", null, innerRadius, 0, 100);
            outerRadius = GuiSliderBar(new Rectangle(600, 170, 120, 20), "OuterRadius", null, outerRadius, 0, 200);

            segments = GuiSliderBar(new Rectangle(600, 240, 120, 20), "Segments", null, segments, 0, 100);

            drawRing = GuiCheckBox(new Rectangle(600, 320, 20, 20), "Draw Ring", drawRing);
            drawRingLines = GuiCheckBox(new Rectangle(600, 350, 20, 20), "Draw RingLines", drawRingLines);
            drawCircleLines = GuiCheckBox(new Rectangle(600, 380, 20, 20), "Draw CircleLines", drawCircleLines);
            //------------------------------------------------------------------------------

            DrawText(TextFormat("MODE: %s", (segments >= 4)? "MANUAL" : "AUTO"), 600, 270, 10, (segments >= 4)? MAROON : DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();