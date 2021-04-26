/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = nullptr;

//The image we will load and show on the screen
SDL_Surface* mainScreen = nullptr;

bool handleSdlInitError(const char * error) {
    std::cout << "SDL could not initialize! SDL_Error: " << error << std::endl;
    return false;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        success = handleSdlInitError(SDL_GetError());
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow(
                "SDL Tutorial",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
        );
        if ( gWindow == nullptr )
        {
            success = handleSdlInitError(SDL_GetError());
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;

}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    const char * imgPath = "game.bmp";
    mainScreen = SDL_LoadBMP(imgPath );
    if (mainScreen == nullptr )
    {
        std::cout << "Unable to load image " << imgPath << "SDL_Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(mainScreen );
    mainScreen = nullptr;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			std::cout << "Failed to load media!" << std::endl;
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(mainScreen, nullptr, gScreenSurface, nullptr );
			
			//Update the surface
			SDL_UpdateWindowSurface( gWindow );

			//Wait two seconds
			SDL_Delay( 2000 );
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}