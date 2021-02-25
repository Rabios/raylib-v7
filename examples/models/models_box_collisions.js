/*******************************************************************************************
*
*   raylib [models] example - Detect basic 3d collisions (box vs sphere vs box)
*
*   This example has been created using raylib 1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var screenWidth = 800;
    var screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - box collisions");

    // Define the camera to look into our 3d world
    var camera = new Camera(new Vector3(0, 10, 10), new Vector3(0, 0, 0), new Vector3(0, 1, 0), 45, 0);

    var playerPosition = new Vector3(0, 1, 2);
    var playerSize = new Vector3(1, 2, 1);
    var playerColor = GREEN;

    var enemyBoxPos = new Vector3(-4, 1, 0);
    var enemyBoxSize = new Vector3(2, 2, 2);

    var enemySpherePos = new Vector3(4, 0, 0);
    var enemySphereSize = 1.5;

    var collision = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Move player
        if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 0.2;
        else if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 0.2;
        else if (IsKeyDown(KEY_DOWN)) playerPosition.z += 0.2;
        else if (IsKeyDown(KEY_UP)) playerPosition.z -= 0.2;

        collision = false;

        // Check collisions player vs enemy-box
        if (CheckCollisionBoxes(
            new BoundingBox(new Vector3(playerPosition.x - playerSize.x/2,
                                     playerPosition.y - playerSize.y/2,
                                     playerPosition.z - playerSize.z/2),
                            new Vector3(playerPosition.x + playerSize.x/2,
                                     playerPosition.y + playerSize.y/2,
                                     playerPosition.z + playerSize.z/2)),
            new BoundingBox(new Vector3(enemyBoxPos.x - enemyBoxSize.x/2,
                                     enemyBoxPos.y - enemyBoxSize.y/2,
                                     enemyBoxPos.z - enemyBoxSize.z/2),
                            new Vector3(enemyBoxPos.x + enemyBoxSize.x/2,
                                     enemyBoxPos.y + enemyBoxSize.y/2,
                                     enemyBoxPos.z + enemyBoxSize.z/2)))) collision = true;

        // Check collisions player vs enemy-sphere
        if (CheckCollisionBoxSphere(
            new BoundingBox(new Vector3(playerPosition.x - playerSize.x/2,
                                     playerPosition.y - playerSize.y/2,
                                     playerPosition.z - playerSize.z/2),
                            new Vector3(playerPosition.x + playerSize.x/2,
                                     playerPosition.y + playerSize.y/2,
                                     playerPosition.z + playerSize.z/2)),
            enemySpherePos, enemySphereSize)) collision = true;

        if (collision) playerColor = RED;
        else playerColor = GREEN;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Draw enemy-box
                DrawCube(enemyBoxPos, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, GRAY);
                DrawCubeWires(enemyBoxPos, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, DARKGRAY);

                // Draw enemy-sphere
                DrawSphere(enemySpherePos, enemySphereSize, GRAY);
                DrawSphereWires(enemySpherePos, enemySphereSize, 16, 16, DARKGRAY);

                // Draw player
                DrawCubeV(playerPosition, playerSize, playerColor);

                DrawGrid(10, 1);        // Draw a grid

            EndMode3D();

            DrawText("Move player with cursors to collide", 220, 40, 20, GRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();
