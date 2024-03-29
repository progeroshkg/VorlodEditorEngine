#include "camera.h"
#include <cstdio> // ��� ������� printf

Camera::Camera(int startX, int startY, int cameraSpeed) : x(startX), y(startY), speed(cameraSpeed) {}

void Camera::move(int deltaX, int deltaY) {
    x += deltaX;
    y += deltaY;
}

void Camera::rotate(int mouseX, int mouseY) {
    // ��������� ���� ����� ������� ���������� ������ � ���������� ����
    double angle = std::atan2(mouseY - y, mouseX - x);

    // ��������, ��� ����� ��������� �����-�� �������������� �������� � ���� �����,
    // ��������, ������������� ��� � ������� ��� ��������� ��� � ������.
    // ����� ������ ������� ���� ��� �������.
    printf("Angle: %f\n", angle);
}

int Camera::getX() const {
    return x;
}

int Camera::getY() const {
    return y;
}
