#include <SDL2/SDL.h>
#include <stdio.h>


// Tutorial para mover un barco por la pantalla


// Resolucion
#define WIDTH 800
#define HEIGHT 600
// Booleanos
#define TRUE 1
#define FALSE 0

typedef struct{
    int x;
    int y;
}Ship;

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

    // Obtener superficie de la ventana
    SDL_Surface *s = SDL_GetWindowSurface(w);

    // Imagenes
    SDL_Surface *cruiser = SDL_LoadBMP("images/cruiser_gr.bmp");

    // Para input y eventos
    SDL_Event e;
    int running = TRUE;

    // Objetos de juego
    SDL_Rect pos;
    pos.x = 50;
    pos.y = 50;

    // Background
    SDL_Rect background;

    // Loop de juego
    while(running){

        while(SDL_PollEvent(&e) != 0){
            // Cerrar ventana con X
            if(e.type == SDL_QUIT)
                running = FALSE;
            else if(e.type == SDL_KEYDOWN){   // Si el evento es de apretar una tecla
                switch(e.key.keysym.sym){
                    case SDLK_UP:
                        pos.y -= 1;
                        break;
                    case SDLK_DOWN:
                        pos.y += 1;
                        break;
                    case SDLK_RIGHT:
                        pos.x += 1;
                        break;
                    case SDLK_LEFT:
                        pos.x -= 1;
                        break;
                }
            }
        }

        // Mostrar imagenes en pantalla
        SDL_FillRect(s, NULL, SDL_MapRGB(s -> format, 255, 0, 0));
        SDL_BlitSurface(cruiser, NULL, s, &pos);

        // Actualizar superficie de la ventana
        SDL_UpdateWindowSurface(w);
    }

    // Al terminar programa
    SDL_FreeSurface(cruiser);
    SDL_DestroyWindow(w);
    SDL_Quit();

    return 0;
}