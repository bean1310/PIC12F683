#include <stdio.h>
#include <wiringPi.h>
#include "rpi-pin.h"

#define READPIN GPIO_14
#define BIT 4

int receve();
int todec(int *);

int main(){

  if(wiringPiSetup() == -1) return 1;
    pinMode(READPIN, INPUT);
	while(1) printf("%dを受信しました\n", receve());

  return 0;
}

int receve(){
  int value = 0, oldValue, startCnt = 0, bit = 0;
  int data[BIT] = {0};

  while(1){
    value = !digitalRead(READPIN);
    if(oldValue == 1 && value == 1) startCnt++;
    if(startCnt == 2){
      for(bit  = 0; bit < BIT; bit++){
        delayMicroseconds(25);
				value = !digitalRead(READPIN);
        data[bit] = value;
        printf("%d, ", value);
      }
      puts("\n");
      return todec(data);
    }
    oldValue = value;
    delayMicroseconds(25);
  }
}

int todec(int *data){
  return data[3] * 8 + data[2] * 4 + data[1] * 2 + data[0];
}
