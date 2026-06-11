#include <stdio.h>
#include <raylib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Initialization
  
    const int WIDTH = 400;
    const int HEIGHT = 350;
    const int FPS = 60;

    const char *path = (argc > 1) ? argv[1] : ".";
    ChangeDirectory(path);
    DIR *dir = opendir(path);
    if (!dir){
      perror("opendir");
      return 1;
    }
    printf("%s\n", path);
    struct dirent *c_entry;
    struct dirent *entry;
    int count = 0;
    while ( (c_entry = readdir(dir)) != NULL){
	count++;
      }
    closedir(dir);
    DIR *dir2 = opendir(path);
    readdir(dir2);
    readdir(dir2);
    char *playlist[count] = {};
    for (int i = 0; i < count; i++){
      entry = readdir(dir2);
      if (entry == NULL){
	break;
      }
      playlist[i] = entry->d_name;
    }
    
    
    SetTraceLogLevel(LOG_NONE);
    InitWindow(WIDTH, HEIGHT, "Openpiece-stripped"); //Initialise window
    InitAudioDevice(); //Initialise audio device
    
    SetTargetFPS(FPS); //Sets max FPS
    int CenterButtonState = 0;
    if (IsWindowReady() == 0){  //Checks window works properly
      perror("IsWindowReady");
      return 1;
    }
    if (IsAudioDeviceReady() == 0){ //Checks audio device works properly
      perror("IsAudioDeviceReady");
      return 1;
    }

    printf("After Checks\n");
    Sound Music = LoadSound(playlist[3]);
    PlaySound(Music);
    
    
    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
           SetExitKey(81);    // Set exit key to q
      SetWindowState(0x00000004); //Make window movable

      BeginDrawing(); //Start drawing part

      ClearBackground(BLACK); //Set black background

      if (IsKeyPressed(32) == 1) // If space pressed cycle through pause and unpause
	{
	  CenterButtonState++;
	  if (CenterButtonState > 1)
	    {
	      CenterButtonState = 0;
	    }
	}
      if (CenterButtonState == 1){	
	//PauseSound(Music);
      }
      else{
	//	ResumeSound(Music);
      }
      
      EndDrawing(); //Stops drawing 
    }
    
    CloseWindow();
    return 0;
}
