// light.cpp
#include "light.h"

Sun::Sun(int x, int y, float intensity) : m_x(x), m_y(y), m_intensity(intensity), m_animSpeed(0.1f) {}

void Sun::setPosition(int x, int y) {
    m_x = x;
    m_y = y;
}

void Sun::setIntensity(float intensity) {
    m_intensity = intensity;
}

void Sun::update() {
    // Пример анимации: изменяем интенсивность солнца с течением времени
    m_intensity += m_animSpeed; // Просто увеличиваем интенсивность на фиксированную скорость
    // Здесь вы можете добавить логику для более сложной анимации
}

int Sun::getX() const {
    return m_x;
}

int Sun::getY() const {
    return m_y;
}

float Sun::getIntensity() const {
    return m_intensity;
}
