#pragma once

#include <SDL.h>

// ����������� ���� ������� ��������� ������ ��� �������� �����
typedef void(*FolderCreationCallback)();

// ��������� ������� ��������� ������ ��� �������� �����
void setContentBrowserCallback(FolderCreationCallback callback);

// ��������� ������ ������ ������� ����
void handleRightMouseClick(SDL_Event& event);
