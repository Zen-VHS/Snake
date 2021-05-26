#include <iostream>

using namespace std;

bool gameOver;
const int width = 20;
const int heigh = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;


void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = heigh / 2;
    fruitX = rand() % width;
    fruitX = rand() % heigh;

}

void Draw() {
    system("cls"); // system ("clear");
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < heigh; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                cout << "#";
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;
}

void Input() {

}

void Logic() {

}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }

    return 0;
}
