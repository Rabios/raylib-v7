/*******************************************************************************************
*
*   raylib - sample game: snake
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
var SNAKE_LENGTH = 256;
var SQUARE_SIZE  =  31;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
var screenWidth = 800;
var screenHeight = 450;

var framesCounter = 0;
var gameOver = false;
var pause = false;

var fruit = {};
var snake = [];
var snakePosition = [];
var allowMove = false;
var offset = null;
var counterTail = 0;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
;(function() {
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "sample game: snake");

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
    framesCounter = 0;
    gameOver = false;
    pause = false;
    
    counterTail = 1;
    allowMove = false;
    
    offset = new Vector2(screenWidth%SQUARE_SIZE, screenHeight%SQUARE_SIZE);

    for (var i = 0; i < SNAKE_LENGTH; i++)
    {
        snake[i] = {};
        snake[i].position = new Vector2(offset.x/2, offset.y/2);
        snake[i].size = new Vector2(SQUARE_SIZE, SQUARE_SIZE);
        snake[i].speed = new Vector2(SQUARE_SIZE, 0);

        if (i == 0) snake[i].color = DARKBLUE;
        else snake[i].color = BLUE;
    }

    for (var i = 0; i < SNAKE_LENGTH; i++)
    {
        snakePosition[i] = new Vector2(0, 0);
    }
    
    fruit.size = new Vector2(SQUARE_SIZE, SQUARE_SIZE);
    fruit.color = SKYBLUE;
    fruit.active = false;
}

// Update game (one frame)
function UpdateGame() {
    if (!gameOver)
    {
        if (IsKeyPressed(KEY_P)) pause = !pause;
        
        if (!pause)
        {
            // Player control
            if (IsKeyPressed(KEY_RIGHT) && (snake[0].speed.x == 0) && allowMove)
            {
                snake[0].speed = new Vector2(SQUARE_SIZE, 0);
                allowMove = false;
            }
            if (IsKeyPressed(KEY_LEFT) && (snake[0].speed.x == 0) && allowMove)
            {
                snake[0].speed = new Vector2(-SQUARE_SIZE, 0);
                allowMove = false;
            }
            if (IsKeyPressed(KEY_UP) && (snake[0].speed.y == 0) && allowMove)
            {
                snake[0].speed = new Vector2(-SQUARE_SIZE);
                allowMove = false;
            }
            if (IsKeyPressed(KEY_DOWN) && (snake[0].speed.y == 0) && allowMove)
            {
                snake[0].speed = new Vector2(0, SQUARE_SIZE);
                allowMove = false;
            }

            // Snake movement
            for (var i = 0; i < counterTail; i++) snakePosition[i] = snake[i].position;
            
            if ((framesCounter%5) == 0)
            {
                for (var i = 0; i < counterTail; i++)
                {
                    if (i == 0)
                    {
                        snake[0].position.x += snake[0].speed.x;
                        snake[0].position.y += snake[0].speed.y;
                        allowMove = true;
                    }
                    else snake[i].position = snakePosition[i-1];
                }
            }

            // Wall behaviour
            if (((snake[0].position.x) > (screenWidth - offset.x)) || 
                ((snake[0].position.y) > (screenHeight - offset.y)) ||
                (snake[0].position.x < 0) || (snake[0].position.y < 0))
            {
                gameOver = true;
            }

            // Collision with yourself
            for (var i = 1; i < counterTail; i++)
            {
                if ((snake[0].position.x == snake[i].position.x) && (snake[0].position.y == snake[i].position.y)) gameOver = true;
            }

            // Fruit position calculation
            if (!fruit.active)
            {
                fruit.active = true;
                fruit.position = new Vector2(GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2);

                for (var i = 0; i < counterTail; i++)
                {
                    while ((fruit.position.x == snake[i].position.x) && (fruit.position.y == snake[i].position.y))
                    {
                        fruit.position = new Vector2(GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2);
                        i = 0;
                    }
                }
            }

            // Collision
            if ((snake[0].position.x < (fruit.position.x + fruit.size.x) && (snake[0].position.x + snake[0].size.x) > fruit.position.x) &&
                (snake[0].position.y < (fruit.position.y + fruit.size.y) && (snake[0].position.y + snake[0].size.y) > fruit.position.y))
            {
                snake[counterTail].position = snakePosition[counterTail - 1];
                counterTail += 1;
                fruit.active = false;
            }

            framesCounter++;
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
            // Draw grid lines
            for (var i = 0; i < screenWidth/SQUARE_SIZE + 1; i++)
            {
                DrawLineV(new Vector2(SQUARE_SIZE*i + offset.x/2, offset.y/2), new Vector2(SQUARE_SIZE*i + offset.x/2, screenHeight - offset.y/2), LIGHTGRAY);
            }

            for (var i = 0; i < screenHeight/SQUARE_SIZE + 1; i++)
            {
                DrawLineV(new Vector2(offset.x/2, SQUARE_SIZE*i + offset.y/2), new Vector2(screenWidth - offset.x/2, SQUARE_SIZE*i + offset.y/2), LIGHTGRAY);
            }

            // Draw snake
            for (var i = 0; i < counterTail; i++) DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);

            // Draw fruit to pick
            DrawRectangleV(fruit.position, fruit.size, fruit.color);

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
