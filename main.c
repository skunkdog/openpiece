#include <stdio.h>
#include <raylib.h>

int main(int argc, char* argv[])
{
    // Initialization
  
    const int WIDTH = 800;
    const int HEIGHT = 450;
    const int FPS = 60;
    
    SetExitKey(81);
    SetTargetFPS(FPS);

    const int CLICKEDOFSET = 10;
    
    int CenterButtonState = 0;
    InitWindow(WIDTH, HEIGHT, "wayland dont touch my screen");
    InitAudioDevice();

    if (IsAudioDeviceReady() == 0  || IsWindowReady() == 0){
      return 1;
	}
    
    float MasterVolume = GetMasterVolume();
    Sound Music = LoadSound(argv[1]);
    if (IsSoundValid(Music) == 0){
      printf("\033[31mSomething wrong with loading file.\nCheck the directory name.\n\033[0m");
      return 1;
    }
    PlaySound(Music);
    if (IsSoundPlaying(Music) == 1){
      printf("\033[31mPlaying music.\n\033[0m");
    }
    
    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
      SetWindowState(0x00000004);
      BeginDrawing();

      ClearBackground(BLACK);
      float CenterX = WIDTH / 2;
      float CenterY = HEIGHT / 2;
      float RecX = 90;
      float RecY = 90;
      
      Vector2 RecSize= {
	RecX,
	RecY,
      };
      Vector2 RecSizeClicked = {
	RecX - CLICKEDOFSET,
	RecY - CLICKEDOFSET,
      };
      Vector2 RecPos = {
	CenterX - (RecX/2),
	CenterY - (RecY/2),
      };
      Vector2 RecPosClicked = {
	CenterX - ( (RecX - CLICKEDOFSET) / 2),
	CenterY - ( (RecY - CLICKEDOFSET) / 2),
      };

      if (IsKeyPressed(32) == 1)
	{
	  CenterButtonState++;
	  if (CenterButtonState > 1)
	    {
	      CenterButtonState = 0;
	    }
	}
      if (CenterButtonState == 1){	
	DrawRectangleV(RecPosClicked, RecSizeClicked, BEIGE); // DRAWS RECTANGLE
	PauseSound(Music);
      }
      else{
	DrawRectangleV(RecPos, RecSize, RAYWHITE);
	ResumeSound(Music);
      }
      
      EndDrawing();
    }

    CloseWindow();
    return 0;
}
