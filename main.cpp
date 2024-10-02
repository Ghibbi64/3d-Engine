#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;

int drawLine(int x, int y);
void setCursor(int x, int y);

int main(){
    setCursor(30, 30);
    cout<<"ciao";
}

int drawLine(int x, int y){

}

void setCursor(int x, int y){
    string command = "tput cup " + to_string(x) + " " + to_string(y);
    system(command.c_str());
}