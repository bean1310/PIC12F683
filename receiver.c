/*
 * File:   main.c
 * Author: BEAN
 *
 * Created on August 2, 2017, 3:57 AM
 */

 /*
  * このプログラムについて
  * ^^^^^^^^^^^^^^^^^^^
  * 赤外線センサより赤外線信号を読み、解析してそのデータを表示するRaspberry Pi 3用のプログラム
  */

#include <stdio.h>
#include <wiringPi.h>
// GPIO指定をわかりやすくする自作ヘッダファイル
#include "rpi-pin.h"

// 赤外線センサのOutputピンに接続するGPIOピンの指定
#define READPIN GPIO_18
// 数値データのビット長
#define BIT 4

// 赤外線センサから得られたデータを解析し、データの値を返す関数
int receve();
// 配列で表現された2進数を10進数に変換する関数, 4ビット長(=2^0 - 2^3まで)しか対応していない
int todec(int *);

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
        /* 先頭のリーダビットを検知した時の処理 */
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
