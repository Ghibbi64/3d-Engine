#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include <unistd.h>
using namespace std;

void drawLine(int x1, int y1, int x2, int y2);
void setCursor(int x, int y);
void scambiaInt(int* a, int* b);

void drawLine(int x1, int y1, int x2, int y2){
    if(x1>x2){
        scambiaInt(&x1, &x2);
        scambiaInt(&y1, &y2);
        cout<<"scambiati\n";
    }
    int h, l;
    int direction;
    float m = float((y2-y1))/float((x2-x1)); //SE POSITIVA, VA SOTTO, SE NEGATIVA, VA SOPRA
    float b = y1 - (m*x1); //b
    l = x2-x1+1;
    if(m<=0){
        if(m<-1) 
            direction = 1; //linea in y
        else
            direction = 2; //linea in x

        h = y1-y2+1;
    }else{
        if(m>1) 
            direction = 1; //linea in y
        else
            direction = 2; //linea in x

        h = y2-y1+1;
    }
    //cout<<"DATI: "<<"h: "<<h<<" l: "<<l<<" m: "<<m<<"\n";
    //y = m*x + b
    //x = (y-b) / m
    //cout<<direction<<"\n";

    if(direction==2){
        for(int i=0; i<l; i++){
            setCursor(i+x1, int((m*(i+x1)+b)));
            cout<<"#";
        }
    }
    if(direction==1){
        for(int i=0; i<h; i++){
            if(y1<y2)
                setCursor(int(((i+y1)-b))/m, i+y1);
            else
                setCursor(int(((-i+y1)-b))/m, -i+y1);

            cout<<"#";
        }
    }
}
    

void setCursor(int x, int y){
    printf("%c[%d;%df",0x1B,y,x);
}

void scambiaInt(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}