#include <stdio.h>
#include <wiringPi.h>
#include "rpi-pin.h"

int main(){
  if(wiringPiSetup() == -1) return 1;
  pinMode(15, INPUT);
  while(1){
      if(digitalRead(15) == HIGH){
        printf("HIGH\n");
      }else{
        printf("LOW\n");
      }
      delay(5);
    }
  return 0;
}
