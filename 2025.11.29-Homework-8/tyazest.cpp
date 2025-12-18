#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main(int argc, char** argv) {
    int n = 0;
    scanf("%d", &n);
    
    Point points[100];

    double sumx = 0.0;
    double sumy = 0.0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        sumx += points[i].x;
        sumy += points[i].y;
    }

    double center_x = sumx / n;
    double center_y = sumy / n;
    
    printf("%.15g %.15g\n", center_x, center_y);
    
    return 0;
}
    