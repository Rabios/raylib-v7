/*******************************************************************************************
*
*   raylib - sample game: floppy
*
*   Sample game developed by Ian Eito, Albert Martos and Ramon Santamaria
*
*   This game has been created using raylib v1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

//----------------------------------------------------------------------------------
// Some Defines
//----------------------------------------------------------------------------------
var MAX_TUBES = 100;
var FLOPPY_RADIUS = 24;
var TUBES_WIDTH = 80;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
var screenWidth = 800;
var screenHeight = 450;

var gameOver = false;
var pause = false;
var score = 0;
var hiScore = 0;

var floppy = {};
var tubes = [];
var tubesPos = [];
var tubesSpeedX = 0;
var superfx = false;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
;(function() {
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "sample game: floppy");

    InitGame();
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update and Draw
        //----------------------------------------------------------------------------------
        UpdateDrawFrame();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models...)
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

})();
//------------------------------------------------------------------------------------
// Module Functions Definitions (local)
//------------------------------------------------------------------------------------

// Initialize game variables
function InitGame() {
    floppy.radius = FLOPPY_RADIUS;
    floppy.position = new Vector2(80, screenHeight/2 - floppy.radius);
    tubesSpeedX = 2;

    for (var i = 0; i < MAX_TUBES; i++)
    {
        tubesPos[i] = new Vector2(400 + 280*i, -GetRandomValue(0, 120));
    }

    for (var i = 0; i < MAX_TUBES*2; i += 2)
    {
        tubes[i] = {};
        //tubes[i].rec = new Rectangle(tubesPos[i/2].x, tubesPos[i/2].y, TUBES_WIDTH, 255);
        tubes[i].rec = { x: tubesPos[i/2].x, y: tubesPos[i/2].y, width: TUBES_WIDTH, height: 255 };
        tubes[i+1] = {};
        //tubes[i+1].rec = new Rectangle(tubesPos[i/2].x, 600 + tubesPos[i/2].y - 255, TUBES_WIDTH, 255);
        tubes[i+1].rec = { x: tubesPos[i/2].x, y: 600 + tubesPos[i/2].y - 255, width: TUBES_WIDTH, height: 255 };
        tubes[i/2].active = true;
    }

    score = 0;

    gameOver = false;
    superfx = false;
    pause = false;
}

// Update game (one frame)
function UpdateGame()
{
    if (!gameOver)
    {
        if (IsKeyPressed(KEY_P)) pause = !pause;

        if (!pause)
        {
            for (var i = 0; i < MAX_TUBES; i++) tubesPos[i].x -= tubesSpeedX;

            for (var i = 0; i < MAX_TUBES*2; i += 2)
            {
                tubes[i].rec.x = tubesPos[i/2].x;
                tubes[i+1].rec.x = tubesPos[i/2].x;
            }

            if (IsKeyDown(KEY_SPACE) && !gameOver) floppy.position.y -= 3;
            else floppy.position.y += 1;

            // Check Collisions
            for (var i = 0; i < MAX_TUBES*2; i++)
            {
                if (CheckCollisionCircleRec(floppy.position, floppy.radius, tubes[i].rec))
                {
                    gameOver = true;
                    pause = false;
                }
                else if ((tubes[i/2] && tubesPos[i/2] && tubesPos[i/2].x < floppy.position.x) && tubes[i/2].active && !gameOver)
                {
                    score += 100;
                    tubes[i/2].active = false;

                    superfx = true;

                    if (score > hiScore) hiScore = score;
                }
            }
        }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            gameOver = false;
        }
    }
}

// Draw game (one frame)
function DrawGame()
{
    BeginDrawing();

        ClearBackground(RAYWHITE);

        if (!gameOver) 
        {
            DrawCircle(floppy.position.x, floppy.position.y, floppy.radius, DARKGRAY);

            // Draw tubes
            for (var i = 0; i < MAX_TUBES; i++)
            {
                DrawRectangle(tubes[i*2].rec.x, tubes[i*2].rec.y, tubes[i*2].rec.width, tubes[i*2].rec.height, GRAY);
                DrawRectangle(tubes[i*2 + 1].rec.x, tubes[i*2 + 1].rec.y, tubes[i*2 + 1].rec.width, tubes[i*2 + 1].rec.height, GRAY);
            }
            
            // Draw flashing fx (one frame only)
            if (superfx)
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
                superfx = false;
            }

            DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);
            DrawText(TextFormat("HI-SCORE: %04i", hiScore), 20, 70, 20, LIGHTGRAY);

            if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);
        }
        else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);

    EndDrawing();
}

// Unload game variables
function UnloadGame()
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
}

// Update and Draw (one frame)
function UpdateDrawFrame()
{
    UpdateGame();
    DrawGame();
}
