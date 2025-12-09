#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

int main(int argc, char** argv) {
    int n = 0;
    scanf("%d", &n);
    
    Point points[100];
    
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    
    double max_d = 0.0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            double dx = points[i].x - points[j].x;
            double dy = points[i].y - points[j].y;
            double dist = sqrt(dx * dx + dy * dy);
            
            if (dist > max_d) {
                max_d = dist;
            }
        }
    }
    
    printf("%.15g\n", max_d);
    
    return 0;
}