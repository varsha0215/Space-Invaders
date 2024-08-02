#include "raylib.h"
#include "Game.hpp"
#include <string>
std::string FormatWithLeadingZeroes(int number,int width){
      std::string numberText = std::to_string(number);
        int leadingZeroes = width - numberText.length();
        return numberText = std::string(leadingZeroes,'0')+numberText;

}
int main(){
    
    Color grey = {29,29,27,255};
    Color yellow = {243,216,63,255};
    //Creating game window
    int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;
    InitAudioDevice();
    InitWindow(windowWidth + offset, windowHeight + 2*offset, "Space Invaders");
    Font font = LoadFontEx("Font/BebasNeue-Regular.ttf",64,0,0);
    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");
    SetTargetFPS(60);
    
    Game game;
    


    
    //Game loop->1)Event Handling ->2)Updating Pos ->3)Drawing Objects
    while(WindowShouldClose() == false){
        UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();

        BeginDrawing();//Creates blank canvas
        ClearBackground(grey);
        DrawRectangleRoundedLines({10,10,780,780},0.18f,20,2,yellow);
        DrawLineEx({25,730},{775,730},3,yellow);
        
        if(game.run){
                    DrawTextEx(font,"LEVEL 01",{570,740},34,2,yellow);
        }else{
                    DrawTextEx(font,"GAME OVER",{570,740},34,2,yellow);
        }
        float x = 50.0;
        for(int i=0;i<game.lives;i++){
            DrawTextureV(spaceshipImage,{x,745},WHITE);
            x+=50;
        }
        DrawTextEx(font,"SCORE",{50,15},34,2,yellow);
        std::string scoreText = FormatWithLeadingZeroes(game.score,5);
        DrawTextEx(font,scoreText.c_str(),{50,40},34,2,yellow);
        

        DrawTextEx(font,"HIGH-SCORE",{570,15},34,2,yellow);
        std::string highscoreText = FormatWithLeadingZeroes(game.highscore,5);
        DrawTextEx(font,highscoreText.c_str(),{625,40},34,2,yellow);
        game.Draw();
        
        EndDrawing();

    }
    
    CloseWindow();
    CloseAudioDevice();
    
    
}