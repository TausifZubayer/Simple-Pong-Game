#include<iostream>
using namespace std;

class cPaddle {
private:
    int x, y;
    int originalX, originalY;

public:
    cPaddle();
    cPaddle(int, int);
    friend ostream& operator<<(ostream&, cPaddle);

    inline void Reset() {
        x = originalX;
        y = originalY;
    }

    inline int getX() {
        return x;
    }

    inline int getY() {
        return y;
    }

    inline void moveUp() {
        y--;
    }

    inline void moveDown() {
        y++;
    }
};
