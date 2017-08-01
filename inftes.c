#include <stdio.h>
#include <wiringPi.h>
#include "rpi-pin.h"

int main(){
  int i = 0;
  if(wiringPiSetup() == -1) return 1;
  pinMode(15, INPUT);
  while(1){
	if(digitalRead(15) == LOW) i++;
	if(i == 3){
	  printf("OKOKOKOK\n");
	}
      delayMicroseconds(25);
    }
  return 0;
}
