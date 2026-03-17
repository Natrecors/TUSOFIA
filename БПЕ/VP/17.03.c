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
int zad10();


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
            case 10: zad10(); break;

            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n");
        }
    } while (choice != 0);

    return 0;
}

// 1. Да се състави програма, чрез която се въвеждат 7 цели числа от интервала [-5000..5000] в едномерен масив. Програмата да изведе общата сума на въведените числа.
int zad1() {
    int arr[7];  
    int sum = 0;
    printf("Въведете 7 цели числа в интервала [-5000..5000]:\n");
    for(int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
        while(arr[i] < -5000 || arr[i] > 5000) {
            printf("Грешка: Числото е извън интервала! Въведете отново: ");
            scanf("%d", &arr[i]);
        }
        sum += arr[i];
    }
    printf("Изход: %d\n", sum);

    return 0;
}

// 2.Да се състави програма, чрез която се въвеждат 7 цели числа от интервала [-5000..5000] в едномерен масив. Програмата да изведе най-голямото от въведените числа.

int zad2() {
    int arr[7];
    int max;
    printf("Въведете 7 цели числа в интервала [-5000..5000]:\n");
    for(int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
        while(arr[i] < -5000 || arr[i] > 5000) {
            printf("Грешка: Числото е извън интервала! Въведете отново: ");
            scanf("%d", &arr[i]);
        }
        if (i == 0 || arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Най-голямото число: %d\n", max);
    return 0;
}


// 3.Да се състави програма, чрез която се въвеждат 7 цели числа от интервала [-5000..5000] в едномерен масив. Програмата да изведе средната стойност на въведените числа.
int zad3() {
    int arr[7];
    int sum = 0;
    printf("Въведете 7 цели числа в интервала [-5000..5000]:\n");
    for(int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
        while(arr[i] < -5000 || arr[i] > 5000) {
            printf("Грешка: Числото е извън интервала! Въведете отново: ");
            scanf("%d", &arr[i]);
        }
        sum += arr[i];
    }
    double average = (double)sum / 7;
    printf("Средна стойност: %.2f\n", average);
    return 0;
}


// 4.Да се състави програма, чрез която се въвеждат 7 цели числа от интервала [-5000..5000] в едномерен масив. Програмата да изведе числото, което е най-близко до средната стойност на въведените числа и къде се намира.
int zad4() {
    int arr[7];
    int sum = 0;

    printf("Въведете 7 цели числа в интервала [-5000..5000]:\n");

    for(int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
        while(arr[i] < -5000 || arr[i] > 5000) {
            printf("Грешка: Числото е извън интервала! Въведете отново: ");
            scanf("%d", &arr[i]);
        }
        sum += arr[i];
    }

    double average = (double)sum / 7;
    double min_diff = -1;
    int closest_val = arr[0];
    int closest_index = 0;

    for(int i = 0; i < 7; i++) {
        double diff = average - arr[i];
        if (diff < 0) {
            diff = -diff;
        }
        
        if (i == 0 || diff < min_diff) {
            min_diff = diff;
            closest_val = arr[i];
            closest_index = i;
        }
    }

    printf("Средна стойност: %.2f\n", average);
    printf("Най-близко число: %d на индекс: %d\n", closest_val, closest_index);
    return 0;
}

// File 2 9lu

// 1.	Напишете функция, която намира дължината на низ без да ползвате вградените.
int custom_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int zad5() {
    char text[] = "Hello, World!";
    printf("%d\n", custom_strlen(text));
    return 0;
}
// 2.	Напишете програма, която намира броя на думите в низ
int zad6() {
    char str[] = "This is a simple test string";
    int words = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            words++;
        }
    }

    printf("%d\n", words);
    return 0;
}
// 3.	Напишете програма, която изкарва колко пъти се среща всяка буква в низ

int zad7() {
    char str[] = "Hello World!";
    int freq[26] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            freq[str[i] - 'A']++;
        } 
        else if (str[i] >= 'a' && str[i] <= 'z') {
            freq[str[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}
// 4.	Напишете програма, която сравнява два низа без да ползвате вградените функции
int zad8() {
    char str1[] = "Apple";
    char str2[] = "apple";
    int i = 0;
    
    while (str1[i] == str2[i] && str1[i] != '\0') {
        i++;
    }
    
    int result = str1[i] - str2[i];
    
    if (result == 0) {
        printf("Низовете са еднакви.\n");
    } else {
        printf("Низовете са различни. Разлика: %d\n", result);
    }
    
    return 0;
}
// 5.	Напишете функция, която връща броя на гласните в низ.
int count_vowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int zad9() {
    char str[] = "Programming in C";
    printf("Брой гласни: %d\n", count_vowels(str));
    return 0;
}
// 6.	Напишете програма, която заменя малките букви в низ с големи
int zad10() {
    char str[] = "make this uppercase!";
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    
    printf("%s\n", str);
    return 0;
}
