#include <stdio.h>
#include <limits.h>
#include <stdlib.h> 

int zad1();
int zad2();
int zad3();
int zad4();
int zad5();
int zad6();
int zad7();
int zad8();

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
            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n\n");
        }
    } while (choice != 0);

    return 0;
}

// 1. Даден е двумерен масив NxM запълнен с цели числа. Проверете дали всеки ред съдържа числа, подредени в нарастващ ред, а всяка колона съдържа числа подредени в намаляващ ред.
int zad1() {
    int n, m;
    printf("Въведете брой редове N: ");
    scanf("%d", &n);
    printf("Въведете брой колони M: ");
    scanf("%d", &m);

    int matrix[n][m];
    printf("Въведете елементите на матрицата:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isValid = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (matrix[i][j] > matrix[i][j+1]) {
                isValid = 0;
                break;
            }
        }
        if (!isValid) break;
    }

    if (isValid) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (matrix[i][j] < matrix[i+1][j]) {
                    isValid = 0;
                    break;
                }
            }
            if (!isValid) break;
        }
    }

    if (isValid) {
        printf("Резултат: Условието е ИЗПЪЛНЕНО.\n");
    } else {
        printf("Резултат: Условието НЕ Е изпълнено.\n");
    }

    return 0;
}

// 2. Даден е масив NxM запълнен с цели числа. Намерете числото, което има околни на него сбора, на които е най-голям. (околно е всяко число което се намира до, над, под или по диагонал на текущото на отстояние не повече от 1 поле).
int zad2() {
    int n, m;
    printf("Въведете брой редове N: ");
    scanf("%d", &n);
    printf("Въведете брой колони M: ");
    scanf("%d", &m);

    int matrix[n][m];
    printf("Въведете елементите на матрицата:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxSum = INT_MIN;
    int bestNum = 0;
    int bestRow = 0, bestCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int currentSum = 0;

            for (int r = i - 1; r <= i + 1; r++) {
                for (int c = j - 1; c <= j + 1; c++) {
                    if (r == i && c == j) continue;
                    
                    if (r >= 0 && r < n && c >= 0 && c < m) {
                        currentSum += matrix[r][c];
                    }
                }
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestNum = matrix[i][j];
                bestRow = i;
                bestCol = j;
            }
        }
    }

    if (n > 0 && m > 0) {
        printf("Числото с най-голяма сума на околните елементи е: %d (на позиция ред %d, колона %d)\n", bestNum, bestRow, bestCol);
        printf("Сумата на околните елементи е: %d\n", maxSum);
    } else {
        printf("Матрицата е празна.\n");
    }

    return 0;
}

// 3. Дадена е матрица NxM запълнена с цели числа. Разменете редовете с най-голям и най-малък елемент.
int zad3() {
    int n, m;
    printf("Въведете брой редове N: ");
    scanf("%d", &n);
    printf("Въведете брой колони M: ");
    scanf("%d", &m);

    int matrix[n][m];
    int min_val = INT_MAX, max_val = INT_MIN;
    int min_row = 0, max_row = 0;

    printf("Въведете елементите на матрицата:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
                min_row = i;
            }
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_row = i;
            }
        }
    }

    if (min_row != max_row) {
        for (int j = 0; j < m; j++) {
            int temp = matrix[min_row][j];
            matrix[min_row][j] = matrix[max_row][j];
            matrix[max_row][j] = temp;
        }
        printf("Разменени бяха ред %d (най-малък елемент %d) и ред %d (най-голям елемент %d).\n", min_row + 1, min_val, max_row + 1, max_val);
    } else {
        printf("Най-малкият и най-големият елемент са на един и същ ред (%d). Няма промяна.\n", min_row + 1);
    }

    printf("Матрицата след проверката/размяната:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 4. В училището на Ели има 1 ≤ N ≤ 100,000 човека. Някои от тях се познават с други, като Ели знае, че съществуват 1 ≤ M ≤ 1,000,000 такива приятелства. Тя иска да напише програма, която бързо отговаря кои са приятелите на даден човек. Ако хората се подават с номера като цяло число, както и приятелите им изведете при поискан човек колко приятели има. (ако 1 е приятел с 3 то и 3 е приятел с 1).

typedef struct Node {
    int friend_id;
    struct Node* next;
} Node;

Node* friends[100005];       
int friends_count[100005];   

void add_friend(int person, int his_friend) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->friend_id = his_friend;
    
    new_node->next = friends[person];
    friends[person] = new_node;
    
    friends_count[person]++;
}

int zad4() {
    int n, m;
    printf("Въведете брой хора (N): ");
    scanf("%d", &n);
    
    printf("Въведете брой приятелства (M): ");
    scanf("%d", &m);

    for (int i = 0; i <= n; i++) {
        friends[i] = NULL;
        friends_count[i] = 0;
    }

    if (m > 0) {
        printf("Въведете %d двойки приятели:\n", m);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            add_friend(u, v);
            add_friend(v, u);
        }
    }

    int query;
    printf("Въведете номер на човек, за да видите приятелите му: ");
    scanf("%d", &query);

    printf("Човек номер %d има %d приятел(и).\n", query, friends_count[query]);

    if (friends_count[query] > 0) {
        printf("Негови приятели са: ");
        
        Node* current = friends[query];
        while (current != NULL) {
            printf("%d ", current->friend_id);
            current = current->next;
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++) {
        Node* current = friends[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}

//5. Наум пише софтуер за малки деца, който има следните команди:
    // 1: add(x) - добавяне на елемент Х към съществуващите до момента
    // 2: delete(x) – изтрива всички срещания на елемента Х
    // 3: smallest(x)  принтира Х тото най-малко число от наличните
// Помогнете на Наум да напише своя софтуер, ако знаете, че Х е цяло число.

int zad5() {
    int *arr = (int *)malloc(100000 * sizeof(int)); 
    int size = 0;
    int cmd;
    printf("Команди:\n");
    printf(" 1 <число> : add(x) - добавя елемент\n");
    printf(" 2 <число> : delete(x) - изтрива всички срещания\n");
    printf(" 3 <число> : smallest(x) - принтира Х-тото най-малко число\n");
    printf(" 0 : Изход към главното меню\n");
    
    while (1) {
        printf("\nВъведете команда: ");
        scanf("%d", &cmd);
        
        if (cmd == 0) break;

        int x;
        scanf("%d", &x);

        if (cmd == 1) {
            int pos = size;
            while (pos > 0 && arr[pos - 1] > x) {
                arr[pos] = arr[pos - 1];
                pos--;
            }
            arr[pos] = x;
            size++;
            printf("Успешно добавено числото %d.\n", x);

        } else if (cmd == 2) {
            int new_size = 0;
            int deleted = 0;
            for (int i = 0; i < size; i++) {
                if (arr[i] != x) {
                    arr[new_size++] = arr[i];
                } else {
                    deleted++;
                }
            }
            size = new_size;
            if (deleted > 0) {
                printf("Изтрити са %d срещания на числото %d.\n", deleted, x);
            } else {
                printf("Числото %d не е намерено.\n", x);
            }

        } else if (cmd == 3) {
            if (x > 0 && x <= size) {
                printf("=> %d-тото най-малко число е: %d\n", x, arr[x - 1]);
            } else {
                printf("=> Грешка: Няма достатъчно елементи (в момента има %d).\n", size);
            }

        } else {
            printf("Невалидна команда.\n");
        }

        printf("Текущи числа в масива: ");
        if (size == 0) {
            printf("[ Празен ]\n");
        } else {
            printf("[ ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("]\n");
        }
    }

    free(arr);
    return 0;
}

// 6. Създайте динамичен масив от цели числа с n на брой елементи,като n и стойностите на елементите се четат от клавиатурата. Изтрийте простите числа от този масив и създайте втори динамичен масив, в който ги записвате . Принтирайте двата масива. 

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int zad6() {
    int n;
    printf("Въведете броя на елементите (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Невалиден брой елементи.\n");
        return 1;
    }

    int *originalArray = (int *)malloc(n * sizeof(int));
    if (originalArray == NULL) {
        printf("Грешка при заделяне на памет!\n");
        return 1;
    }
    
    printf("Въведете %d елемента:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &originalArray[i]);
    }

    int primeCount = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(originalArray[i])) {
            primeCount++;
        }
    }

    int nonPrimeCount = n - primeCount;

    int *primesArray = NULL;
    if (primeCount > 0) {
        primesArray = (int *)malloc(primeCount * sizeof(int));
    }

    int *tempArray = NULL;
    if (nonPrimeCount > 0) {
        tempArray = (int *)malloc(nonPrimeCount * sizeof(int));
    }

    int primeIndex = 0;
    int nonPrimeIndex = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime(originalArray[i])) {
            primesArray[primeIndex++] = originalArray[i];
        } else {
            tempArray[nonPrimeIndex++] = originalArray[i];
        }
    }
    
    free(originalArray);
    originalArray = tempArray;

    printf("\nМасив без простите числа: ");
    if (nonPrimeCount == 0) {
        printf("Празен");
    } else {
        for (int i = 0; i < nonPrimeCount; i++) {
            printf("%d ", originalArray[i]);
        }
    }
    printf("\n");

    printf("Масив само с простите числа: ");
    if (primeCount == 0) {
        printf("Празен");
    } else {
        for (int i = 0; i < primeCount; i++) {
            printf("%d ", primesArray[i]);
        }
    }
    printf("\n");

    if (originalArray != NULL) free(originalArray);
    if (primesArray != NULL) free(primesArray);

    return 0;
}

// 7. Да се напише програма, която създава правоъгълна матрица с размер  n на m . Размерността и стойностите за елементите се въвеждат от клавиатурата. Да се намери подматрица с размер 3х3, която има максимална сума. Принтирайте подматрицата.
int zad7() {
    int n, m;
    printf("Въведете брой редове N: ");
    scanf("%d", &n);
    printf("Въведете брой колони M: ");
    scanf("%d", &m);

    if (n < 3 || m < 3) {
        printf("Матрицата трябва да е с размер минимум 3x3 за тази задача!\n");
        return 0;
    }

    int matrix[n][m];
    printf("Въведете елементите на матрицата:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxSum = INT_MIN;
    int bestRow = 0, bestCol = 0;

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            int currentSum = 0;
            
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    currentSum += matrix[r][c];
                }
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    printf("\nНай-голямата сума от 3x3 подматрица е: %d\n", maxSum);
    printf("Подматрицата е:\n");
    for (int i = bestRow; i < bestRow + 3; i++) {
        for (int j = bestCol; j < bestCol + 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 8. Потребителя въвежда 10 числа в динамичен масив. След това въвежда числа, като с всяко въведено число указва индекса, където да бъде вмъкнато това число (числото избутва останалите) . Въвеждането спира при вход 0.
int zad8() {
    int size = 10;
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Въведете 10 начални числа:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        int val, idx;
        printf("\nВъведете стойност за вмъкване (0 за край): ");
        scanf("%d", &val);
        
        if (val == 0) {
            break;
        }

        printf("Въведете индекс (от 0 до %d), на който да бъде вмъкнато: ", size);
        scanf("%d", &idx);

        if (idx < 0 || idx > size) {
            printf("Невалиден индекс! Моля, опитайте отново.\n");
            continue;
        }
        size++;
        int *temp = (int *)realloc(arr, size * sizeof(int));
        if (temp != NULL) {
            arr = temp;
        } else {
            printf("Грешка при заделяне на памет!\n");
            free(arr);
            return 1;
        }

        for (int i = size - 1; i > idx; i--) {
            arr[i] = arr[i - 1];
        }
        
        arr[idx] = val;

        printf("Текущ масив: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}