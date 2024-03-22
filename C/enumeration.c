#include <stdio.h>
#define N 10000000
double cul (double x) {
    double dx = x/N;
    int i;
    for (i = 0; i < N; ++i){
        double j = i * dx;
        double y = j*j -x;
        if (y >= 0){
            return j;
        }
    }
    return x;
}

int main() {
    double n;
    scanf("%lf",&n);
    printf("%8.3lf",cul(n));
    return 0;
}
