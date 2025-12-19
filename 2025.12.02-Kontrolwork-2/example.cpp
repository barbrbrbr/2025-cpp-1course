#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

// Структура для хранения оценок студента
typedef struct {
    int* grades;    // динамический массив оценок
    int count;      // количество оценок
    int capacity;   // вместимость массива
} Gradebook;

// Структура для студента
typedef struct {
    char name[50];
    int age;
    Gradebook grades;  // вложенная структура с оценками
} Student;

// Функции для работы с Gradebook
void init_gradebook(Gradebook* gb) {
    gb->count = 0;
    gb->capacity = 5;
    gb->grades = (int*)malloc(gb->capacity * sizeof(int));
}

void add_grade(Gradebook* gb, int grade) {
    // Если массив заполнен, увеличиваем его размер
    if (gb->count >= gb->capacity) {
        gb->capacity *= 2;
        gb->grades = (int*)realloc(gb->grades, gb->capacity * sizeof(int));
    }
    gb->grades[gb->count] = grade;
    gb->count++;
}

double calculate_average(const Gradebook* gb) {
    if (gb->count == 0) return 0.0;

    int sum = 0;
    for (int i = 0; i < gb->count; i++) {
        sum += gb->grades[i];
    }
    return (double)sum / gb->count;
}

void free_gradebook(Gradebook* gb) {
    free(gb->grades);
    gb->grades = NULL;
    gb->count = 0;
    gb->capacity = 0;
}

// Функции для работы со студентами
Student* create_students(int n) {
    Student* students = (Student*)malloc(n * sizeof(Student));
    for (int i = 0; i < n; i++) {
        init_gradebook(&students[i].grades);
    }
    return students;
}

Student* find_best_student(Student* students, int n) {
    if (n <= 0) return NULL;

    Student* best = &students[0];
    double best_avg = calculate_average(&students[0].grades);

    for (int i = 1; i < n; i++) {
        double current_avg = calculate_average(&students[i].grades);
        if (current_avg > best_avg) {
            best = &students[i];
            best_avg = current_avg;
        }
    }
    return best;
}

void print_student(const Student* student) {
    printf("Студент: %s, возраст: %d\n", student->name, student->age);
    printf("Оценки: ");
    for (int i = 0; i < student->grades.count; i++) {
        printf("%d ", student->grades.grades[i]);
    }
    printf("\nСредний балл: %.2f\n", calculate_average(&student->grades));
}

void free_students(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        free_gradebook(&students[i].grades);
    }
    free(students);
}

void clear_input_buffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void clear_last_linebreak(char* str) {
    if (str != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
    }
}

int main(int argc, char** argv) {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int n = 0;
    printf("Введите количество студентов: ");
    scanf("%d", &n);
    clear_input_buffer();

    Student* students = create_students(n);

    // Ввод данных о студентах
    for (int i = 0; i < n; i++) {
        printf("\nСтудент %d:\n", i + 1);

        printf("Имя: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        clear_last_linebreak(students[i].name);

        printf("Возраст: ");
        scanf("%d", &students[i].age);        
        clear_input_buffer(); // Очищаем после scanf

        int grade_count = 0;
        printf("Количество оценок: ");
        scanf("%d", &grade_count);
        clear_input_buffer(); // Очищаем после scanf

        printf("Введите %d оценок: ", grade_count);
        for (int j = 0; j < grade_count; j++) {
            int grade = 0;
            scanf("%d", &grade);
            add_grade(&students[i].grades, grade);
        }
        clear_input_buffer();
    }

    // Вывод всех студентов
    printf("\nВсе студенты:\n");
    for (int i = 0; i < n; i++) {
        printf("\n%d. ", i + 1);
        print_student(&students[i]);
    }

    // Поиск лучшего студента
    Student* best = find_best_student(students, n);
    if (best) {
        printf("\nЛучший студент:\n");
        print_student(best);
    }
    
    free_students(students, n);
    return 0;
}
