#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

typedef struct {
    char date[20];
    int quantity;
} Supply;

typedef struct {
    Supply* supplies;
    int count;
    int capacity;
} SupplyList;

typedef struct {
    char name[50];
    double price;
    SupplyList supply_list;
} Product;

void init_supply_list(SupplyList* sl) {
    sl->count = 0;
    sl->capacity = 5;
    sl->supplies = (Supply*)malloc(sl->capacity * sizeof(Supply));
}

void add_supply(SupplyList* sl, const char* date, int quantity) {
    if (sl->count >= sl->capacity) {
        sl->capacity *= 2;
        sl->supplies = (Supply*)realloc(sl->supplies, 
                                       sl->capacity * sizeof(Supply));
    }
    
    // новая поставка
    strncpy(sl->supplies[sl->count].date, date, 19);
    sl->supplies[sl->count].date[19] = '\0';
    sl->supplies[sl->count].quantity = quantity;
    sl->count++;
}

int calculate_total_quantity(const SupplyList* sl) {
    if (sl->count == 0) return 0;

    int total = 0;
    for (int i = 0; i < sl->count; i++) {
        total += sl->supplies[i].quantity;
    }
    return total;
}

void free_supply_list(SupplyList* sl) {
    free(sl->supplies);
    sl->supplies = NULL;
    sl->count = 0;
    sl->capacity = 0;
}

Product* create_products(int n) {
    Product* products = (Product*)malloc(n * sizeof(Product));
    for (int i = 0; i < n; i++) {
        init_supply_list(&products[i].supply_list);
    }
    return products;
}

Product* find_product_with_most_supplies(Product* products, int n) {
    if (n <= 0) return NULL;

    Product* best = &products[0];
    int best_total = calculate_total_quantity(&products[0].supply_list);

    for (int i = 1; i < n; i++) {
        int current_total = calculate_total_quantity(&products[i].supply_list);
        if (current_total > best_total) {
            best = &products[i];
            best_total = current_total;
        }
    }
    return best;
}

void print_product(const Product* product) {
    printf("Товар: %s, цена: %.2f\n", product->name, product->price);
    printf("Поставки: ");
    for (int i = 0; i < product->supply_list.count; i++) {
        printf("[%s - %d] ", product->supply_list.supplies[i].date, product->supply_list.supplies[i].quantity);
    }
    printf("\nОбщее количество: %d\n", calculate_total_quantity(&product->supply_list));
}

void free_products(Product* products, int n) {
    for (int i = 0; i < n; i++) {
        free_supply_list(&products[i].supply_list);
    }
    free(products);
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
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int n = 0;
    printf("Введите количество товаров: ");
    scanf("%d", &n);
    clear_input_buffer();

    Product* products = create_products(n);

    for (int i = 0; i < n; i++) {
        printf("\nТовар %d:\n", i + 1);
        
        printf("Название: ");
        fgets(products[i].name, sizeof(products[i].name), stdin);
        clear_last_linebreak(products[i].name);
        
        printf("Цена: ");
        scanf("%lf", &products[i].price);

        int supply_count = 0;
        printf("Количество поставок: ");
        scanf("%d", &supply_count);

        printf("Введите %d поставок (дата и количество): ", supply_count);
        for (int j = 0; j < supply_count; j++) {
            char date[20];
            int quantity = 0;
            
            printf("Поставка %d - дата (ДД.ММ.ГГГГ): ", j + 1);
            scanf("%s", date);
            printf("Поставка %d - количество: ", j + 1);
            scanf("%d", &quantity);
            
            add_supply(&products[i].supply_list, date, quantity);
        }
        clear_input_buffer();
    }

    printf("\nВсе товары:\n");
    for (int i = 0; i < n; i++) {
        printf("\n%d. ", i + 1);
        print_product(&products[i]);
    }

    Product* best = find_product_with_most_supplies(products, n);
    if (best) {
        printf("\nТовар с наибольшим количеством:\n");
        print_product(best);
    }
    
    printf("\nДОБАВЛЕНИЕ НОВОЙ ПОСТАВКИ\n");
    if (n > 0) {
        char new_date[20];
        int new_quantity;
        
        printf("Введите дату новой поставки:");
        scanf("%s", new_date);
        printf("Введите количество: ");
        scanf("%d", &new_quantity);
        
        add_supply(&products[0].supply_list, new_date, new_quantity);
        
        printf("Поставка добавлена к товару '%s'\n", products[0].name);
        printf("Обновленная информация:\n");
        print_product(&products[0]);
    }
    
    free_products(products, n);
    return 0;
}