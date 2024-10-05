#include<cstdlib>
#include<iostream>
using namespace std;

void scambiaInt(int* a, int* b);

void scambiaInt(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}