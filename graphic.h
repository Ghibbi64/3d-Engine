#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<unistd.h>
using namespace std;

char frameBuffer[70][230];
const int bufferWidth = 230;
const int bufferHeight = 70;

void drawLine(int x1, int y1, int x2, int y2);
void charsToBuffer(char* text, int x, int y);
void drawBuffer();
void clearBuffer();
void setCursor(int x, int y);
void scambiaInt(int* a, int* b);

void drawLine(int x1, int y1, int x2, int y2){
    if(x1>x2){
        scambiaInt(&x1, &x2);
        scambiaInt(&y1, &y2);
    }
    int h, l;
    int direction;
    float m = float((y2-y1))/float((x2-x1)); //SE POSITIVA, VA SOPRA, SE NEGATIVA, VA SOTTO (curvatura della linea)
    float b = y1 - (m*x1); //fattore b per il calcolo dei vari punti
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
    cout<<"DATI: "<<"h: "<<h<<" l: "<<l<<" m: "<<m<<"\n";
    //y = m*x + b
    //x = (y-b) / m
    cout<<direction<<"\n";

    //zona di calcolo 
    if(direction==2){
        for(int i=0; i<l; i++){
            frameBuffer[int((m*(i+x1)+b))][i+x1] = '#';
        }
    }
    if(direction==1){
        for(int i=0; i<h; i++){
            if(y1<y2){
                if(isinf(m))
                    frameBuffer[i+y1][x1] = '#';
                else
                    frameBuffer[i+y1][int(((i+y1)-b)/m)] = '#';
            }else{
                if(isinf(m))
                    frameBuffer[-i+y1][x1] = '#';
                else
                    frameBuffer[-i+y1][int(((-i+y1)-b)/m)] = '#';
            }
        }
    }
}

void charsToBuffer(char* text, int x, int y){

}

void drawBuffer(){
    for(int i=0; i<bufferHeight; i++){
        setCursor(0,i);
        for(int j=0; j<bufferWidth; j++){
            cout<<frameBuffer[i][j];
        }
    }
}

void clearBuffer(){
    for(int i=0; i<bufferHeight; i++){
        for(int j=0; j<bufferWidth; j++){
            frameBuffer[i][j] = ' ';
        }
    }
}

void setCursor(int x, int y){
    x++;
    y++;
    printf("%c[%d;%df",0x1B,y,x);
}

void scambiaInt(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}