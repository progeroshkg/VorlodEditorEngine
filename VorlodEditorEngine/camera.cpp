#include "camera.h"
#include <cstdio> // ƒл€ функции printf

Camera::Camera(int startX, int startY, int cameraSpeed) : x(startX), y(startY), speed(cameraSpeed) {}

void Camera::move(int deltaX, int deltaY) {
    x += deltaX;
    y += deltaY;
}

void Camera::rotate(int mouseX, int mouseY) {
    // ¬ычисл€ем угол между текущим положением камеры и положением мыши
    double angle = std::atan2(mouseY - y, mouseX - x);

    // ¬озможно, вам нужно выполнить какие-то дополнительные действи€ с этим углом,
    // например, преобразовать его в градусы или применить его к камере.
    // «десь просто выводим угол дл€ примера.
    printf("Angle: %f\n", angle);
}

int Camera::getX() const {
    return x;
}

int Camera::getY() const {
    return y;
}
