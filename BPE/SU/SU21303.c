#include <stdio.h>
#include <math.h>


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
int zad11(); 
int zad12(); 


double get_max(double a, double b) {
    if (a > b) return a;
    return b;
}

double get_min(double a, double b) {
    if (a < b) return a;
    return b;
}

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
            case 11: zad11(); break;
            case 12: zad12(); break;
           
            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n\n");
        }
    } while (choice != 0);

    return 0;
}

// 1.	Напишете функция, която получава две числа и връща по – голямото от тях. Направете същото и за по -  малкото. Демонстрирайте работата на функциите като четете множество числа до въвеждане на 0 и изкарате най – голямото въведено и най-малкото въведено число.

int zad1() {
    double number, max_number, min_number;

    printf("Въведете число (0 за край): ");
    scanf("%lf", &number);

    if (number == 0) {
        printf("Не са въведени числа за сравняване.\n\n");
    } else {
        max_number = number;
        min_number = number;

        while (1) {
            printf("Въведете число (0 за край): ");
            scanf("%lf", &number);
            
            if (number == 0) {
                break;
            }
            
            max_number = get_max(max_number, number);
            min_number = get_min(min_number, number);
        }

        printf("Най-голямото въведено число е: %g\n", max_number);
        printf("Най-малкото въведено число е: %g\n\n", min_number);
    }
    return 0;
}

// 2.	Да се напише програма, която чете час и минути от 24-часово денонощие, въведени от потребителя, и изчислява колко ще е часът след 15 минути. Резултатът да се отпечата във формат hh:mm. Часовете винаги са между 0 и 23, а минутите винаги са между 0 и 59. Часовете се изписват с една или две цифри. Минутите се изписват винаги с по две цифри, с водеща нула когато е необходимо. 
int zad2() {
    int hours, minutes;

    printf("Въведете час (0-23): ");
    scanf("%d", &hours);
    
    printf("Въведете минути (0-59): ");
    scanf("%d", &minutes);

    minutes += 15;

    if (minutes >= 60) {
        hours += 1;
        minutes -= 60; 
    }

    if (hours >= 24) {
        hours = 0;
    }

    printf("Времето след 15 минути е: %d:%02d\n\n", hours, minutes);
    return 0;
}

// 3.	Да се напише програма, която чете 3 числа и отпечатва дали са еднакви (yes / no).
int zad3() {
    double a, b, c;

    printf("Въведете три числа: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == b && b == c) {
        printf("yes\n\n");
    } else {
        printf("no\n\n");
    }

    return 0;
}

// 4.	Дадено е цяло число – брой точки. Върху него се начисляват бонус точки по правилата, описани по-долу. Да се напише програма, която пресмята бонус точките за това число и общия брой точки с бонусите.

int zad4() {
    int points;
    double bonus = 0.0;


    printf("Въведете брой точки: ");
    scanf("%d", &points);


    if (points <= 100) {
        bonus = 5;
    } else if (points > 1000) {
        bonus = points * 0.10; 
    } else {
        bonus = points * 0.20; 
    }


    if (points % 2 == 0) {
        bonus += 1; 
    } else if (points % 10 == 5) {
        bonus += 2; 
    }

    printf("Бонус точки: %g\n", bonus);
    printf("Общ брой точки: %g\n\n", points + bonus);

    return 0;
}

// 5.	Трима спортни състезатели финишират за някакъв брой секунди (между 1 и 50). Да се напише програма, която чете времената на състезателите, въведени от потребителя, и пресмята сумарното им време във формат "минути:секунди". Секундите да се изведат с водеща нула (2 🡪 "02", 7 🡪 "07", 35 🡪 "35"). 

int zad5() {
    int time1, time2, time3, total_time;
    int minutes, seconds;

    printf("Въведете времето на първия състезател: ");
    scanf("%d", &time1);
    printf("Въведете времето на втория състезател: ");
    scanf("%d", &time2);
    printf("Въведете времето на третия състезател: ");
    scanf("%d", &time3);

    total_time = time1 + time2 + time3;

    minutes = total_time / 60;
    
    seconds = total_time % 60;

    printf("%d:%02d\n\n", minutes, seconds);

    return 0;
}

//6.	Напишете програма, която проверява дали точка {x, y} се намира вътре в правоъгълник {x1, y1} – {x2, y2}. Входните данни се четат от конзолата и се състоят от 6 реда, въведени от потребителя: десетичните числа x1, y1, x2, y2, x и y (като се гарантира, че x1 < x2 и y1 < y2). Една точка е вътрешна за даден правоъгълник, ако се намира някъде във вътрешността му или върху някоя от страните му. Отпечатайте “Inside” или “Outside”.

int zad6() {
    double x1, y1, x2, y2, x, y;

    printf("Въведете x1: ");
    scanf("%lf", &x1);
    printf("Въведете y1: ");
    scanf("%lf", &y1);
    printf("Въведете x2: ");
    scanf("%lf", &x2);
    printf("Въведете y2: ");
    scanf("%lf", &y2);
    printf("Въведете x: ");
    scanf("%lf", &x);
    printf("Въведете y: ");
    scanf("%lf", &y);

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        printf("Inside\n\n");
    } else {
        printf("Outside\n\n");
    }

    return 0;
}
//7.	Студент трябва да пропътува n километра. Той има избор измежду три вида транспорт:
int zad7() {
    int n;
    char period;
    printf("Въведете брой километри (n) и част от деня ('D' за ден или 'N' за нощ) разделени с интервал: ");
    if (scanf("%d %c", &n, &period) != 2) {
        return 1;
    }

    double price = 0.0;

    if (n >= 100) {

        price = n * 0.06;
    } else if (n >= 20) {

        price = n * 0.09;
    } else {
        if (period == 'D') {
            price = 0.70 + (n * 0.79);
        } else if (period == 'N') {
            price = 0.70 + (n * 0.90);
        }
    }
    printf("%.2f\n", price);

    return 0;
}

//8.	Басейн с обем V(кубични  метра) има две тръби от които се пълни. Всяка тръба има определен дебит (литрите вода минаващи през една тръба за един час). Работникът пуска тръбите едновременно и излиза за N часа. Напишете програма, която изкарва състоянието на басейна, в момента, когато работникът се върне. 
int zad8() {
    int v, p1, p2;
    double n; 

    printf("Въведете обем на басейна (V), дебит на първа тръба (P1), дебит на втора тръба (P2) и часове отсъствие (N): ");

    if (scanf("%d %d %d %lf", &v, &p1, &p2, &n) != 4) {
        return 1;
    }

    double water_p1 = p1 * n;
    double water_p2 = p2 * n;
    double total_water = water_p1 + water_p2;

    if (total_water <= v) {
        double percent_full = (total_water / v) * 100.0;
        double percent_p1 = (water_p1 / total_water) * 100.0;
        double percent_p2 = (water_p2 / total_water) * 100.0;

        printf("Басейнът е пълен на %.2f%%. Тръба 1: %.2f%%. Тръба 2: %.2f%%.\n", 
               percent_full, percent_p1, percent_p2);
    } else {
        double overflow = total_water - v;
        printf("За %.2f часа басейнът преля с %.2f литра.\n", n, overflow);
    }

    return 0;
}


//9.	От лозе с площ X квадратни метри се заделя 40% от реколтата за производство на вино. От 1 кв.м лозе се изкарват Y килограма грозде. За 1 литър вино са нужни 2,5 кг. грозде. Желаното количество вино за продан е Z литра.Напишете програма, която пресмята колко вино може да се произведе и дали това количество е достатъчно. Ако е достатъчно, остатъкът се разделя по равно между работниците на лозето.

int zad9() {
    int x, z, workers;
    double y;
    printf("Въведете площ (X), кг грозде от кв.м. (Y), желани литри вино (Z) и брой работници: ");
    if (scanf("%d %lf %d %d", &x, &y, &z, &workers) != 4) {
        return 1;
    }

    double total_grapes = x * y;
    double grapes_for_wine = total_grapes * 0.40;
    double wine_produced = grapes_for_wine / 2.5;

    if (wine_produced >= z) {
        double leftover = wine_produced - z;
        double per_person = leftover / workers;

        printf("Общо вино: %.0f литри.\n", floor(wine_produced));
        printf("%.0f остващи литри: %.0f литър на човек.\n", ceil(leftover), ceil(per_person));
    } else {
        double needed = z - wine_produced;
        printf(" Нужни са още %.0f литри\n", floor(needed));
    }

    return 0;
}

//10.	Дадени са n цели числа в интервала [1…1000]. От тях някакъв процент p1 са под 200, друг процент p2 са от 200 до 399, друг процент p3 са от 400 до 599, друг процент p4 са от 600 до 799 и останалите p5 процента са от 800 нагоре. Да се напише програма, която изчислява и отпечатва процентите p1, p2, p3, p4 и p5.

int zad10() {
    int count_p1 = 0, count_p2 = 0, count_p3 = 0, count_p4 = 0, count_p5 = 0;
    int num, n;

    printf("Въведете броя на числата (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Невалиден брой числа.\n");
        while(getchar() != '\n'); // Изчистване на буфера при грешка
        return 1;
    }

    printf("Въведете %d цели числа:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        
        if (num < 200) {
            count_p1++;
        } else if (num < 400) {
            count_p2++;
        } else if (num < 600) {
            count_p3++;
        } else if (num < 800) {
            count_p4++;
        } else {
            count_p5++;
        }
    }

    printf("\nРезултати:\n");
    printf("%.2f%%\n", (count_p1 / (double)n) * 100.0);
    printf("%.2f%%\n", (count_p2 / (double)n) * 100.0);
    printf("%.2f%%\n", (count_p3 / (double)n) * 100.0);
    printf("%.2f%%\n", (count_p4 / (double)n) * 100.0);
    printf("%.2f%%\n", (count_p5 / (double)n) * 100.0);

    return 0;
}

//11.	Да се напише програма, която прочита от конзолата цяло число n, въведено от потребителя, и чертае крепост с ширина 2 * n колони и височина n реда като в примерите по-долу. Лявата и дясната колона във вътрешността си са широки n / 2.

void print_chars(char c, int count) {
    for (int i = 0; i < count; i++) {
        putchar(c);
    }
}

int zad11() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int col_width = n / 2;
    int mid_width = 2 * n - 2 * col_width - 4; //sreda

    //1 red
    putchar('/');
    print_chars('^', col_width);
    putchar('\\');
    print_chars('_', mid_width);
    putchar('/');
    print_chars('^', col_width);
    putchar('\\');
    putchar('\n');

    // tqlo
    for (int i = 1; i < n - 1; i++) {
        putchar('|');
        
        if (i == n - 2) {
            print_chars(' ', col_width + 1);
            print_chars('_', mid_width);
            print_chars(' ', col_width + 1);
        } else {
            print_chars(' ', 2 * n - 2);
        }
        
        putchar('|');
        putchar('\n');
    }

    putchar('\\');
    print_chars('_', col_width);
    putchar('/');
    print_chars(' ', mid_width);
    putchar('\\');
    print_chars('_', col_width);
    putchar('/');
    putchar('\n');

    return 0;
}

//12.	Да се напише програма, която прочита от конзолата цяло число n, въведено от потребителя, и чертае пеперуда с ширина 2 * n - 1 колони и височина 2 * (n - 2) + 1 реда като в примерите по-долу.  Лявата и дясната ѝ част са широки n - 1.
int zad12() {
    int n;
    printf("Въведете n: ");
    if (scanf("%d", &n) != 1) return 1;

    //gore
    for (int i = 1; i <= n - 2; i++) {
        if (i % 2 != 0) {
            print_chars('*', n - 2); printf("\\ /"); print_chars('*', n - 2);
        } else {
            print_chars('-', n - 2); printf("\\ /"); print_chars('-', n - 2);
        }
        printf("\n");
    }

    //tqlo
    print_chars(' ', n - 1);
    printf("@\n");

    //dolu
    for (int i = 1; i <= n - 2; i++) {
        if (i % 2 != 0) {
            print_chars('*', n - 2); printf("/ \\"); print_chars('*', n - 2);
        } else {
            print_chars('-', n - 2); printf("/ \\"); print_chars('-', n - 2);
        }
        printf("\n");
    }

    return 0;
}

