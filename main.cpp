#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<time.h>
#include"graphic.h"
using namespace std;

int main(){
    
}

void circleTest(){
    const int RADIUS = 30;      // Radius of the circle
    const int CENTER_X = 187;   // X coordinate of the center
    const int CENTER_Y = 45;   // Y coordinate of the center
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