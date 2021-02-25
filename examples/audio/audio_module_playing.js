/*******************************************************************************************
*
*   raylib [audio] example - Module playing (streaming)
*
*   This example has been created using raylib 1.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var MAX_CIRCLES = 64;

    var screenWidth = 800;
    var screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);  // NOTE: Try to enable MSAA 4X

    InitWindow(screenWidth, screenHeight, "raylib [audio] example - module playing (streaming)");

    InitAudioDevice();                  // Initialize audio device

    var colors = [ ORANGE, RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK,
                         YELLOW, GREEN, SKYBLUE, PURPLE, BEIGE ];

    // Creates ome circles for visual effect
    var circles = [];

    for (var i = MAX_CIRCLES - 1; i >= 0; i--)
    {
        circles[i] = {};
        circles[i].alpha = 0;
        circles[i].radius = GetRandomValue(10, 40);
        circles[i].position.x = GetRandomValue(circles[i].radius, screenWidth - circles[i].radius);
        circles[i].position.y = GetRandomValue(circles[i].radius, screenHeight - circles[i].radius);
        circles[i].speed = GetRandomValue(1, 100)/2000;
        circles[i].color = colors[GetRandomValue(0, 13)];
    }

    var music = LoadMusicStream("resources/mini1111.xm");
    music.looping = false;
    var pitch = 1;

    PlayMusicStream(music);

    var timePlayed = 0;
    var pause = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateMusicStream(music);      // Update music buffer with new stream data

        // Restart music playing (stop and play)
        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
        }

        // Pause/Resume music playing
        if (IsKeyPressed(KEY_P))
        {
            pause = !pause;

            if (pause) PauseMusicStream(music);
            else ResumeMusicStream(music);
        }

        if (IsKeyDown(KEY_DOWN)) pitch -= 0.01;
        else if (IsKeyDown(KEY_UP)) pitch += 0.01;
        
        SetMusicPitch(music, pitch);

        // Get timePlayed scaled to bar dimensions
        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music)*(screenWidth - 40);

        // Color circles animation
        for (var i = MAX_CIRCLES - 1; (i >= 0) && !pause; i--)
        {
            circles[i].alpha += circles[i].speed;
            circles[i].radius += circles[i].speed*10;

            if (circles[i].alpha > 1) circles[i].speed *= -1;

            if (circles[i].alpha <= 0)
            {
                circles[i].alpha = 0;
                circles[i].radius = GetRandomValue(10, 40);
                circles[i].position = new Vector2();
                circles[i].position.x = GetRandomValue(circles[i].radius, screenWidth - circles[i].radius);
                circles[i].position.y = GetRandomValue(circles[i].radius, screenHeight - circles[i].radius);
                circles[i].color = colors[GetRandomValue(0, 13)];
                circles[i].speed = GetRandomValue(1, 100)/2000;
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (var i = MAX_CIRCLES - 1; i >= 0; i--)
            {
                DrawCircleV(circles[i].position, circles[i].radius, Fade(circles[i].color, circles[i].alpha));
            }

            // Draw time bar
            DrawRectangle(20, screenHeight - 20 - 12, screenWidth - 40, 12, LIGHTGRAY);
            DrawRectangle(20, screenHeight - 20 - 12, Math.floor(timePlayed), 12, MAROON);
            DrawRectangleLines(20, screenHeight - 20 - 12, screenWidth - 40, 12, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadMusicStream(music);          // Unload music stream buffers from RAM

    CloseAudioDevice();     // Close audio device (music streaming is automatically stopped)

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();
