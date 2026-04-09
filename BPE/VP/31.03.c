#include <stdio.h>
#include <stdlib.h>
int zad1();
int zad2();


int main(){
    int choice;
    do {
        printf("Въведете номер на задача (0 за изход): ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            printf("Невалиден вход! Моля, въведете число.\n");
            continue;
        }
        printf("\n"); 
        switch(choice) {
            case 1: zad1(); break;
            case 2: zad2(); break;


            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n");
        }
    } while (choice != 0);

    return 0;
}


// 1.програма динамичен масив  с първоначален въведен от потребителя n , позволете на потребителя да въвежда елемети в масива , ако масива се запълни удвоете неговия размер и продължете да добавяте елементи 
int zad1() {
    int capacity;

    printf("Въведете първоначален размер на масива (n): ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        while(getchar() != '\n');
        printf("Моля, въведете валидно положително число за размер.\n");
        return 1;
    }

    int *arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("Грешка: Неуспешно заделяне на памет.\n");
        return 1;
    }

    int size = 0; 
    int input;
    int has_resized = 0; 
    printf("\nЗапочнете да въвеждате цели числа.\n");
    printf("(За да прекратите въвеждането по-рано, въведете буква):\n");

    while (scanf("%d", &input) == 1) {
        if (size == capacity) {
            if (has_resized == 0) {
                capacity *= 2;
                printf("\n Масивът е пълен! Удвояване на капацитета до %d \n", capacity);
                
                int *temp = (int *)realloc(arr, capacity * sizeof(int));
                if (temp == NULL) {
                    printf("Грешка: Неуспешно презаделяне на памет.\n");
                    free(arr); 
                    return 1;
                }
                arr = temp;
                has_resized = 1; 
            }
            else {
                printf("\n Достигнат е максималният капацитет. \n");
                break; 
            }
        }

        arr[size] = input;
        size++;
    }
    while(getchar() != '\n');

    printf("\nВъведени са общо: %d елемента.\n", size);
    printf("Краен капацитет на масива: %d\n", capacity);
    printf("Елементи: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
// 2.напишете програма която чете динамичем масив с n числа и създва нов масив които чете само нечетни числа 

int zad2() {
    int n;

    printf("Въведете броя на елементите (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Моля, въведете валидно положително число.\n");
        return 1;
    }
    
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Грешка при заделяне на памет!\n");
        return 1;
    }

    printf("Въведете %d на брой цели числа:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int choice;
    do {
        printf("\nМЕНЮ\n");
        printf("1. Покажи четните числа\n");
        printf("2. Покажи нечетните числа\n");
        printf("3. Покажи средно аритметично\n");
        printf("0. Изход\n");
        printf("Изберете опция: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int hasEven = 0;
                printf("Четни числа: ");
                for (int i = 0; i < n; i++) {
                    if (array[i] % 2 == 0) {
                        printf("%d ", array[i]);
                        hasEven = 1;
                    }
                }
                if (!hasEven) printf("Няма въведени четни числа.");
                printf("\n");
                break;
            }
            case 2: {
                int hasOdd = 0;
                printf("Нечетни числа: ");
                for (int i = 0; i < n; i++) {
                    if (array[i] % 2 != 0) {
                        printf("%d ", array[i]);
                        hasOdd = 1;
                    }
                }
                if (!hasOdd) printf("Няма въведени нечетни числа.");
                printf("\n");
                break;
            }
            case 3: {
                double sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += array[i];
                }
                printf("Средно аритметично: %.2f\n", sum / n);
                break;
            }
            case 0:
                printf("Изход от програмата.\n");
                break;
            default:
                printf("Невалидна опция! Моля, опитайте отново.\n");
        }

    } while (choice != 0);

    free(array);

    return 0;
}