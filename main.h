#ifndef MAIN_H
#define MAIN_H

char sec1=7;
char sec2=5;
char min1=9;
char min2=5;
char hour1=2;
char hour2=1;
unsigned int delay;

char start,set,shift,digit,INC;

sbit d6 = P1 ^ 0;
sbit d5 = P1 ^ 1;
sbit d4 = P1 ^ 2;
sbit d3 = P1 ^ 3;
sbit d2 = P1 ^ 4;
sbit d1 = P1 ^ 5;

unsigned int segments[10] ={0x01,0x4F,0x12,0x06,0x4C,0x24,0x20,0x0F,0x00,0x04}; 

#endif