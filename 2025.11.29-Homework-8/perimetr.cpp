#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double dist(Point a, Point b);

int main(int argc, char** argv) {
    int n = 0;
    scanf("%d", &n);
    
    Point points[100];
    
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    
    double max_perimetr = 0.0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double a = dist(points[i], points[j]);
                double b = dist(points[j], points[k]);
                double c = dist(points[k], points[i]);
                
                double perimetr = a + b + c;
                
                if (perimetr > max_perimetr) {
                    max_perimetr = perimetr;
                }
            }
        }
    }
    
    printf("%.15g\n", max_perimetr);
    
    return 0;
}

double dist(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}