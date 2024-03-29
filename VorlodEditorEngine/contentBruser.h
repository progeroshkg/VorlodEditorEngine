#pragma once

#include <SDL.h>

// Определение типа функции обратного вызова для создания папки
typedef void(*FolderCreationCallback)();

// Установка функции обратного вызова для создания папки
void setContentBrowserCallback(FolderCreationCallback callback);

// Обработка щелчка правой кнопкой мыши
void handleRightMouseClick(SDL_Event& event);
