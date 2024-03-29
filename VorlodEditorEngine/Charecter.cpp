#include "Charecter.h"

Character::Character(float x, float y) {
    posX = x;
    posY = y;
    velocityX = 0.0f;
    velocityY = 0.0f;
    gravity = 9.8f; // Земное ускорение
    jumpForce = 10.0f;
    isJumping = false;
}

void Character::update(float deltaTime) {
    // Применяем гравитацию
    velocityY += gravity * deltaTime;
    posY += velocityY * deltaTime;
    // Обновляем позицию персонажа
    posX += velocityX * deltaTime;
}

void Character::jump() {
    if (!isJumping) {
        velocityY = -jumpForce;
        isJumping = true;
    }
}

void Character::setPosition(float x, float y) {
    posX = x;
    posY = y;
}

float Character::getX() {
    return posX;
}

float Character::getY() {
    return posY;
}
