/*******************************************************************************************
*
*   raylib [models] example - rlgl module usage with push/pop matrix transformations
*
*   This example uses [rlgl] module funtionality (pseudo-OpenGL 1.1 style coding)
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2018 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var screenWidth = 800;
    var screenHeight = 450;

    var sunRadius = 4;
    var earthRadius = 0.6;
    var earthOrbitRadius = 8;
    var moonRadius = 0.16;
    var moonOrbitRadius = 1.5;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - rlgl module usage with push/pop matrix transformations");

    // Define the camera to look into our 3d world
    var camera = new Camera();
    camera.position = new Vector3(16, 16, 16);
    camera.target = new Vector3(0, 0, 0);
    camera.up = new Vector3(0, 1, 0);
    camera.fovy = 45;
    camera.type = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE);

    var rotationSpeed = 0.2;       // General system rotation speed

    var earthRotation = 0;         // Rotation of earth around itself (days) in degrees
    var earthOrbitRotation = 0;    // Rotation of earth around the Sun (years) in degrees
    var moonRotation = 0;          // Rotation of moon around itself
    var moonOrbitRotation = 0;     // Rotation of moon around earth in degrees

    SetTargetFPS(60);              // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(camera);

        earthRotation += (5*rotationSpeed);
        earthOrbitRotation += (365/360*(5*rotationSpeed)*rotationSpeed);
        moonRotation += (2*rotationSpeed);
        moonOrbitRotation += (8*rotationSpeed);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                rlPushMatrix();
                    rlScalef(sunRadius, sunRadius, sunRadius);          // Scale Sun
                    DrawSphereBasic(GOLD);                              // Draw the Sun
                rlPopMatrix();

                rlPushMatrix();
                    rlRotatef(earthOrbitRotation, 0, 1, 0);    // Rotation for Earth orbit around Sun
                    rlTranslatef(earthOrbitRadius, 0, 0);         // Translation for Earth orbit
                    rlRotatef(-earthOrbitRotation, 0, 1, 0);   // Rotation for Earth orbit around Sun inverted

                    rlPushMatrix();
                        rlRotatef(earthRotation, 0.25, 1.0, 0.0);       // Rotation for Earth itself
                        rlScalef(earthRadius, earthRadius, earthRadius);// Scale Earth

                        DrawSphereBasic(BLUE);                          // Draw the Earth
                    rlPopMatrix();

                    rlRotatef(moonOrbitRotation, 0, 1, 0);     // Rotation for Moon orbit around Earth
                    rlTranslatef(moonOrbitRadius, 0, 0);          // Translation for Moon orbit
                    rlRotatef(-moonOrbitRotation, 0, 1, 0);    // Rotation for Moon orbit around Earth inverted
                    rlRotatef(moonRotation, 0, 1, 0);          // Rotation for Moon itself
                    rlScalef(moonRadius, moonRadius, moonRadius);       // Scale Moon

                    DrawSphereBasic(LIGHTGRAY);                         // Draw the Moon
                rlPopMatrix();

                // Some reference elements (not affected by previous matrix transformations)
                DrawCircle3D(new Vector3(0, 0, 0), earthOrbitRadius, new Vector3(1, 0, 0), 90, Fade(RED, 0.5));
                DrawGrid(20, 1);

            EndMode3D();

            DrawText("EARTH ORBITING AROUND THE SUN!", 400, 10, 20, MAROON);
            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();

//--------------------------------------------------------------------------------------------
// Module Functions Definitions (local)
//--------------------------------------------------------------------------------------------

// Draw sphere without any matrix transformation
// NOTE: Sphere is drawn in world position ( 0, 0, 0 ) with radius 1.0f
function DrawSphereBasic(color)
{
    var rings = 16;
    var slices = 16;

    rlBegin(RL_TRIANGLES);
        rlColor4ub(color.r, color.g, color.b, color.a);

        for (var i = 0; i < (rings + 2); i++)
        {
            for (var j = 0; j < slices; j++)
            {
                rlVertex3f(Math.cos(DEG2RAD*(270+(180/(rings + 1))*i))*Math.sin(DEG2RAD*(j*360/slices)),
                           Math.sin(DEG2RAD*(270+(180/(rings + 1))*i)),
                           Math.cos(DEG2RAD*(270+(180/(rings + 1))*i))*Math.cos(DEG2RAD*(j*360/slices)));
                rlVertex3f(Math.cos(DEG2RAD*(270+(180/(rings + 1))*(i+1)))*Math.sin(DEG2RAD*((j+1)*360/slices)),
                           Math.sin(DEG2RAD*(270+(180/(rings + 1))*(i+1))),
                           Math.cos(DEG2RAD*(270+(180/(rings + 1))*(i+1)))*Math.cos(DEG2RAD*((j+1)*360/slices)));
                rlVertex3f(Math.cos(DEG2RAD*(270+(180/(rings + 1))*(i+1)))*Math.sin(DEG2RAD*(j*360/slices)),
                           Math.sin(DEG2RAD*(270+(180/(rings + 1))*(i+1))),
                           Math.cos(DEG2RAD*(270+(180/(rings + 1))*(i+1)))*Math.cos(DEG2RAD*(j*360/slices)));

                rlVertex3f(Math.cos(DEG2RAD*(270+(180/(rings + 1))*i))*Math.sin(DEG2RAD*(j*360/slices)),
                           Math.sin(DEG2RAD*(270+(180/(rings + 1))*i)),
                           Math.cos(DEG2RAD*(270+(180/(rings + 1))*i))*Math.cos(DEG2RAD*(j*360/slices)));
                rlVertex3f(Math.cos(DEG2RAD*(270+(180/(rings + 1))*(i)))*Math.sin(DEG2RAD*((j+1)*360/slices)),
                           Math.sin(DEG2RAD*(270+(180/(rings + 1))*(i))),
                           Math.cos(DEG2RAD*(270+(180/(rings + 1))*(i)))*Math.cos(DEG2RAD*((j+1)*360/slices)));
                rlVertex3f(Math.cos(DEG2RAD*(270+(180/(rings + 1))*(i+1)))*Math.sin(DEG2RAD*((j+1)*360/slices)),
                           Math.sin(DEG2RAD*(270+(180/(rings + 1))*(i+1))),
                           Math.cos(DEG2RAD*(270+(180/(rings + 1))*(i+1)))*Math.cos(DEG2RAD*((j+1)*360/slices)));
            }
        }
    rlEnd();
}
