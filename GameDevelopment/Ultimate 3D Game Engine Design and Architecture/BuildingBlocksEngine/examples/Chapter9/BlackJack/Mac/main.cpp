/*
   Simple Black Jack Game Demo - Chapter 9
   Ultimate Game Engine Design and Architecture
   Created by Allen Sherrod
*/


#include<Carbon/Carbon.h>
#include"blackJackOSX.h"


BlackJackGameOSX *g_blackJackGame = NULL;


void UpdateTimer(EventLoopTimerRef timer, void *userData);


int main(int argc, char* argv[])
{
   IBNibRef nibRef;
   OSStatus err;
   WindowRef window;

   // Create a Nib reference passing the name of the nib file.
   err = CreateNibReference(CFSTR("main"), &nibRef);
   require_noerr( err, CantGetNibRef );

   // Once the nib reference is created, set the menu bar.
   err = SetMenuBarFromNib(nibRef, CFSTR("MenuBar"));
   require_noerr( err, CantSetMenuBar );

   // Then create a window.
   err = CreateWindowFromNib(nibRef, CFSTR("MainWindow"), &window);
   require_noerr( err, CantCreateWindow );

   // We don't need the nib reference anymore.
   DisposeNibReference(nibRef);
	
   Rect windowRect;
	
   // Get the window rectangle.
	GetWindowBounds(window, kWindowContentRgn, &windowRect);
    
   // The window was created hidden so show it.
   ShowWindow(window);

   g_blackJackGame = new BlackJackGameOSX(window);

   if(g_blackJackGame == NULL)
      {
         printf("Error creating g_blackJackGame!\n");
         return 0;
      }

   if(g_blackJackGame->GameInitialize() == false)
      {
         printf("Error in initialize!\n");
         delete g_blackJackGame;
         return 0;
      }
   
   g_blackJackGame->Resize(windowRect.right - windowRect.left,
                           windowRect.bottom - windowRect.top);
   
   // Set up a timer to refresh the scene asap.
	InstallEventLoopTimer(GetMainEventLoop(), 0, kEventDurationSecond / 60,
                         NewEventLoopTimerUPP(UpdateTimer), NULL, 0);
    
   // Loop through the application until the user closes through app menu.
   RunApplicationEventLoop();
	
   g_blackJackGame->GameShutdown();
   delete g_blackJackGame;
   g_blackJackGame = NULL;
   
   // Destroy the window.
	DisposeWindow(window);

   CantCreateWindow:
   CantSetMenuBar:
   CantGetNibRef:
	return err;
}


void UpdateTimer(EventLoopTimerRef timer, void *userData)
{
    g_blackJackGame->EnterGameLoop();
}