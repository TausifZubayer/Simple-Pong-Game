#include<iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include "cBall.h"
#include "cPaddle.h"
using namespace std;

class cGameManager {
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall* ball;
    cPaddle* player1;
    cPaddle* player2;

public:
    cGameManager(int, int);
    ~cGameManager();
    void scoreUp(cPaddle*);
    void Draw();
    void Input();
    void Logic();
    void Run();
};
