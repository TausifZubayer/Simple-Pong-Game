#include<iostream>
using namespace std;

enum eDir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall{
private:
    int x, y;
    int originalX, originalY;
    eDir direction;

public:
    cBall(int, int);
    void Reset();
    void changeDirection(eDir);
    void randomDirection();
    void Move();
    friend ostream& operator<<(ostream&, cBall);

    inline int getX(){

        return x;

    }

    inline int getY(){

        return y;

    }

    inline eDir getDirection(){

        return direction;

    }
};
