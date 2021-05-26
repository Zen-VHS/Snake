#include <iostream>
#include <conio.h> // автономно отслеживает нажатия
#include <windows.h>//перемещения курсора в консоли, Sleep
#include <stdlib.h>
#include <time.h>

using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail; // колличесто эллементов хвоста
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup() {
    gameOver = false;
    srand(time(NULL) + 1);
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;

}

void Draw() {
    Sleep(100);
    system("cls"); // system ("clear");
    for (int i = 0; i < width + 1; i++) // рисует верхнюю границу
        cout << "=";
    cout << endl;

    for (int i = 0; i < height; i++) { // рисует границы по бокам
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                cout << "|";
            if (i == y && j == x)
                cout << "Q";
            else if (i == fruitY && j == fruitX)
                cout << "$";
            else {
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i)
                        cout << "o";
                }
                    cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++) // рисует нижнюю границу
        cout << "=";
    cout << endl;
    cout << "Score: " << score << endl; // счетчик очков
}

void Input() {
    if (_kbhit()) {
        switch (_getch ())
        {
        case 'a':
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    //if ( x > width || x < 0 || y > height || y < 0)
    //    gameOver = true;
    if (x >= width) {
        x = 0;
    }
    else if (x < 0) {
        x = width - 2;
    }
    if (y >= height) {
        y = 0;
    }
    else if (y < 0) {
        y = height - 1;
    }
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
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
