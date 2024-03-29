#pragma once
#include <SDL.h> // Подключаем библиотеку SDL для работы с текстурами

class Object {
public:
    Object(int x, int y) : m_x(x), m_y(y), m_texture1(nullptr), m_texture2(nullptr) {}

    void setPosition(int x, int y) {
        m_x = x;
        m_y = y;
    }

    void setTexture1(SDL_Texture* texture) {
        m_texture1 = texture;
    }

    void setTexture2(SDL_Texture* texture) {
        m_texture2 = texture;
    }

    int getX() const {
        return m_x;
    }

    int getY() const {
        return m_y;
    }

    SDL_Texture* getTexture1() const {
        return m_texture1;
    }

    SDL_Texture* getTexture2() const {
        return m_texture2;
    }

private:
    int m_x;
    int m_y;
    SDL_Texture* m_texture1;
    SDL_Texture* m_texture2;
};
