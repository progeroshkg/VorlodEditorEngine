#include <SDL.h>
#include <SDL_ttf.h>
#include "object.h" // Подключаем заголовочный файл с классом Object
#include "light.h" // Подключаем заголовочный файл с классом Sun
#include <stdio.h>
#include "contentBruser.h"
#include <vector>
#include <string>


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int BUTTON_MARGIN = 10;
const int BUTTON_WIDTH = 100;
const int BUTTON_HEIGHT = 50;
const int BROWSER_HEIGHT = 200;

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* text, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void createFolder() {
    printf("Creating folder...\n");
    // Здесь добавьте код для создания папки
}

void renderButton(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y, int width, int height) {
    SDL_Color textColor = { 255, 255, 255 };
    SDL_Texture* texture = loadTexture(renderer, text, font, textColor);

    SDL_Rect buttonRect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // Gray color
    SDL_RenderFillRect(renderer, &buttonRect);

    SDL_Rect textRect = { x + width / 2 - 25, y + height / 2 - 10, 50, 20 }; // Adjust text position
    SDL_RenderCopy(renderer, texture, NULL, &textRect);

    SDL_DestroyTexture(texture);
}

void renderMenu(SDL_Renderer* renderer, TTF_Font* font) {
    // Render the menu
    renderButton(renderer, font, "New Project", BUTTON_MARGIN, 5, BUTTON_WIDTH, BUTTON_HEIGHT);
    renderButton(renderer, font, "Build", BUTTON_MARGIN * 2 + BUTTON_WIDTH, 5, BUTTON_WIDTH, BUTTON_HEIGHT);
    renderButton(renderer, font, "Test", BUTTON_MARGIN * 3 + BUTTON_WIDTH * 2, 5, BUTTON_WIDTH, BUTTON_HEIGHT);
}

void renderBrowser(SDL_Renderer* renderer) {
    // Render the content browser
    SDL_Rect browserRect = { 0, WINDOW_HEIGHT - BROWSER_HEIGHT, WINDOW_WIDTH, BROWSER_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); // Dark gray color
    SDL_RenderFillRect(renderer, &browserRect);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 1;
    }
    Object player(100, 100);
    Object enemy(200, 200);

    // Пример использования объектов
    player.setPosition(150, 150);

    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "VorlodEditorEngine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    setContentBrowserCallback(createFolder);

    // Создаем объект солнца
    Sun sun(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4, 0.8);

    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            handleRightMouseClick(e); // Обработка событий мыши в контент-браузере
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear screen
        SDL_RenderClear(renderer);

        // Рендеринг солнца
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow color
        SDL_Rect sunRect = { sun.getX(), sun.getY(), 50, 50 }; // Пример размеров солнца
        SDL_RenderFillRect(renderer, &sunRect);

        renderMenu(renderer, font);
        renderBrowser(renderer);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
