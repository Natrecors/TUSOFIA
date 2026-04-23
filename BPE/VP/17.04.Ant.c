#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    float x;
    float y;
    float z;
} Point;

typedef struct {
    int power;
} Engine;

typedef struct {
    char name[20];
    int maxSpeed;
    Engine engine; 
} Vehicle;

typedef struct {
    char name[20];
    float grade;
} Student;

typedef struct {
    Student students[30]; 
} SchoolClass;

typedef struct {
    SchoolClass classA;
    SchoolClass classB;
} Vipusk;

void zad1() {
    Point p[3];

    for(int i = 0; i < 3; i++) {
        printf("Въведете x, y, z за точка %d (с интервали): ", i + 1);
        scanf("%f %f %f", &p[i].x, &p[i].y, &p[i].z);
    }

    float a = sqrt(pow(p[1].x - p[0].x, 2) + pow(p[1].y - p[0].y, 2) + pow(p[1].z - p[0].z, 2));
    float b = sqrt(pow(p[2].x - p[1].x, 2) + pow(p[2].y - p[1].y, 2) + pow(p[2].z - p[1].z, 2));
    float c = sqrt(pow(p[0].x - p[2].x, 2) + pow(p[0].y - p[2].y, 2) + pow(p[0].z - p[2].z, 2));

    printf("Страните на триъгълника са:\n");
    printf("A = %.2f, B = %.2f, C = %.2f\n", a, b, c);
}

void zad2() {
    Vehicle fleet[4];
    char types[4][20] = {"Кола", "Мотор", "Лодка", "Самолет"};

    for(int i = 0; i < 4; i++) {
        printf("Въведете данни за %s:\n", types[i]);
        strcpy(fleet[i].name, types[i]);
        
        printf("Максимална скорост (км/ч): ");
        scanf("%d", &fleet[i].maxSpeed);
        
        printf("Мощност на двигателя (к.с.): ");
        scanf("%d", &fleet[i].engine.power);
        printf("\n");
    }

    int maxIndex = 0;
    for(int i = 1; i < 4; i++) {
        if(fleet[i].maxSpeed > fleet[maxIndex].maxSpeed) {
            maxIndex = i;
        }
    }

    printf("Най-бързото превозно средство е: %s със скорост %d км/ч.\n", 
           fleet[maxIndex].name, fleet[maxIndex].maxSpeed);
}

void zad3() {
    Vipusk myVipusk;
    float sumA = 0, sumB = 0;
    int countA, countB;

    printf("Колко ученика искате да въведете за Клас А? (макс 30): ");
    scanf("%d", &countA);
    
    if(countA > 30) countA = 30; 
    if(countA < 0) countA = 0;

    for(int i = 0; i < countA; i++) {
        printf("Име на ученик %d от Клас А: ", i + 1);
        scanf("%s", myVipusk.classA.students[i].name);
        printf("Бал: ");
        scanf("%f", &myVipusk.classA.students[i].grade);
        
        sumA += myVipusk.classA.students[i].grade;
    }

    printf("\nКолко ученика искате да въведете за Клас Б? (макс 30): ");
    scanf("%d", &countB);
    
    if(countB > 30) countB = 30; 
    if(countB < 0) countB = 0;

    for(int i = 0; i < countB; i++) {
        printf("Име на ученик %d от Клас Б: ", i + 1);
        scanf("%s", myVipusk.classB.students[i].name);
        printf("Бал: ");
        scanf("%f", &myVipusk.classB.students[i].grade);
        
        sumB += myVipusk.classB.students[i].grade;
    }

    float avgA = (countA > 0) ? (sumA / countA) : 0;
    float avgB = (countB > 0) ? (sumB / countB) : 0;
    
    int totalStudents = countA + countB;
    float totalAvg = (totalStudents > 0) ? ((sumA + sumB) / totalStudents) : 0;

    if(countA > 0) printf("Среден бал на Клас А (%d ученици): %.2f\n", countA, avgA);
    else printf("За Клас А няма въведени ученици.\n");

    if(countB > 0) printf("Среден бал на Клас Б (%d ученици): %.2f\n", countB, avgB);
    else printf("За Клас Б няма въведени ученици.\n");

    if(totalStudents > 0) printf("ОБЩ среден бал на випуска (%d ученици общо): %.2f\n", totalStudents, totalAvg);
    else printf("Няма въведени ученици във випуска.\n");
}

typedef struct {
    char title[100];
    char author[100];
    int year;
    double price;
} Book;

void analyze_books(Book books[], int size) {
    if (size == 0) return;

    int min_idx = 0;
    int max_idx = 0;
    double sum_price = 0.0;

    for (int i = 0; i < size; i++) {
        if (books[i].price < books[min_idx].price) {
            min_idx = i;
        }
        if (books[i].price > books[max_idx].price) {
            max_idx = i;
        }
        sum_price += books[i].price;
    }

    double avg_price = sum_price / size;

    printf("Най-евтина книга: \"%s\" от %s (%.2f €).\n", 
           books[min_idx].title, books[min_idx].author, books[min_idx].price);
    
    printf("Най-скъпа книга: \"%s\" от %s (%.2f €).\n", 
           books[max_idx].title, books[max_idx].author, books[max_idx].price);
           
    printf("Средна цена на всички книги: %.2f €.\n", avg_price);
}

int zad4() {
    Book library[5] = {
        {"Под игото", "Иван Вазов", 1894, 7.80},
        {"Тютюн", "Димитър Димов", 1951, 11.00},
        {"Железният светилник", "Димитър Талев", 1952, 9.70},
        {"Бай Ганьо", "Алеко Константинов", 1895, 6.00},
        {"Осъдени души", "Димитър Димов", 1945, 9.85}
    };


    analyze_books(library, 5);

    return 0;
}


int main(){
    int choice;
    do {
        printf("\nВъведете номер на задача (0 за изход): ");
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

// 1.	Съставете структура за точка в пространството. Направете масив от точки и ги попълнете с данни. Направете триъгълници със зададените точки и намерете страните на триъгълниците.
// 2.	Направете структура за превозно средство с подходящи полета. Направете втора структура за различен тип превозни средства и попълнете данните за променливи от вид кола, мотор лодка и самолет. Сравнявайте различните средства по характеристика по избор.
// 3.	Направете масив от елементи с тип структура за ученици. Направете структура за випуск с няколко класа.  Въведете данни за учениците от един клас и изчислете средния бал на групата. Изчислете средния бал на випуска. 
//4. Сьздайте структура Book, която сьдържа следната информация:
// • заглавие (низ),
// • автор (низ),
// • година на издаване (яло число),
// • цена (реално число).
// Направете масив от книги (примерно 5). Попълнете данни за тях.
// Напишете функция, която:
// • извежда информацията за най-евтината и най-скопата книга.
// • намира средната цена на всички книги.
