#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void zad1();
void zad1_a();
void zad1_b();
void zad1_c();


void zad2();
void zad2_a();
void zad2_b();
void zad2_c();

typedef struct {
    char make[50];
    char model[6]; 
    float engine_capacity;
    float price;
    char registered;
} Car;

void zad3();
void zad3_add();
void zad3_compare();


int main() {
    int choice;
    do {
        printf("1. Задача 1 (Файл с N и след това N числа)\n");
        printf("2. Задача 2 (Файл с неизвестен брой числа)\n");
        printf("3. Задача 3 (База данни Автокъща)\n");
        printf("0. Изход от програмата\n");
        printf("Въведете избор: ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            printf("Невалиден вход!\n");
            continue;
        }

        switch(choice) {
            case 1: zad1(); break;
            case 2: zad2(); break;
            case 3: zad3(); break;
            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор!\n");
        }
    } while (choice != 0);

    return 0;
}

void zad1() {
    int choice;
    do {
        printf("\nЗадача 1\n");
        printf("1. (а) Създаване на двоичен файл\n");
        printf("2. (б) Брой четни и нечетни \n");
        printf("3. (в) Сортиране и запис в текстов файл\n");
        printf("0. Назад към главното меню\n");
        printf("Избор: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: zad1_a(); break;
            case 2: zad1_b(); break;
            case 3: zad1_c(); break;
            case 0: break;
            default: printf("Невалиден избор!\n");
        }
    } while (choice != 0);
}

void zad1_a() {
    FILE *fp = fopen("data1.bin", "wb");
    if (!fp) { printf("Грешка при създаване на файла!\n"); return; }

    int n;
    printf("Въведете броя на числата (N): ");
    scanf("%d", &n);
    fwrite(&n, sizeof(int), 1, fp);

    printf("Въведете %d цели числа:\n", n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        fwrite(&temp, sizeof(int), 1, fp);
    }

    fclose(fp);
    printf("Двоичният файл 'data1.bin' е създаден успешно!\n");
}

void zad1_b() {
    FILE *fp = fopen("data1.bin", "rb");
    if (!fp) { printf("Създайте файла първо (подточка а)!\n"); return; }

    int n;
    if (fread(&n, sizeof(int), 1, fp) != 1) {
        printf("Грешка при четене на N.\n");
        fclose(fp); return;
    }

    int even_count = 0, odd_count = 0;
    for (int i = 0; i < n; i++) {
        int num;
        fread(&num, sizeof(int), 1, fp);

        if (num == 0) { even_count++; continue; }

        while (num != 0) {
            int digit = num % 10;
            if (digit < 0) digit = -digit;
            if (digit % 2 == 0) even_count++;
            else odd_count++;
            num /= 10;
        }
    }
    fclose(fp);
    printf("Общ брой четни цифри: %d\n", even_count);
    printf("Общ брой нечетни цифри: %d\n", odd_count);
}

void zad1_c() {
    FILE *fp = fopen("data1.bin", "rb");
    if (!fp) { printf("Създайте файла първо (подточка а)!\n"); return; }

    int n;
    fread(&n, sizeof(int), 1, fp);

    int *arr = (int *)malloc(n * sizeof(int));
    fread(arr, sizeof(int), n, fp);
    fclose(fp);

    qsort(arr, n, sizeof(int), compare_ints);

    FILE *txt_fp = fopen("sorted1.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(txt_fp, "%d ", arr[i]);
    }
    fclose(txt_fp);
    free(arr);

    printf("Масивът е сортиран и записан в 'sorted1.txt'!\n");
}

void zad2() {
    int choice;
    do {
        printf("\nЗадача 2\n");
        printf("1. (а) Създаване на двоичен файл (неизвестен брой числа)\n");
        printf("2. (б) Брой четни и нечетни цифри\n");
        printf("3. (в) Сортиране и запис в текстов файл\n");
        printf("0. Назад към главното меню\n");
        printf("Избор: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: zad2_a(); break;
            case 2: zad2_b(); break;
            case 3: zad2_c(); break;
            case 0: break;
            default: printf("Невалиден избор!\n");
        }
    } while (choice != 0);
}

void zad2_a() {
    FILE *fp = fopen("data2.bin", "wb");
    if (!fp) { printf("Грешка при създаване на файла!\n"); return; }

    int num;
    printf("Въвеждайте цели числа. За край въведете буква:\n");
    
    while (scanf("%d", &num) == 1) {
        fwrite(&num, sizeof(int), 1, fp);
    }
    while(getchar() != '\n');

    fclose(fp);
    printf("Файлът 'data2.bin' е създаден успешно!\n");
}

void zad2_b() {
    FILE *fp = fopen("data2.bin", "rb");
    if (!fp) { printf("Създайте файла първо (подточка а)!\n"); return; }

    int num;
    int even_count = 0, odd_count = 0;

    while (fread(&num, sizeof(int), 1, fp) == 1) {
        if (num == 0) { even_count++; continue; }
        
        while (num != 0) {
            int digit = num % 10;
            if (digit < 0) digit = -digit; 
            if (digit % 2 == 0) even_count++;
            else odd_count++;
            num /= 10;
        }
    }

    fclose(fp);
    printf("Общ брой четни цифри: %d\n", even_count);
    printf("Общ брой нечетни цифри: %d\n", odd_count);
}

void zad2_c() {
    FILE *fp = fopen("data2.bin", "rb");
    if (!fp) { printf("Създайте файла първо (подточка а)!\n"); return; }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    int n = file_size / sizeof(int);
    if (n == 0) {
        printf("Файлът е празен!\n");
        fclose(fp); return;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    fread(arr, sizeof(int), n, fp);
    fclose(fp);

    qsort(arr, n, sizeof(int), compare_ints);

    FILE *txt_fp = fopen("sorted2.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(txt_fp, "%d ", arr[i]);
    }
    fclose(txt_fp);
    free(arr);

    printf("Успешно сортирани %d числа. Записани в 'sorted2.txt'.\n", n);
}

void zad3() {
    int choice;
    do {
        printf("\nЗадача 3\n");
        printf("1. Добавяне на нов запис\n");
        printf("2. Сравнение на бинарния и текстовия файл\n");
        printf("0. Назад към главното меню\n");
        printf("Избор: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: zad3_add(); break;
            case 2: zad3_compare(); break;
            case 0: break;
            default: printf("Невалиден избор!\n");
        }
    } while (choice != 0);
}

void zad3_add() {
    Car new_car;
    printf("\nВъведете марка: ");
    scanf("%49s", new_car.make);
    
    printf("Въведете модел (точно 5 знака): ");
    scanf("%5s", new_car.model);
    
    printf("Въведете обем на двигателя: ");
    scanf("%f", &new_car.engine_capacity);
    
    printf("Въведете цена: ");
    scanf("%f", &new_car.price);
    
    printf("Има ли регистрация (Y/N): ");
    scanf(" %c", &new_car.registered); 

    FILE *bin_fp = fopen("cars.bin", "ab");
    FILE *txt_fp = fopen("cars.txt", "a");

    if (!bin_fp || !txt_fp) {
        printf("Грешка при отваряне на файловете!\n");
        if(bin_fp) fclose(bin_fp);
        if(txt_fp) fclose(txt_fp);
        return;
    }

    fwrite(&new_car, sizeof(Car), 1, bin_fp);
    fprintf(txt_fp, "Марка: %-15s Модел: %-5s Обем: %-5.1f Цена: %-8.2f Регистрация: %c\n", 
            new_car.make, new_car.model, new_car.engine_capacity, new_car.price, new_car.registered);

    fclose(bin_fp);
    fclose(txt_fp);
    printf("Записът е добавен успешно!\n");
}

void zad3_compare() {
    FILE *bin_fp = fopen("cars.bin", "rb");
    FILE *txt_fp = fopen("cars.txt", "r");

    if (!bin_fp || !txt_fp) {
        printf("Грешка: Файловете не съществуват.\n");
        if(bin_fp) fclose(bin_fp);
        if(txt_fp) fclose(txt_fp);
        return;
    }

    printf("\nДАННИ ОТ БИНАРНИЯ ФАЙЛ\n");
    Car temp_car;
    int count = 1;
    while (fread(&temp_car, sizeof(Car), 1, bin_fp) == 1) {
        printf("%d. %s %s, Двигател: %.1f, Цена: %.2f, Рег: %c\n", 
               count++, temp_car.make, temp_car.model, 
               temp_car.engine_capacity, temp_car.price, temp_car.registered);
    }

    printf("\nДАННИ ОТ ТЕКСТОВИЯ ФАЙЛ\n");
    char line[256];
    while (fgets(line, sizeof(line), txt_fp)) {
        printf("%s", line);
    }

    fclose(bin_fp);
    fclose(txt_fp);
    printf("\nСравнението приключи.\n");
}