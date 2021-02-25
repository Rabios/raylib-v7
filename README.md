<div align="center">
  <img src="raylib-v7.png" width="256", height="256"><br>
  <p>JavaScript 5.1 bindings for <a href="https://raylib.com">raylib</a> powered by <a href="https://github.com/cesanta/v7">v7 JavaScript engine</a>!</p>
</div>
<br>

### Build and Usage

The bindings written fully in C, And it's contain following modules:

1. raylib
2. raymath
3. easings
4. rlgl
5. raygui
6. physac
7. rlights
8. rnet (Will be available once [raysan5](https://github.com/raysan5) reviews rnet.h)

raylib-v7 by default uses CMake as primary build system, And uses v7 as it's JavaScript engine implementing JavaScript 5.1 standards

```
git clone https://github.com/Rabios/raylib-v7
cd raylib-v7
cmake -B build

# If you are on Windows, You could build generated solution of raylib-v7 bu CMake with Visual Studio (It works!)
# In case you don't use Visual Studio, make!
cd build
make
```

> By the way, You could get ready-built binaries for Microsoft Windows from releases (If you're on Linux please submit built binaries via issue/pull request)

### Implementation notes

1. `TextFormat` or `FormatText` function only takes 2 arguments, If you want more arguments concat string and variables with `+` instead of using both of the functions.
2. `SetTraceLogCallback` takes callback function, And it's not tested!
3. Issues are welcome, As most stuff (Functions) untested!
4. There are currently some performance bottlenecks when working with big stuff, I don't currently consider using this as turn-key solution for building games!

### Coding

> v7 by the way implements JavaScript 5.1 (Old JavaScript), That means some keywords won't be available like `const` and `else if`, And some of those modern keywords... 

Enjoy coding with JavaScript!

```js
/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
;(function() {
    // Initialization
    //--------------------------------------------------------------------------------------
    var screenWidth = 800;
    var screenHeight = 450;
	
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	
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
		
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
})();
```

Once finished, Run `raylib-v7 --run core_basic_window.js`

### CLI

Command line is provided within raylib-v7's executable, Here is brief overview of what it currently has...

```
raylib-v7 USAGE:

raylib-v7 --run/-r [file]         Runs JavaScript file
raylib-v7 --rundir/-d [dir]       Runs directory of project containing main.js
raylib-v7 --version/-v            Prints used raylib version
raylib-v7 --eval/-e [code]        Evals JavaScript code (And executes it)
raylib-v7 --compile/-c [file]     Builds executable of your JavaScript code
raylib-v7 --help/-h               Shows help for using raylib-v7
```

### What uses?

1. [raylib (Including easings, rlgl, raymath, And rlights)](https://github.com/raysan5/raylib)
2. [raygui](https://github.com/raysan5/raygui)
3. [physac](https://github.com/victorfisac/physac)
4. [v7](https://github.com/cesanta/v7)
5. Modified version of [SasLuca/raylib-cmake-template](https://github.com/SasLuca/raylib-cmake-template)

### Special Thanks

1. [Astie Teddy (@TSnake41)](https://github.com/TSnake41) for helping me with some stuff, And for working on the executable builder!
2. [Ramon Santamaria (@raysan5)](https://github.com/raysan5) for [raylib](https://www.raylib.com)!
3. [Luca Sas (@SasLuca)](https://github.com/SasLuca) for the [raylib CMake template](https://github.com/SasLuca/raylib-cmake-template)!

### Licenses

Following v7 license, raylib-v7 licensed under GNU GPL v2 license!

### TODO

These are list of next TODOs

- [ ] Fix performance bottlenecks...