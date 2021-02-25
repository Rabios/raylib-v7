/*******************************************************************************************
*
*   raylib [audio] example - Multichannel sound playing
*
*   This example has been created using raylib 2.6 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Chris Camacho (@chriscamacho) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2019 Chris Camacho (@chriscamacho) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var screenWidth = 800;
    var screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [audio] example - Multichannel sound playing");

    InitAudioDevice();      // Initialize audio device

    var fxWav = LoadSound("resources/sound.wav");         // Load WAV audio file
    var fxOgg = LoadSound("resources/target.ogg");        // Load OGG audio file
    
    SetSoundVolume(fxWav, 0.2);

    SetTargetFPS(60);       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_ENTER)) PlaySoundMulti(fxWav);     // Play a new wav sound instance
        if (IsKeyPressed(KEY_SPACE)) PlaySoundMulti(fxOgg);     // Play a new ogg sound instance
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawText("MULTICHANNEL SOUND PLAYING", 20, 20, 20, GRAY);
            DrawText("Press SPACE to play new ogg instance!", 200, 120, 20, LIGHTGRAY);
            DrawText("Press ENTER to play new wav instance!", 200, 180, 20, LIGHTGRAY);

            DrawText("CONCURRENT SOUNDS PLAYING: " + GetSoundsPlaying(), 220, 280, 20, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    StopSoundMulti();       // We must stop the buffer pool before unloading

    UnloadSound(fxWav);     // Unload sound data
    UnloadSound(fxOgg);     // Unload sound data

    CloseAudioDevice();     // Close audio device

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();
