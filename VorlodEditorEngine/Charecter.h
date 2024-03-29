#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
    float posX;
    float posY;
    float velocityX;
    float velocityY;
    float gravity;
    float jumpForce;
    bool isJumping;

public:
    Character(float x, float y);
    void update(float deltaTime);
    void jump();
    void setPosition(float x, float y);
    float getX();
    float getY();
};

#endif // CHARACTER_H
