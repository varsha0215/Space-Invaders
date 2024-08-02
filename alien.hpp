#pragma once
#include <raylib.h>

class Alien{
    public:
    Alien(int type,Vector2 position);
    void Update(int direction);
    void Draw();
    static void UnloadImages();
    static Texture2D alienImages[3];
    int type;
    int GetType();
    Rectangle getRect();
    Vector2 position;


};