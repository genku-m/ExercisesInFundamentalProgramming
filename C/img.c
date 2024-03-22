#include <stdio.h>
#include <stdlib.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

void img_clear(void) {
  int i, j;
  for(j = 0; j < HEIGHT; ++j) {
    for(i = 0; i < WIDTH; ++i) {
      buf[j][i][0] = buf[j][i][1] = buf[j][i][2] = 255;
    }
  }
}

void img_write(void) {
  sprintf(fname, "img%04d.ppm", ++filecnt);
  FILE *f = fopen(fname, "wb");
  if(f == NULL) { fprintf(stderr, "can't open %s\n", fname); exit(1); }
  fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(buf, sizeof(buf), 1, f);
  fclose(f);
}

void img_putpixel(struct color c, int x, int y) {
  if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) { return; }
  buf[HEIGHT-y-1][x][0] = c.r;
  buf[HEIGHT-y-1][x][1] = c.g;
  buf[HEIGHT-y-1][x][2] = c.b;
}

void img_fillcircle(struct color c, double x, double y, double r) {
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
  int i, j;
  for(j = jmin; j <= jmax; ++j) {
    for(i = imin; i <= imax; ++i) {
      if((x-i)*(x-i) + (y-j)*(y-j) <= r*r) { img_putpixel(c, i, j); }
    }
  }
}

void img_fillpin(struct color c, double x, double y, double r) {
  double xr1 = r; double yr1 = r*2.2; double xr2 = r*6/10; double yr2 = r*9/10;
  double y2 = y + yr2 + yr1;
  int imin1 = (int)(x - xr1 - 1), imax1 = (int)(x + xr1 + 1);
  int jmin1 = (int)(y - yr1 - 1), jmax1 = (int)(y + yr1 + 1);
  int imin2 = (int)(x - xr2 - 1), imax2 = (int)(x + xr2 + 1);
  int jmin2 = (int)(y2 - yr2 - 1), jmax2 = (int)(y2 + yr2 + 1);
  int i, j;
  for(j = jmin1; j <= jmax1; ++j) {
    for(i = imin1; i <= imax1; ++i) {
      if((x-i)*(x-i)/(xr1*xr1) + (y-j)*(y-j)/(yr1*yr1) <= 1) { img_putpixel(c, i, j); }
    }
  }
  for(j = jmin2; j <= jmax2; ++j) {
    for(i = imin2; i <= imax2; ++i) {
      if((x-i)*(x-i)/(xr2*xr2) + (y2-j)*(y2-j)/(yr2*yr2) <= 1) { img_putpixel(c, i, j); }
    }
  }
}
