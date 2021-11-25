#include <SDL2/SDL.h>
#include <stdio.h>

// Tutorial para crear una ventana con SDL

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char *args[]){

    // Inicializar SDL2
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error al iniciar SDL2\n");
        return 0;
    }

    // Crear ventana
    SDL_Window *w = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if(w == NULL){
        printf("Error al crear ventana SDL2\n");
        return 0;
    }

    // Actualizar superficie de la ventana
    SDL_UpdateWindowSurface(w);
    SDL_Delay(5000);

    return 0;
}