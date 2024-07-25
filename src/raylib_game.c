#include "raylib.h"

#define SNAKESPEED 64

void DrawSnake(Vector2 Position,char SnakeArr[], int snakeLength) {

}



int main (void) {

    InitWindow(800,450,"Game Window");
    SetTargetFPS(144);

    int Case = 1 ;

    int timer = 0 ;

    int direction = 0; // 0 == RIGHT --- 1 == DOWN --- 2 == LEFT --- 3 == UP
    Vector2 Position = {GetScreenWidth()/2,GetScreenHeight()/2};
    const Vector2 Size = {25,25};


    int PositionArray[32][18];

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (Case) {
            case 0:
            break;

            case 1:


                                //--------------------------    DRAW POSITION    --------------------------------


            Position.x = (int)(Position.x / 25 ) * 25;
            Position.y = (int)(Position.y / 25 ) * 25;
            DrawRectangleV(Position,Size,BLUE);

            timer++;
            if (timer > SNAKESPEED) {
                switch (direction) {
                    case 0: Position.x+= 25;
                    break;

                    case 1: Position.y+= 25;
                    break;

                    case 2: Position.x -= 25;
                    break;

                    case 3: Position.y -= 25;
                    break;

                    default:
                        break;
                }
                timer = 0;
            }

            //--------------------------    DRAW POSITION END   --------------------------------



            //--------------------------    SNAKE MOVEMENT    --------------------------------

            // 0 == RIGHT --- 1 == DOWN --- 2 == LEFT --- 3 == UP

            if (IsKeyDown(KEY_A))
                direction = direction == 0 ? 0 : 2 ;

            if (IsKeyDown(KEY_D))
                direction = direction == 2 ? 2 : 0 ;

            if (IsKeyDown(KEY_W))
                direction = direction == 1 ? 1 : 3 ;

            if (IsKeyDown(KEY_S))
                direction = direction == 3 ? 3 : 1 ;

            //--------------------------    SNAKE MOVEMENT END    --------------------------------

            //--------------------------    DEATH CONTROL    --------------------------------

            // CORNERS AND SIDES
            if (Position.x / 25 > 32 || Position.x / 25 < 0 || Position.y / 25 > 18 || Position.y / 25 < 0)
                Case = 2;


            //--------------------------    DEATH CONTROL END    --------------------------------

        break;

            case 2:
            DrawText("YOU DEAD",300,350,40,BLACK);
            break;


            default:
                break;

        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
