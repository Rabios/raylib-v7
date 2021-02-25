/*******************************************************************************************
*
*   raylib [shapes] example - easings box anim
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
    var screenWidth = 800;
    var screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - easings box anim");

    // Box variables to be animated with easings
    var rec = new Rectangle(GetScreenWidth()/2, -100, 100, 100);
    var rotation = 0;
    var alpha = 1;

    var state = 0;
    var framesCounter = 0;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch (state)
        {
            case 0:     // Move box down to center of screen
            {
                framesCounter++;
                
                // NOTE: Remember that 3rd parameter of easing function refers to
                // desired value variation, do not confuse it with expected final value!
                rec.y = EaseElasticOut(framesCounter, -100, GetScreenHeight()/2 + 100, 120);

                if (framesCounter >= 120)
                {
                    framesCounter = 0;
                    state = 1;
                }
            } break;
            
            case 1:     // Scale box to an horizontal bar
            {
                framesCounter++;
                rec.height = EaseBounceOut(framesCounter, 100, -90, 120);
                rec.width = EaseBounceOut(framesCounter, 100, GetScreenWidth(), 120);

                if (framesCounter >= 120)
                {
                    framesCounter = 0;
                    state = 2;
                }
            } break;
            case 2:     // Rotate horizontal bar rectangle
            {
                framesCounter++;
                rotation = EaseQuadOut(framesCounter, 0, 270, 240);

                if (framesCounter >= 240)
                {
                    framesCounter = 0;
                    state = 3;
                }
            } break;
            case 3:     // Increase bar size to fill all screen
            {
                framesCounter++;
                rec.height = EaseCircOut(framesCounter, 10, GetScreenWidth(), 120);

                if (framesCounter >= 120)
                {
                    framesCounter = 0;
                    state = 4;
                }
            } break;
            case 4:     // Fade out animation
            {
                framesCounter++;
                alpha = EaseSineOut(framesCounter, 1, -1, 160);

                if (framesCounter >= 160)
                {
                    framesCounter = 0;
                    state = 5;
                }
            } break;
            default: break;
        }

        // Reset animation at any moment
        if (IsKeyPressed(KEY_SPACE))
        {
            rec = new Rectangle(GetScreenWidth()/2, -100, 100, 100);
            rotation = 0;
            alpha = 1;
            state = 0;
            framesCounter = 0;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectanglePro(rec, new Vector2(rec.width/2, rec.height/2), rotation, Fade(BLACK, alpha));

            DrawText("PRESS [SPACE] TO RESET BOX ANIMATION!", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();
