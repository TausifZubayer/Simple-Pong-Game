#include "cGameManager.h"

cGameManager::cGameManager(int w, int h) {
    srand(time(NULL));
    quit = false;
    up1 = 'w';
    up2 = 'i';
    down1 = 's';
    down2 = 'k';
    score1 = score2 = 0;
    width = w;
    height = h;
    ball = new cBall(w/2, h/2);
    player1 = new cPaddle(1, h/2 - 3);
    player2 = new cPaddle(w - 2, h/2 - 3);
}

cGameManager::~cGameManager() {
    delete ball, player1, player2;
}

void cGameManager::scoreUp(cPaddle* player) {
    if(player == player1) {
        score1++;
    } else if(player == player2) {
        score2++;
    }

    ball -> Reset();
    player1 -> Reset();
    player2 -> Reset();
}

void cGameManager::Draw() {
    system("cls");

    for(int i = 0; i < width + 2; i++) {
        cout << "\xB2";
    }

    cout << endl;

    for(int i = 0; i < height; i++) {

        for(int j = 0; j < width; j++) {
            int ballx = ball -> getX();
            int bally = ball -> getY();
            int player1x = player1 -> getX();
            int player2x = player2 -> getX();
            int player1y = player1 -> getY();
            int player2y = player2 -> getY();

            if(j == 0) {
                cout << "\xB2";
            }

            if(ballx == j && bally == i) {
                cout << "O"; //ball
            } else if(player1x == j && player1y == i) {
                cout << "\xDB"; //player 1
            } else if(player2x == j && player2y == i) {
                cout << "\xDB"; //player 2
            } else if(player1x == j && player1y + 1 == i) {
                cout << "\xDB"; //player 1
            } else if(player1x == j && player1y + 2 == i) {
                cout << "\xDB"; //player 1
            } else if(player1x == j && player1y + 3 == i) {
                cout << "\xDB"; //player 1
            } else if(player2x == j && player2y + 1 == i) {
                cout << "\xDB"; //player 2
            } else if(player2x == j && player2y + 2 == i) {
                cout << "\xDB"; //player 2
            } else if(player2x == j && player2y + 3 == i) {
                cout << "\xDB"; //player 2
            } else {
                cout << " ";
            }

            if(j == width - 1) {
                cout << "\xB2";
            }

        }

        cout << endl;

    }

    for(int i = 0; i < width + 2; i++) {
        cout << "\xB2";
    }

    cout << endl;

    cout << "Score 1 : " << score1 << endl;
    cout << "Score 2 : " << score2 << endl;
}

void cGameManager::Input() {
    ball -> Move();

    int ballx = ball -> getX();
    int bally = ball -> getY();
    int player1x = player1 -> getX();
    int player2x = player2 -> getX();
    int player1y = player1 -> getY();
    int player2y = player2 -> getY();

    if(kbhit()) {
        char current = getch();

        if(current == up1) {
            if(player1y > 0) {
                player1 -> moveUp();
            }
        }
        if(current == up2) {
            if(player2y > 0) {
                player2 -> moveUp();
            }
        }
        if(current == down1) {
            if(player1y + 4 < height) {
                player1 -> moveDown();
            }
        }
        if(current == down2) {
            if(player2y + 4 < height) {
                player2 -> moveDown();
            }
        }

        if(ball -> getDirection() == STOP) {
            ball -> randomDirection();
        }

        if(current == 'q') {
            quit = true;
        }

    }
}

void cGameManager::Logic() {

    int ballx = ball -> getX();
    int bally = ball -> getY();
    int player1x = player1 -> getX();
    int player2x = player2 -> getX();
    int player1y = player1 -> getY();
    int player2y = player2 -> getY();

    //left paddle
    for(int i = 0; i < 4; i++) {
        if(ballx == player1x + 1) {
            if(bally == player1y + i) {
                ball -> changeDirection((eDir)((rand() % 3) + 4));
            }
        }
    }

    //right paddle
    for(int i = 0; i < 4; i++) {
        if(ballx == player2x - 1) {
            if(bally == player2y + i) {
                ball -> changeDirection((eDir)((rand() % 3) + 1));
            }
        }
    }

    //bottom wall
    if(bally == height - 1) {
        ball -> changeDirection(ball -> getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
    }

    //top wall
    if(bally == 0) {
        ball -> changeDirection(ball -> getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
    }

    //right wall
    if(ballx == width - 1) {
        scoreUp(player1);
    }

    //left wall
    if(ballx == 0) {
        scoreUp(player2);
    }

}

void cGameManager::Run() {
    while(!quit) {
        Draw();
        Input();
        Logic();
        Sleep(50);
    }
}
