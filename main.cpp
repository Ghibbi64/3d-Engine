#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<time.h>
#include"graphic.h"
using namespace std;

const int RADIUS = 30;      // Radius of the circle
const int CENTER_X = 187;   // X coordinate of the center
const int CENTER_Y = 45;   // Y coordinate of the center
int msleep(long msec);

int main(){
        //int x = CENTER_X + static_cast<int>(RADIUS * cos(angle));
        //int y = CENTER_Y + static_cast<int>(RADIUS * sin(angle));

    int x=0, y=0;
    float angle=0;
    while(true){
        angle += 0.1;
        if(angle==360)
            angle = 0;
            
        x = CENTER_X + static_cast<int>(RADIUS * cos(angle));
        y = CENTER_Y + static_cast<int>(RADIUS * sin(angle));

        drawLine(CENTER_X, CENTER_Y, x, y);
        drawBuffer();
        clearBuffer();
        getchar();
        system("tput reset");
    }
}

int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}