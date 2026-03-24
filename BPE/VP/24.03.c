#include <stdio.h>

int zad1();
int zad2();
int zad3();
int zad4();

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
            case 3: zad3(); break;
            case 4: zad4(); break;

            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n");
        }
    } while (choice != 0);

    return 0;
}

// Задача 1: Демонстрация на указатели
int zad1() {
    int num = 42;         
    int *ptr = &num;       

    printf("Стойност на променливата num: %d\n", num);
    printf("Адрес на променливата num в паметта: %p\n", (void*)&num);
    
    printf("Стойност, изведена чрез указателя ptr: %d\n", *ptr);
    printf("Адрес, съхранен в указателя ptr: %p\n", (void*)ptr);
    
    return 0;
}


// Задача 2: Математически операции с числа чрез указатели

int zad2() {
    float a, b;
    float *pA = &a;
    float *pB = &b;

    printf("Въведете първото число: ");
    scanf("%f", pA);  
    printf("Въведете второто число: ");
    scanf("%f", pB);

    printf("Сума: %.2f\n", (*pA) + (*pB));
    printf("Разлика: %.2f\n", (*pA) - (*pB));
    printf("Умножение: %.2f\n", (*pA) * (*pB));
    
    if (*pB != 0) {
        printf("Деление: %.2f\n", (*pA) / (*pB));
    } else {
        printf("Деление: Грешка! Не може да се дели на нула.\n");
    }
    
    return 0;
}

// Задача 3(7.1): Работа с диагонали на NxN масив
int zad3() {
    int n;
    printf("Въведете размер на матрицата NxN (от 1 до 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Невалиден размер! Моля въведете число между 1 и 10.\n");
        return 0;
    }

    int matrix[10][10];

    printf("Въведете елементите на матрицата:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Елемент [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nЕлементи на главния диагонал: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix[i][i]);
    }

    printf("\nЕлементи на второстепенния диагонал: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix[i][n - 1 - i]);
    }

    printf("\nЕлементи над главния диагонал: ");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
    }

    printf("\nЕлементи под главния диагонал: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    return 0;
}


// Задача 4(7.2): Проверка за магически квадрат

int zad4() {
    int n;
    printf("Въведете размер на квадрата N (от 1 до 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Невалиден размер! Моля въведете число между 1 и 10.\n");
        return 0;
    }

    int matrix[10][10];
    printf("Въведете елементите на матрицата:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Елемент [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int targetSum = 0;
    int isMagic = 1;


    for (int j = 0; j < n; j++) {
        targetSum += matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != targetSum) {
            isMagic = 0;
        }
    }

    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != targetSum) {
            isMagic = 0;
        }
    }

    int mainDiagSum = 0;
    int secDiagSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagSum += matrix[i][i];
        secDiagSum += matrix[i][n - 1 - i];
    }
    if (mainDiagSum != targetSum || secDiagSum != targetSum) {
        isMagic = 0;
    }

    if (isMagic) {
        printf("\nРезултат: Квадратът Е магически! (Общата сума е %d)\n", targetSum);
    } else {
        printf("\nРезултат: Квадратът НЕ е магически.\n");
    }

    return 0;
}