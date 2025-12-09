#include <stdio.h>

typedef struct {
    char surname[25];
    char name[25];
    int math;
    int phys;
    int inf;
} Student;

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    
    Student students[1000];
    
    double sum_math = 0.0;
    double sum_phys = 0.0;
    double sum_inf = 0.0;
    
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d %d", students[i].surname, students[i].name, &students[i].math, &students[i].phys, &students[i].inf);
        
        sum_math += students[i].math;
        sum_phys += students[i].phys;
        sum_inf += students[i].inf;
    }

    double sr_math = sum_math / n;
    double sr_phys = sum_phys / n;
    double sr_inf = sum_inf / n;

    printf("%g %g %g", sr_math, sr_phys, sr_inf);

    return 0;

}