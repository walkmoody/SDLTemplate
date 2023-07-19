#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "rects.hpp"

const int WIDTH = 1080;
const int HEIGHT = 720;
const int FPS = 60; 

//g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

int main( int argc, char *argv[]){
    SDL_Window* window = nullptr; //SDL_CreateWindow("new Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI) ; // change window name here, CHANGE STARTING POS HERE
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* image = nullptr;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    SDL_RenderPresent( renderer );
    if (NULL == window) {
        std::cout << "Could not create Window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;
    bool quit = false;
    Rectangle rect;
    rect.initRectangle();
    
    bool down = false;
    
    while (!quit){
        while (SDL_PollEvent( &windowEvent) != 0){
            if( windowEvent.type == SDL_QUIT ){
                    quit = true;
                }
            SDL_Keycode key = windowEvent.key.keysym.sym;
            if (key == SDLK_1)
                down = true;
           /* if (windowEvent.type == SDL_KEYDOWN){
                //const Uint8* key = SDL_GetKeyboardState(nullptr)
                SDL_Keycode key = windowEvent.key.keysym.sym;
                if (key == SDLK_1)
                    down = true;
            */
            if (windowEvent.type == SDL_KEYUP)
                down = false;
            
        }
        if (down == true){
            rect.setRectangleY(10);
        }
   
        SDL_RenderClear(renderer);
        rect.setRectangleX();
       
        //SDL_RenderCopy( renderer, NULL, NULL, NULL );
        rect.printRect(renderer);
        
        SDL_SetRenderDrawColor (renderer, 255,255,255,255);
        SDL_RenderPresent( renderer );
        //SDL_RenderDrawPoint(renderer, WIDTH/2, HEIGHT/2);     
        SDL_Delay(1000/FPS);      

 
        }

    SDL_DestroyRenderer(renderer);    
    SDL_DestroyWindow (window);
    SDL_Quit();
    return EXIT_SUCCESS;
}