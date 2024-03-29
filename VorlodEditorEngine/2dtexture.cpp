//#define STB_IMAGE_IMPLEMENTATION
#include "GL/stb_image.h"
#include "2dtexture.h"
#include <iostream>

Texture2D::Texture2D() : m_width(0), m_height(0), m_textureID(0) {
    glGenTextures(1, &m_textureID);
}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &m_textureID);
}
/// <summary>
/// 
/// </summary>
/// <param name="filePath"></param>
/// <returns></returns>

//bool Texture2D::LoadFromFile(const std::string& filePath) {
  //  int channels;
    //int width, height; // временные переменные для хранения ширины и высоты

    //stbi_set_flip_vertically_on_load(true); // перевернуть изображение по вертикали
    //unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
    //if (!data) {
      //  std::cerr << "Failed to load texture: " << filePath << std::endl;
        //return false;
   // }

    // сохраняем ширину и высоту изображения в переменные класса
    //m_width = static_cast<unsigned int>(width);
    //m_height = static_cast<unsigned int>(height);

    //glBindTexture(GL_TEXTURE_2D, m_textureID);

    // настройка параметров текстуры
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //if (channels == 3)
      //  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    //else if (channels == 4)
       // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    //glGenerateMipmap(GL_TEXTURE_2D);

    //stbi_image_free(data);

    //return true;
//}


//void Texture2D::Bind() const {
  //  glBindTexture(GL_TEXTURE_2D, m_textureID);
//}
