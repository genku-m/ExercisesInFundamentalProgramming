#include "img.h"

int main(void) {
  struct color pin1 = { 219, 0, 32 };
  struct color pin2 = { 255, 15, 51 };
  struct color pin3 = { 255, 71, 99 };
  struct color pin4 = { 255, 117, 137 };
  struct color pin5 = { 255, 168, 181 };
  struct color ball = { 0, 0, 0 };
  int i;

  for(i = 0; i < 40; ++i) {
    img_clear();
     if (i < 28) {
    //4列目
    img_fillpin(pin4,120,135,9);
    img_fillpin(pin4,140,135,9);
    img_fillpin(pin4,160,135,9);
    img_fillpin(pin4,180,135,9);
    }
    if (i < 24) {
    //3列目
    img_fillpin(pin3,130,130,10);
    img_fillpin(pin3,150,130,10);
    img_fillpin(pin3,170,130,10);
    }
    if (i < 20){
    //2列目
    img_fillpin(pin2,140,125,11);
    img_fillpin(pin2,160,125,11);
    }
    if (i < 16){
    //1列目
      img_fillpin(pin1,150,120,12);
    }
    img_fillcircle(ball, 150, 30+i*5, 40-i); 
    img_write();
  }


  return 0;
}