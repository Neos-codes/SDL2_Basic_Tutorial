#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

// Tutorial de tiempo transcurrido y deltaTime

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

void Load_Explosion_Sprites(SDL_Surface **expl);

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

    // Timing
    float frameTime = 0;
    int lastTime = 0;
    int actualTime = 0;
    float deltaTime = 0;

    float cdAtk_enemigo = 0;

    int frames = 0;



    // Obtener superficie de la ventana
    SDL_Surface *s = SDL_GetWindowSurface(w);

    // Imagenes
    SDL_Surface *cruiser = SDL_LoadBMP("images/cruiser_gr.bmp");
    SDL_Surface **explosion = (SDL_Surface **)malloc(8 * sizeof(SDL_Surface *));    // Arreglo dinamico de Surfaces
    Load_Explosion_Sprites(explosion);

    // Para input y eventos
    SDL_Event e;
    int running = TRUE;

    // ----- Objetos de juego
    // Barco
    SDL_Rect pos;
    pos.x = 50;
    pos.y = 50;
    // Explosion
    SDL_Rect expl_pos;
    expl_pos.x = 100;
    expl_pos.y = 100;
    int expl_index = 0;


    // Background
    SDL_Rect background;

    // Loop de juego
    while(running){

        lastTime = actualTime;                            // ----- NUEVO
        actualTime = SDL_GetTicks();   //en ms
        deltaTime = (actualTime - lastTime) / 1000.0;


        while(SDL_PollEvent(&e) != 0){
            // Cerrar ventana con X
            if(e.type == SDL_QUIT)
                running = FALSE;
            else if(e.type == SDL_KEYDOWN){  // Si el evento es de apretar una tecla
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

        if(frameTime >= 0.016){    // Cada 60 FPS
            frameTime = 0;
            frames++;
            // Animacion de explosion
            if(frames % 8 == 0){
                expl_index++;
                if(expl_index > 7)
                    expl_index = 0;
            }
            if(frames == 60)
                frames = 0;
        }

        // Mostrar imagenes en pantalla
        SDL_FillRect(s, NULL, SDL_MapRGB(s -> format, 255, 0, 0));
        SDL_BlitSurface(cruiser, NULL, s, &pos);
        // Explosion
        SDL_BlitSurface(explosion[expl_index], NULL, s, &expl_pos);

        // Actualizar superficie de la ventana
        SDL_UpdateWindowSurface(w);
    }

    // Al terminar programa
    SDL_FreeSurface(cruiser);
    SDL_DestroyWindow(w);
    SDL_Quit();

    return 0;
}

void Load_Explosion_Sprites(SDL_Surface **expl){
    // Cargar imagenes de explosion
    expl[0] = SDL_LoadBMP("images/1.bmp");
    expl[1] = SDL_LoadBMP("images/2.bmp");
    expl[2] = SDL_LoadBMP("images/3.bmp");
    expl[3] = SDL_LoadBMP("images/4.bmp");
    expl[4] = SDL_LoadBMP("images/5.bmp");
    expl[5] = SDL_LoadBMP("images/6.bmp");
    expl[6] = SDL_LoadBMP("images/7.bmp");
    expl[7] = SDL_LoadBMP("images/8.bmp");

    // Setear celeste como "Key"
    for(int i = 0; i < 8; i++){
        SDL_SetColorKey(expl[i], SDL_TRUE, SDL_MapRGB(expl[i] -> format, 0, 255, 255));
    }
}