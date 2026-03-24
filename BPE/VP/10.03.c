#include <stdio.h>

int zad1();
int zad2();
int zad3();
int zad4();
int zad5();
int zad6();
int zad7();


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
            case 5: zad5(); break;
            case 6: zad6(); break;
            case 7: zad7(); break;

            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n");
        }
    } while (choice != 0);

    return 0;
}


// 1.	Да се прочете от клавиатурата едно целочислено число и да се изведе съобщение, ако то е по-голямо от 6. 
int zad1() {
    int number;
    printf("Въведете цяло число: ");
    scanf("%d", &number);
    if (number > 6) {
        printf("Числото %d е по-голямо от 6.\n", number);
    }
    else{
        printf("Числото %d е по-малко от 6.\n", number);
    }

    return 0;
}

// 2.	Да се прочете от клавиатурата едно целочислено число и да се изведе на екрана съобщение, ако остатъкът от делението му с 8 е по-голям от 4. 
int zad2() {
    int number;
    int ostatuk;
    printf("Въведете цяло число: ");
    scanf("%d", &number);
    ostatuk = number % 8;
    if (ostatuk > 4) {
        printf("Остатъкът от делението на %d с 8 е %d, което е по-голямо от 4.\n", number, ostatuk);
    }

    return 0;
}
// 3.	Да се прочетат от клавиатурата 3 числа и да се изведе на екрана най-малкото от тях. 
int zad3() {
    int a, b, c;
    int min;
    printf("Въведете три числа (разделени с интервал): ");
    scanf("%d %d %d", &a, &b, &c);
    min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    printf("Най-малкото число е: %d\n", min);

    return 0;
}
// 4.	Да се прочете от клавиатурата цифра и да се изведе на екрана нейното име. Да се използва оператор switch-case.

int zad4() {
    int digit;
    printf("Въведете цифра (от 0 до 9): ");
    scanf("%d", &digit);
    switch (digit) {
        case 0: printf("Нула\n");break;
        case 1: printf("Едно\n");break;
        case 2: printf("Две\n"); break;
        case 3: printf("Три\n"); break;
        case 4: printf("Четири\n"); break;
        case 5: printf("Пет\n"); break;
        case 6: printf("Шест\n"); break;
        case 7: printf("Седем\n"); break;
        case 8: printf("Осем\n"); break;
        case 9: printf("Девет\n"); break;
        default:
            printf("Грешка: Въведеното число не е цифра (трябва да е между 0 и 9)!\n");
            break;
    }

    return 0;
}


// 5.	Да се прочете от клавиатурата едно число от 1 до 7 и да се изведе на екрана кой ден от седмицата съответства на това число. Да се предвиди случай, когато не е въведено валидно число.
#include <stdio.h>

int zad5() {
    int day;
    printf("Въведете число от 1 до 7: ");
    scanf("%d", &day);
    switch(day) {
        case 1: printf("Понеделник\n"); break;
        case 2: printf("Вторник\n"); break;
        case 3: printf("Сряда\n"); break;
        case 4: printf("Четвъртък\n"); break;
        case 5: printf("Петък\n"); break;
        case 6: printf("Събота\n"); break;
        case 7: printf("Неделя\n"); break;
        default:
            printf("Грешка: Невалидно число! Моля, въведете число между 1 и 7.\n");
            break;
    }

    return 0;
}

// 1.	Да се напише програма, която прочита от клавиатурата едно цяло число и изкарва числова пирамида: 
// 1 
// 2 2 
// 3 3 3 
// ..... 

int zad6() {
    int n;

    printf("Въведете цяло число за големина на пирамидата: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}

// Да се напише програма, в която се въвежда цяло число, което представлява код на геометрична фигура – 1 – квадрат, 2 – правоъгълник, 3 – правоъгълен триъгълник, 4 – окръжност. След това се въвеждат размерите на избраната геометрична фигура. Програмата трябва да изведе типа на геометричната фигура, както и нейното лице. За пресмятането на лицето да се напишат подходящи функции.Напишете функция за размяна на две числа.  Демонстрирайте работата й. Напишете функция, която проверява дали конкретно число е четно или нечетно.

double areaSquare(double a) {
    return a * a;
}

double areaRectangle(double a, double b) {
    return a * b;
}

double areaRightTriangle(double a, double b) {
    return (a * b) / 2.0;
}

double areaCircle(double r) {
    double pi = 3.14; 
    return pi * r * r;
}



void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        printf("Числото %d е ЧЕТНО.\n", num);
    } else {
        printf("Числото %d е НЕЧЕТНО.\n", num);
    }
}

// 7. Геометрични фигури, размяна на числа и проверка за четност
int zad7() {
    int shapeCode;
    double a, b, r, area;

    printf("Въведете код на фигурата:\n");
    printf("1 - Квадрат\n2 - Правоъгълник\n3 - Правоъгълен триъгълник\n4 - Окръжност\n");
    printf("Вашият избор: ");
    scanf("%d", &shapeCode);

    switch (shapeCode) {
        case 1:
            printf("Избрахте: Квадрат\n");
            printf("Въведете страната a: ");
            scanf("%lf", &a);
            area = areaSquare(a);
            printf("Лицето на квадрата е: %.2lf\n", area);
            break;
        case 2:
            printf("Избрахте: Правоъгълник\n");
            printf("Въведете страна a: ");
            scanf("%lf", &a);
            printf("Въведете страна b: ");
            scanf("%lf", &b);
            area = areaRectangle(a, b);
            printf("Лицето на правоъгълника е: %.2lf\n", area);
            break;
        case 3:
            printf("Избрахте: Правоъгълен триъгълник\n");
            printf("Въведете катет a: ");
            scanf("%lf", &a);
            printf("Въведете катет b: ");
            scanf("%lf", &b);
            area = areaRightTriangle(a, b);
            printf("Лицето на правоъгълния триъгълник е: %.2lf\n", area);
            break;
        case 4:
            printf("Избрахте: Окръжност\n");
            printf("Въведете радиус r: ");
            scanf("%lf", &r);
            area = areaCircle(r);
            printf("Лицето на окръжността е: %.2lf\n", area);
            break;
        default:
            printf("Грешка: Невалиден код на фигура!\n");
            break;
    }

    printf("\nФУНКЦИЯ ЗА РАЗМЯНА\n");
    int n1 = 5, n2 = 10, temp;
    printf("преди a = %d, b = %d\n", n1, n2);
    temp = n1;
    n1 = n2;
    n2 = temp;
    printf("след a = %d, b = %d\n", n1, n2);

    printf("\nФУНКЦИЯ ЗА ЧЕТНО/НЕЧЕТНО\n");
    int testNum;
    printf("Въведете цяло число за проверка (четно/нечетно): ");
    scanf("%d", &testNum);
    checkEvenOdd(testNum);

    return 0;
}