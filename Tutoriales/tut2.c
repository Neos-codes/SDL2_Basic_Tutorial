#include <SDL2/SDL.h>
#include <stdio.h>

// Tutorial para activar botón "X" y cerrar la ventana


// Resolucion
#define WIDTH 800
#define HEIGHT 600
// Booleanos
#define TRUE 1
#define FALSE 0

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

    // Para input y eventos
    SDL_Event e;
    int running = TRUE;

    // Loop de juego
    while(running){

        while(SDL_PollEvent(&e) != 0){
            // Cerrar ventana con X
            if(e.type == SDL_QUIT)   // Si el evento es de tipo "SDL_QUIT", termina el while
                running = FALSE;
        }

        // Actualizar superficie de la ventana
        SDL_UpdateWindowSurface(w);
    }

    // Al terminar programa
    SDL_DestroyWindow(w);
    SDL_Quit();

    return 0;
}