#include "cPaddle.h"

cPaddle::cPaddle() {
    x =0;
    y = 0;
}

cPaddle::cPaddle(int posX, int posY):cPaddle() {
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
}

ostream& operator<<(ostream& o, cPaddle c){

    o << "Paddle [" << c.x << "," << c.y << "]";
    return o;
}
