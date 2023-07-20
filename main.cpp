#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "menus.hpp"
#include "game.hpp"

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
    SDL_SetWindowTitle(window, "FUN GAME"); // Change title here
    SDL_RenderPresent( renderer );
    SDL_Event windowEvent;

    
    if (NULL == window) {
        std::cout << "Could not create Window: " << SDL_GetError() << std::endl;
        return 1;
    }

    bool looping = true;
    string screen = "splash";
    Menus mainMenu;
    mainMenu.menusInit(window, renderer, windowEvent);

    while (looping){
        while (SDL_PollEvent( &windowEvent) != 0){
            if( windowEvent.type == SDL_QUIT ){
                SDL_DestroyRenderer(renderer);    
                SDL_DestroyWindow (window);
                SDL_Quit();
                return EXIT_SUCCESS;
            }}
        
        if (screen == "splash")
            screen = mainMenu.splash();
        else if (screen == "menu")
            screen = "menu_screen()";
        else if (screen == "game")
            screen = mainMenu.game_screen(); // in menu create a game sectoion to init
        else if (screen == "game_over")
            screen = "game_over_screen()"; // todo add gameOver
        else if (screen == "instructions")
            screen = "instructions_screen()";  //todo add instructions
        else if (screen == "quit")
            break;
        else
            screen = "goodbye_screen()"; // todo add goodbye 

    }

    SDL_DestroyRenderer(renderer);    
    SDL_DestroyWindow (window);
    SDL_Quit();
    return EXIT_SUCCESS;
}