#include <SDL.h>
#include <stdio.h>
#include "contentBruser.h"

static FolderCreationCallback folderCreationCallback = nullptr;

void setContentBrowserCallback(FolderCreationCallback callback) {
    folderCreationCallback = callback;
}

void handleRightMouseClick(SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_RIGHT && folderCreationCallback != nullptr) {
            printf("Right mouse button clicked in content browser! Creating folder...\n");
            folderCreationCallback(); // Вызываем функцию создания папки
        }
    }
}
