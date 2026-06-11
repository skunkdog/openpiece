#include <stdio.h>
#include <raylib.h>

int main(int argc, char* argv[])
{
    // Initialization
  
    const int WIDTH = 400;
    const int HEIGHT = 350;
    const int FPS = 60;
    int CenterButtonState = 0;
    
    SetTargetFPS(FPS);
    
    InitWindow(WIDTH, HEIGHT, "Openpiece-stripped");
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
      SetExitKey(81);    
      SetWindowState(0x00000004);
      BeginDrawing();

      ClearBackground(BLACK);
      
      if (IsKeyPressed(32) == 1)
	{
	  CenterButtonState++;
	  if (CenterButtonState > 1)
	    {
	      CenterButtonState = 0;
	    }
	}
      if (CenterButtonState == 1){	
	PauseSound(Music);
      }
      else{
	ResumeSound(Music);
      }
      EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
