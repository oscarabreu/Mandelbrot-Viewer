#include <SDL2/SDL.h>
#include <numeric>
#include <complex>

int in_Mandelbrot(std::complex<double> c) {
    std::complex<double> z (0,0);
    for (int i = 0; i < 25; i++) {
        z = std::pow(z,2) + c;
        if (std::norm(z) > 10) {
            return i; 
        }
    }
    return 0;
}


// int main() {
//     SDL_Init(SDL_INIT_EVERYTHING);
//     SDL_Window* window = nullptr;
//     SDL_Renderer* renderer = nullptr;
//     SDL_CreateWindowAndRenderer(2000,2000,0, &window, &renderer);
//     SDL_RenderSetScale(renderer,2,2);

//     for(double x = 0.0; x < 1.0; x += 0.001) {
//         for (double y = 0.0; y < 1.0; y += 0.001) {
//             double point_x = std::lerp(-2.0, 2.0, x);
//             double point_y = std::lerp(-2.0, 2.0, y);
//             int iters = in_Mandelbrot(std::complex<double>(point_x, point_y));
//             if (iters == 0) {
//                 SDL_SetRenderDrawColor(renderer, 0,0,0,255);
//                 SDL_RenderDrawPointF(renderer, x*1000, y*1000);
//             } else {
//                 SDL_SetRenderDrawColor(renderer, 3*iters%255, 3*iters%255, 3*iters%255,255);
//                 SDL_RenderDrawPointF(renderer, x*1000, y*1000);
//             }
//         }
//     }

//     SDL_RenderPresent(renderer);
//     SDL_Delay(100000);
// }


int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Set to red
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    
    SDL_Delay(5000); // Wait for 5 seconds

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}