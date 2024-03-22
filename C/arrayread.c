#include <stdio.h>
void piarray(int n, int a[]) {
  int i;
  for(i = 0; i < n; ++i) {
    printf(" %2d", a[i]);
    if(i % 10 == 9 || i == n-1) { printf("\n"); }
  }
}
void riarray(int n, int a[]) {
  int i;
  for(i = 0; i < n; ++i) {
    printf("%d> ", i+1); scanf("%d", a+i);  // &a[i]でもOK
  }
}

void riarrayz(int a[]) {
  int i = 0;
  for(;;) {
    printf("%d> ", i+1); scanf("%d", a+i);  // &a[i]でもOK
    if(a[i]== 0) {
        printf("%d",i);
        break;
    }
    i++;
  }
}

int main(void) {
  int a[100];
  riarrayz(a);
  return 0;
}
