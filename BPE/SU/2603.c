#include <stdio.h>

int zad1();
int zad2();
int zad3();
int zad4();
int zad5();
int zad6();
int zad7();
int zad8();
int zad9();

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
            case 8: zad8(); break;
            case 9: zad9(); break;
            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n\n");
        }
    } while (choice != 0);

    return 0;
}

//1.	Всяка редица от равни числа в едномерен сортиран масив, се нарича площадка. Да се напише програма, която намира началото и дължината на най-дългата площадка в даден сортиран във възходящ ред едномерен масив(въвеждат се N и самият масив от потребителя).

int zad1() {
    int n;
    printf("Въведете брой елементи N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Броят елементи трябва да е по-голям от 0.\n\n");
        return 0;
    }

    int arr[100];
    printf("Въведете %d сортирани елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_len = 1, best_start = 0;
    int current_len = 1, current_start = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                best_start = current_start;
            }
            current_len = 1;
            current_start = i;
        }
    }
    if (current_len > max_len) {
        max_len = current_len;
        best_start = current_start;
    }

    printf("Най-дългата площадка започва от индекс %d и е с дължина %d (елемент: %d).\n\n", best_start, max_len, arr[best_start]);
    return 0;
}

//2.	Да се напише програма, която проверява дали между елементите на редицата a0, a1, ..., an са изпълнени релациите: a0 < a1 > a2 < a3… (въвеждат се N и елементите на редицата)
int zad2() {
    int n;
    printf("Въведете брой елементи N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Броят елементи трябва да е по-голям от 0.\n\n");
        return 0;
    }

    int arr[100];
    printf("Въведете %d елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int is_zigzag = 1; 

    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            if (arr[i] >= arr[i + 1]) {
                is_zigzag = 0;
                break;
            }
        } else {
            if (arr[i] <= arr[i + 1]) {
                is_zigzag = 0;
                break;
            }
        }
    }

    if (is_zigzag) {
        printf("Релациите СА изпълнени.\n\n");
    } else {
        printf("Релациите НЕ са изпълнени.\n\n");
    }
    return 0;
}

//3.	Напишете програма, която получава масив от N елемента и обръща реда на елементите. Изкарайте ново полученият масив.

int zad3() {
    int n;
    printf("Въведете брой елементи N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Броят елементи трябва да е по-голям от 0.\n\n");
        return 0;
    }

    int arr[100];
    printf("Въведете %d елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("Обърнатият масив е: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    return 0;
}
//4.	Напишете програма, която получава редица с цели N числа. След това получава цяло число К. Отместете всички елементи на редицата с K позиции, като използвате правилото за превъртане (когато елемент от последна позиция трябва да се измести то той трябва да отиде на първа позиция в редицата).
int zad4() {
    int n, k;
    printf("Въведете брой елементи N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Броят елементи трябва да е по-голям от 0.\n\n");
        return 0;
    }

    int arr[100], temp[100];
    printf("Въведете %d елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Въведете брой позиции за изместване K: ");
    scanf("%d", &k);

    k = k % n;
    if (k < 0) k += n;

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    printf("Изместеният масив е: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n\n");
    return 0;
}
//5.	Дадена е редица с N цели числа. Да не намери K тия по големина елемент в редицата. 

int zad5() {
    int n, k;
    printf("Въведете брой елементи N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Броят елементи трябва да е по-голям от 0.\n\n");
        return 0;
    }

    int arr[100];
    printf("Въведете %d елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Въведете K, за да намерите K-тия по големина елемент: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Невалидна стойност за K. Трябва да е между 1 и %d.\n\n", n);
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("%d-тият по големина елемент е: %d\n\n", k, arr[k - 1]);
    return 0;
}

// 6. За дадена редица от числа да се намери и отпечата най-дългата (монотонно) нарастваща (или намаляваща) под редица
int zad6() {
    int n;
    printf("Въведете брой елементи N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Броят елементи трябва да е по-голям от 0.\n\n");
        return 0;
    }

    int arr[100];
    printf("Въведете %d елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_inc = 1, cur_inc = 1, start_inc = 0, best_start_inc = 0;
    int max_dec = 1, cur_dec = 1, start_dec = 0, best_start_dec = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            cur_inc++;
        } else {
            if (cur_inc > max_inc) { max_inc = cur_inc; best_start_inc = start_inc; }
            cur_inc = 1; start_inc = i;
        }

        if (arr[i] < arr[i - 1]) {
            cur_dec++;
        } else {
            if (cur_dec > max_dec) { max_dec = cur_dec; best_start_dec = start_dec; }
            cur_dec = 1; start_dec = i;
        }
    }
    
    if (cur_inc > max_inc) { max_inc = cur_inc; best_start_inc = start_inc; }
    if (cur_dec > max_dec) { max_dec = cur_dec; best_start_dec = start_dec; }

    if (max_inc >= max_dec) {
        printf("Най-дългата нарастваща подредица е с дължина %d: ", max_inc);
        for (int i = 0; i < max_inc; i++) printf("%d ", arr[best_start_inc + i]);
    } else {
        printf("Най-дългата намаляваща подредица е с дължина %d: ", max_dec);
        for (int i = 0; i < max_dec; i++) printf("%d ", arr[best_start_dec + i]);
    }
    printf("\n\n");
    return 0;
}

//7.	Да се напише програма, която намира последователност от числа в масив,които имат сума равна на число, въведено от  потребителя(ако има такава). 
int zad7() {
    int n, target_sum;
    printf("Въведете брой елементи N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Броят елементи трябва да е по-голям от 0.\n\n");
        return 0;
    }

    int arr[100];
    printf("Въведете %d елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Въведете търсената сума: ");
    scanf("%d", &target_sum);

    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            
            if (current_sum == target_sum) {
                printf("Намерена последователност: ");
                for (int k = i; k <= j; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n\n");
                return 0; 
            }
        }
    }

    printf("Не е намерена последователност с търсената сума.\n\n");
    return 0;
}

// 8. Вмъкване на числа на определен индекс в масив с капацитет 20 елемента. Въвеждането спира при вход 0 (нула) или при запълване на масива.
int zad8() {
    int arr[20];
    int current_size = 0;
    int n;

    printf("Въведете първоначалния брой елементи: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Невалиден брой! Трябва да е между 1 и 20.\n\n");
        return 0;
    }

    printf("Въведете %d първоначални елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    current_size = n;

    printf("\nЗапочнете да въвеждате двойки: <число> <индекс>.\n");
    printf("Въведете само '0' като първо число за край.\n");

    while (current_size < 20) {
        int val, idx;
        
        printf("Вход: ");
        scanf("%d", &val);
        
        if (val == 0) {
            break;
        }
        scanf("%d", &idx);

        if (idx < 0 || idx > current_size) {
            printf("Невалиден индекс! Трябва да е между 0 и %d.\n", current_size);
            continue;
        }

        for (int i = current_size; i > idx; i--) {
            arr[i] = arr[i - 1];
        }

        arr[idx] = val;
        current_size++;
    }
    if (current_size == 20) {
        printf("\nМасивът е запълнен!\n");
    }
    printf("Изход: ");
    for (int i = 0; i < current_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    return 0;
}


// 9. Напишете програма, която намира максималната редица от последователни еднакви елементи в масив и ги отпечатва.
int zad9() {
    int n;
    printf("Въведете брой елементи N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Броят елементи трябва да е по-голям от 0.\n\n");
        return 0;
    }

    int arr[100];
    printf("Въведете %d елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_len = 1, current_len = 1;
    int best_start = 0, current_start = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                best_start = current_start;
            }
            current_len = 1;
            current_start = i;
        }
    }
    
    if (current_len > max_len) {
        max_len = current_len;
        best_start = current_start;
    }

    printf("Изход: ");
    for (int i = 0; i < max_len; i++) {
        printf("%d ", arr[best_start]);
    }
    printf("\n\n");
    return 0;
}
