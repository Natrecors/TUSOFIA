#include <stdio.h>

int zad1();
int zad2();
int zad3();
int zad4();
int zad5();

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
            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n\n");
        }
    } while (choice != 0);

    return 0;
}
// 1. Извеждане на диагонали и елементи под/над главния диагонал
int zad1() {
    int n;
    printf("Въведете размерността N на матрицата (NxN): ");
    scanf("%d", &n);
    
    int arr[n][n];
    printf("Въведете елементите на матрицата:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n• Елементи на главния диагонал: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i][i]);
    }

    printf("\n• Елементи на второстепенния диагонал: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i][n - 1 - i]);
    }

    printf("\n• Елементи над главния диагонал: ");
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
    }

    printf("\n• Елементи под главния диагонал: ");
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n\n");
    return 0;
}

//2.	Направете програма, която проверява дали един квадрат е магически(сумите на числата във всички редове и колони да е равна на едно и също число). 
int zad2() {
    int n;
    printf("Въведете размерността N на матрицата (NxN): ");
    scanf("%d", &n);
    
    int arr[n][n];
    printf("Въведете елементите на матрицата:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int targetSum = 0;
    int isMagic = 1;

    for(int j = 0; j < n; j++){
        targetSum += arr[0][j];
    }

    for(int i = 1; i < n; i++) {
        int rowSum = 0;
        for(int j = 0; j < n; j++) rowSum += arr[i][j];
        if(rowSum != targetSum) isMagic = 0;
    }

    for(int j = 0; j < n; j++) {
        int colSum = 0;
        for(int i = 0; i < n; i++) colSum += arr[i][j];
        if(colSum != targetSum) isMagic = 0;
    }

    if (isMagic) {
        printf("\nКвадратът Е магически (сумата е %d).\n\n", targetSum);
    } else {
        printf("\nКвадратът НЕ Е магически.\n\n");
    }
    return 0;
}

//3.	Дадена е квадратна матрица n x n. Създай нова матрица, която е получена чрез завъртане на оригиналната на 90° по часовниковата стрелка.
int zad3() {
    int n;
    printf("Въведете размерността N на матрицата (NxN): ");
    scanf("%d", &n);
    
    int arr[n][n];
    int rotated[n][n];

    printf("Въведете елементите на матрицата:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            rotated[j][n - 1 - i] = arr[i][j];
        }
    }

    printf("\nЗавъртяна матрица:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", rotated[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

//4.	Да се създаде матрица m x n, която се запълва със стойности от 1 до m*n по следния начин:
int zad4() {
    int m, n;
    printf("Въведете брой редове (M) и колони (N): ");
    scanf("%d %d", &m, &n);
    
    int arr[m][n];
    int counter = 1;

    for(int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for(int j = 0; j < n; j++) {
                arr[i][j] = counter++;
            }
        } else {
            for(int j = n - 1; j >= 0; j--) {
                arr[i][j] = counter++;
            }
        }
    }

    printf("\nРезултатна матрица:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%3d ", arr[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

//5.	Дадена е основна матрица A[m][n] и по-малка матрица B[p][q]. Програмата трябва да провери дали B се съдържа като подматрица в A (т.е. всички нейни елементи да са в точно тази форма някъде в A).
int zad5() {
    int m, n, p, q;
    printf("Въведете размери на голямата матрица A (редове колони): ");
    scanf("%d %d", &m, &n);
    int a[m][n];
    printf("Въведете елементите на матрица A:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    }

    printf("\nВъведете размери на малката матрица B (редове колони): ");
    scanf("%d %d", &p, &q);
    int b[p][q];
    printf("Въведете елементите на матрица B:\n");
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < q; j++) scanf("%d", &b[i][j]);
    }

    int found = 0;

    for(int i = 0; i <= m - p; i++) {
        for(int j = 0; j <= n - q; j++) {
            
            int match = 1;
            for(int r = 0; r < p; r++) {
                for(int c = 0; c < q; c++) {
                    if(a[i + r][j + c] != b[r][c]) {
                        match = 0;
                        break;
                    }
                }
                if(!match) break;
            }

            if(match) {
                printf("\nИзход:\nМатрицата B се съдържа в A, започвайки от ред %d, колона %d.\n\n", i, j);
                found = 1;
                break;
            }
        }
        if(found) break;
    }

    if(!found) {
        printf("\nИзход:\nМатрицата B НЕ се съдържа в A.\n\n");
    }
    return 0;
}

