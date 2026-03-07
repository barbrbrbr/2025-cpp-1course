#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} ArrayList;

// Конструктор
ArrayList* createArrayList(int initialCapacity) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    if (!list) return NULL;
    
    list->data = (int*)malloc(sizeof(int) * initialCapacity);
    if (!list->data) {
        free(list);
        return NULL;
    }
    
    list->size = 0;
    list->capacity = initialCapacity;
    return list;
}

// Деструктор
void destroyArrayList(ArrayList* list) {
    if (list) {
        if (list->data) {
            free(list->data);
        }
        free(list);
    }
}

// Добавление элемента в конец
void add(ArrayList* list, int value) {
    if (!list) return;
    
    if (list->size >= list->capacity) {
        // Увеличиваем capacity в 2 раза
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    }
    
    list->data[list->size] = value;
    list->size++;
}

// Получение элемента по индексу
int get(ArrayList* list, int index) {
    if (!list || index < 0 || index >= list->size) {
        return -1; // Возвращаем -1 при ошибке
    }
    return list->data[index];
}

// Изменение элемента по индексу
void set(ArrayList* list, int index, int value) {
    if (!list || index < 0 || index >= list->size) return;
    
    list->data[index] = value;
}

// Удаление элемента по индексу
void removeAt(ArrayList* list, int index) {
    if (!list || index < 0 || index >= list->size) return;
    
    // Сдвигаем элементы влево
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    
    list->size--;
}

// Получение размера списка
int getSize(ArrayList* list) {
    if (!list) return 0;
    return list->size;
}

// Печать списка
void print(ArrayList* list) {
    if (!list) return;
    
    printf("ArrayList: [");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->data[i]);
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("] (size=%d, capacity=%d)\n", list->size, list->capacity);
}

// Вставка элемента по индексу
void insert(ArrayList* list, int index, int value) {
    if (!list || index < 0 || index > list->size) return;
    
    // Проверяем, нужно ли увеличивать capacity
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    }
    
    // Сдвигаем элементы вправо
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    
    // Вставляем новый элемент
    list->data[index] = value;
    list->size++;
}

// Очистка списка
void clear(ArrayList* list) {
    if (!list) return;
    list->size = 0;
}

// Проверка наличия элемента
int contains(ArrayList* list, int value) {
    if (!list) return 0;
    
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == value) {
            return 1;
        }
    }
    return 0;
}

// Сохранение в бинарный файл
void saveToFile(ArrayList* list, const char* filename) {
    if (!list || !filename) return;
    
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 0;
    }
    
    // Сохраняем размер и capacity
    fwrite(&list->size, sizeof(int), 1, file);
    fwrite(&list->capacity, sizeof(int), 1, file);
    
    // Сохраняем данные
    fwrite(list->data, sizeof(int), list->size, file);
    
    fclose(file);
    printf("Список сохранен в файл %s\n", filename);
}

// Загрузка из бинарного файла
ArrayList* loadFromFile(const char* filename) {
    if (!filename) return NULL;
    
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return NULL;
    }
    
    int size, capacity;
    
    // Читаем размер и capacity
    fread(&size, sizeof(int), 1, file);
    fread(&capacity, sizeof(int), 1, file);
    
    // Создаем список с нужной capacity
    ArrayList* list = createArrayList(capacity);
    if (!list) {
        fclose(file);
        return NULL;
    }
    
    // Читаем данные
    fread(list->data, sizeof(int), size, file);
    list->size = size;
    
    fclose(file);
    printf("Список загружен из файла %s\n", filename);
    return list;
}

// Пример использования
int main() {
    // Создаем список
    ArrayList* list = createArrayList(2);
    printf("Создан пустой список:\n");
    print(list);
    
    // Добавляем элементы
    printf("\nДобавляем элементы 10, 20, 30:\n");
    add(list, 10);
    add(list, 20);
    add(list, 30);
    print(list);
    
    // Вставляем элемент
    printf("\nВставляем 15 на позицию 1:\n");
    insert(list, 1, 15);
    print(list);
    
    // Получаем элемент
    printf("\nЭлемент на позиции 2: %d\n", get(list, 2));
    
    // Изменяем элемент
    printf("\nИзменяем элемент на позиции 0 на 5:\n");
    set(list, 0, 5);
    print(list);
    
    // Проверяем наличие элементов
    printf("\nСодержит ли список 20? %s\n", contains(list, 20) ? "Да" : "Нет");
    printf("Содержит ли список 100? %s\n", contains(list, 100) ? "Да" : "Нет");
    
    // Удаляем элемент
    printf("\nУдаляем элемент на позиции 2:\n");
    removeAt(list, 2);
    print(list);
    
    // Сохраняем в файл
    printf("\nСохраняем список в файл:\n");
    saveToFile(list, "list.bin");
    
    // Очищаем список
    printf("\nОчищаем список:\n");
    clear(list);
    print(list);
    
    // Загружаем из файла
    printf("\nЗагружаем список из файла:\n");
    ArrayList* loadedList = loadFromFile("list.bin");
    if (loadedList) {
        print(loadedList);
        destroyArrayList(loadedList);
    }
    
    // Уничтожаем список
    destroyArrayList(list);
    
    return 0;
}