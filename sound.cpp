#include "sound.h"
#include <windows.h>   
#include <mmsystem.h>  

void playSound(const char* filename) {
    
    PlaySound(filename, NULL, SND_ASYNC | SND_FILENAME);
}
