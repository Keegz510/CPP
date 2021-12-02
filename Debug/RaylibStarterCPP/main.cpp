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
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "DataFile.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    DataFile data;
    int currentRecordIdx = 0;

    data.Load("npc_data.dat");

    // Gets the data record we want to load
    DataFile::Record* currentRecord = data.GetRecord(currentRecordIdx);
    // Loads the texture for the data record above
    Texture2D recordTexture = LoadTextureFromImage(currentRecord->image);


    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // === KEY PRESS LEFT === //
        if (IsKeyPressed(KEY_LEFT))
        {
            currentRecordIdx--;                 // Decrease the recorr
            
            // Ensure we stay within the bounds of the data files
            if (currentRecordIdx < 0) currentRecordIdx = 0;
            
            // Get the new record
            currentRecord = data.GetRecord(currentRecordIdx);
            // Load the texture for the new record
            recordTexture = LoadTextureFromImage(currentRecord->image);
        }

        // === KEY PRESS RIGHT === //
        if (IsKeyPressed(KEY_RIGHT))
        {
            if(currentRecordIdx + 1 < data.GetRecordCount())
                currentRecordIdx++;         // Increment the record

            // Ensure we stay within the bounds of the data file
            if (currentRecordIdx >= data.GetRecordCount())
            {
                currentRecordIdx = data.GetRecordCount();
            }

            // Get the new record
            currentRecord = data.GetRecord(currentRecordIdx);
            // Update the texture that we are displaying
            recordTexture = LoadTextureFromImage(currentRecord->image);
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw the current loaded texture
        DrawTexture(recordTexture, 300, 50, WHITE);

        // Draw the name of the load data
        DrawText("NAME", 10, 50, 20, LIGHTGRAY);
        DrawText(currentRecord->name.c_str(), 10, 80, 20, LIGHTGRAY);

        // Draw the age of the load data
        DrawText("AGE", 10, 120, 20, LIGHTGRAY);
        DrawText(to_string(currentRecord->age).c_str(), 10, 150, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}