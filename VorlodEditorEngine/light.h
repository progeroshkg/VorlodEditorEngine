// light.h
#pragma once

class Sun {
public:
    Sun(int x, int y, float intensity);

    void setPosition(int x, int y);
    void setIntensity(float intensity);
    void update(); // ��������� ������� ���������� ��������

    int getX() const;
    int getY() const;
    float getIntensity() const;

private:
    int m_x;
    int m_y;
    float m_intensity; // ������������� ���������� �����
    float m_animSpeed; // �������� ��������� ������������� ��������
};
