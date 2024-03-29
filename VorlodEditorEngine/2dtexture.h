#pragma once

#include <string>
#include "GL/glew.h"

class Texture2D {
public:
    Texture2D();
    ~Texture2D();

    bool LoadFromFile(const std::string& filePath);
    void Bind() const;

    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }

private:
    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_textureID;
};
