/*******************************************************************************************
*
*   raylib [models] example - Waving cubes
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Codecat (@codecat) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2019 Codecat (@codecat) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var screenWidth = 800;
    var screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - waving cubes");

    // Initialize the camera
    var camera = new Camera();
    camera.position = new Vector3(30, 20, 30);
    camera.target = new Vector3(0, 0, 0);
    camera.up = new Vector3(0, 1, 0);
    camera.fovy = 70;
    camera.type = CAMERA_PERSPECTIVE;

    // Specify the amount of blocks in each direction
    var numBlocks = 15;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        var time = GetTime();

        // Calculate time scale for cube position and size
        var scale = (2 + Math.sin(time))*0.7;

        // Move camera around the scene
        var cameraTime = time*0.3;
        camera.position.x = Math.cos(cameraTime)*40;
        camera.position.z = Math.sin(cameraTime)*40;
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawGrid(10, 5);

                for (var x = 0; x < numBlocks; x++) 
                {
                    for (var y = 0; y < numBlocks; y++) 
                    {
                        for (var z = 0; z < numBlocks; z++) 
                        {
                            // Scale of the blocks depends on x/y/z positions
                            var blockScale = (x + y + z)/30;

                            // Scatter makes the waving effect by adding blockScale over time
                            var scatter = Math.sin(blockScale*20 + (time*4));

                            // Calculate the cube position
                            var cubePos = new Vector3((x - numBlocks/2)*(scale*3) + scatter,
                                                      (y - numBlocks/2)*(scale*2) + scatter,
                                                      (z - numBlocks/2)*(scale*3) + scatter);

                            // Pick a color with a hue depending on cube position for the rainbow color effect
                            var cubeColor = ColorFromHSV((((x + y + z)*18)%360), 0.75, 0.9);

                            // Calculate cube size
                            var cubeSize = (2.4 - scale)*blockScale;

                            // And finally, draw the cube!
                            DrawCube(cubePos, cubeSize, cubeSize, cubeSize, cubeColor);
                        }
                    }
                }
                
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
