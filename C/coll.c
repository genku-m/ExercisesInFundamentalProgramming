#include <stdio.h>
struct color { unsigned char r, g, b; };
void showcolor(struct color c) {
  printf("%02x%02x%02x\n", c.r, c.g, c.b);
}
struct color mixcolor(struct color c, struct color d) {
  struct color ret = { (c.r+d.r)/2, (c.g+d.g)/2, (c.b+d.b)/2 };
  return ret;
}

struct color brighter (struct color c){
    struct color white = {255,255,255}; return mixcolor(c,white);
}

struct color darker (struct color c){
    struct color dark = {0,0,0}; return mixcolor(c,dark);
}

int main(void) {
  struct color c1 = {165,215,255};
  struct color c2 = {255,237,91};
  showcolor(c1);
  showcolor(c2);
  showcolor(brighter(c1));
  showcolor(darker(c2));
  return 0;
}
