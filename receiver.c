#include <stdio.h>
#include <wiringPi.h>
#include "rpi-pin.h"

#define READPIN GPIO_18
#define BIT 4

int receve();
int todec(int *);
char readInfrared();

int main(){

  if(wiringPiSetup() == -1) return 1;
  
  pinMode(READPIN, INPUT);
	
	printf("%dを受信しました\n", receve());
  
  return 0;
}

int receve(){
  int bit = 0;
  int data[BIT] = {0};
  
  while(1){
		if(!digitalRead(READPIN)){
			for(bit = 0; bit < BIT; bit++){
				delayMicroseconds(600);
				data[bit] = !digitalRead(READPIN);
			}
      return todec(data);
    }
  }
}

int todec(int *data){
  return data[3] * 8 + data[2] * 4 + data[1] * 2 + data[0];
}
