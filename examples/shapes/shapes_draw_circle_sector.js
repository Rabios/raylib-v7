/*******************************************************************************************
*
*   raylib [shapes] example - draw circle sector (with gui options)
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

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - draw circle sector");

    var center = new Vector2((GetScreenWidth() - 300)/2, GetScreenHeight()/2);

    var outerRadius = 180;
    var startAngle = 0;
    var endAngle = 180;
    var segments = 0;

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

            DrawCircleSector(center, outerRadius, startAngle, endAngle, segments, Fade(MAROON, 0.3));
            DrawCircleSectorLines(center, outerRadius, startAngle, endAngle, segments, Fade(MAROON, 0.6));
            
            // Draw GUI controls
            //------------------------------------------------------------------------------
            startAngle = GuiSliderBar(new Rectangle(600, 40, 120, 20), "StartAngle", null, startAngle, 0, 720);
            endAngle = GuiSliderBar(new Rectangle(600, 70, 120, 20), "EndAngle", null, endAngle, 0, 720);
            
            outerRadius = GuiSliderBar(new Rectangle(600, 140, 120, 20), "Radius", null, outerRadius, 0, 200);
            segments = GuiSliderBar(new Rectangle(600, 170, 120, 20), "Segments", null, segments, 0, 100);
            //------------------------------------------------------------------------------
            
            DrawText(TextFormat("MODE: %s", (segments >= 4)? "MANUAL" : "AUTO"), 600, 200, 10, (segments >= 4)? MAROON : DARKGRAY);
            
            DrawFPS(10, 10);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------  
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();
