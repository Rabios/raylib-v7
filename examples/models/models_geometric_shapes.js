/*******************************************************************************************
*
*   raylib [models] example - Draw some basic geometric shapes (cube, sphere, cylinder...)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var screenWidth = 800;
    var screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - geometric shapes");

    // Define the camera to look into our 3d world
    var camera = new Camera();
    camera.position = new Vector3(0, 10, 10);
    camera.target = new Vector3(0, 0, 0);
    camera.up = new Vector3(0, 1, 0);
    camera.fovy = 45;
    camera.type = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawCube(new Vector3(-4, 0, 2), 2, 5, 2, RED);
                DrawCubeWires(new Vector3(-4, 0, 2), 2, 5, 2, GOLD);
                DrawCubeWires(new Vector3(-4, 0, -2), 3, 6, 2, MAROON);

                DrawSphere(new Vector3(-1, 0, -2), 1, GREEN);
                DrawSphereWires(new Vector3(1, 0, 2), 2, 16, 16, LIME);

                DrawCylinder(new Vector3(4, 0, -2), 1, 2, 3, 4, SKYBLUE);
                DrawCylinderWires(new Vector3(4, 0, -2), 1, 2, 3, 4, DARKBLUE);
                DrawCylinderWires(new Vector3(4.5, -1, 2), 1, 1, 2, 6, BROWN);

                DrawCylinder(new Vector3(1, 0, -4), 0, 1.5, 3, 8, GOLD);
                DrawCylinderWires(new Vector3(1, 0, -4), 0, 1.5, 3, 8, PINK);

                DrawGrid(10, 1);        // Draw a grid

            EndMode3D();

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();
