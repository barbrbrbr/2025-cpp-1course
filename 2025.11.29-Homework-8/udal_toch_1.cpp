#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    
    Point points[100];
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    
    Point farthest = points[0];
    long long max_dist_sq = (long long)farthest.x * farthest.x + (long long)farthest.y * farthest.y;
    
    for (int i = 1; i < n; i++) {
        long long current_dist_sq = (long long)points[i].x * points[i].x + (long long)points[i].y * points[i].y;
        
        if (current_dist_sq > max_dist_sq) {
            max_dist_sq = current_dist_sq;
            farthest = points[i];
        }
    }
    
    printf("%d %d\n", farthest.x, farthest.y);
    
    return 0;
}