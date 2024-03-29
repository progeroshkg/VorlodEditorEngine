#pragma once
#define CAMERA_H
#include <cmath> // Для использования функции std::atan2()

class Camera {
private:
    int x, y; // Позиция камеры
    int speed; // Скорость перемещения камеры

public:
    Camera(int startX, int startY, int cameraSpeed);
    void move(int deltaX, int deltaY);
    void rotate(int mouseX, int mouseY);
    int getX() const;
    int getY() const;
};