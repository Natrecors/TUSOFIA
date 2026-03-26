#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
 //ЗАДАЧА 1 (Активна в момента) 

 int main() {
    char symbol;
    printf("Въведете знак: ");
    scanf(" %c", &symbol);
    
    printf("\nИзход:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            if(i == 0 || i == 4 || j == 0 || j == 9) printf("%c", symbol);
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
 }

 
 //ЗАДАЧА 2 

// int main() {
//     float inches;
//     printf("Въведете инчове: ");
//     scanf("%f", &inches);
//     printf("%.2f мм (mm)\n", inches * 25.4);
//     printf("%.2f см (cm)\n", inches * 2.54);
//     printf("%.4f дм (dm)\n", inches * 0.254);
//     printf("%.4f м (m)\n", inches * 0.0254);
//     return 0;
// }

 
 //ЗАДАЧА 3 

 //int main() {
 //    float celsius;
 //    printf("Въведете градуси по Целзий: ");
 //    scanf("%f", &celsius);
 //    printf("Фаренхайт: %.2f\n", (celsius * 9.0 / 5.0) + 32.0);
 //    return 0;
 //}


  
 //ЗАДАЧА 4 

 //int main() {
 //    float degrees;
 //    printf("Въведете градуси: ");
 //    scanf("%f", &degrees);
 //    printf("Радиани: %.6f\n", degrees * 3.14159265 / 180.0);
 //    return 0;
 //}
 

  
 //ЗАДАЧА 5 

 //int main() {
 //    float bgn;
 //    printf("Въведете сума в левове: ");
 //    scanf("%f", &bgn);
 //    printf("Долари (USD): %.2f\n", bgn / 1.80);
 //    printf("Евро (EUR): %.2f\n", bgn / 1.95583);
 //    printf("Паундове (GBP): %.2f\n", bgn / 2.20);
 //    return 0;
 //}
 

  
 //ЗАДАЧА 6 

 //int main() {
 //    float a, b, h;
 //    printf("Въведете a, b и h на трапеца: ");
 //    scanf("%f %f %f", &a, &b, &h);
 //    printf("Лицето е: %.2f\n", (a + b) * h / 2.0);
 //    return 0;
 //}
 

  
 //ЗАДАЧА 7 

 //int main() {
 //    float x1, y1, x2, y2;
 //    printf("Въведете координати на точка А (x1 y1): ");
 //    scanf("%f %f", &x1, &y1);
 //    printf("Въведете координати на точка Б (x2 y2): ");
 //    scanf("%f %f", &x2, &y2);
    
 //    float width = fabs(x1 - x2);
 //    float height = fabs(y1 - y2);
 //    printf("Лицето на правоъгълника е: %.2f\n", width * height);
 //    return 0;
 //}
 


 //ЗАДАЧА 8 

 //int main() {
 //    float x1, y1, x2, y2, x3, y3;
 //    printf("Въведете координати на 3 точки (x1 y1 x2 y2 x3 y3): ");
 //    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    
 //    float area = fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
 //    printf("Лицето на триъгълника е: %.2f\n", area);
 //    return 0;
 //}
 

  
 //ЗАДАЧА 9

 //int main() {
 //    double w, h;
 //    printf("Въведете размери на залата w и h (в метри): ");
 //    scanf("%lf %lf", &w, &h);
    
 //    int rows = w / 1.2;
 //    int cols = (h - 1.0) / 0.7;
 //    int seats = (rows * cols) - 3;
    
 //    printf("Брой работни места: %d\n", seats);
 //    return 0;
 //}
 

  
 //ЗАДАЧА 10 

// int main() {
//     float veg_price, fruit_price;
//     int veg_kg, fruit_kg;
    
//     printf("Цена зеленчуци (лв/кг): "); scanf("%f", &veg_price);
//     printf("Цена плодове (лв/кг): "); scanf("%f", &fruit_price);
//     printf("Общо кг зеленчуци: "); scanf("%d", &veg_kg);
//     printf("Общо кг плодове: "); scanf("%d", &fruit_kg);
    
//     float total_bgn = (veg_price * veg_kg) + (fruit_price * fruit_kg);
//     printf("Приходи в евро: %.2f\n", total_bgn / 1.95);
//     return 0;
// }
 

  
 //ЗАДАЧА 11 

// int main() {
//     float N, W, L, M, O;
//     printf("Страна N: "); scanf("%f", &N);
//     printf("Плочка W L: "); scanf("%f %f", &W, &L);
//     printf("Пейка M O: "); scanf("%f %f", &M, &O);
    
//     float area_to_cover = (N * N) - (M * O);
//     float tiles_needed = area_to_cover / (W * L);
    
//     printf("Необходими плочки: %.2f\n", tiles_needed);
//     printf("Необходимо време: %.2f минути\n", tiles_needed * 0.2);
//     return 0;
// }
 

  
 //ЗАДАЧА 12 
// int main() {
//     int days;
//     float money_per_day, exchange_rate;
//     printf("Работни дни, пари на ден и курс на долара: ");
//     scanf("%d %f %f", &days, &money_per_day, &exchange_rate);
    
//     float monthly_salary = days * money_per_day;
//     float total_usd = (monthly_salary * 12) + (monthly_salary * 2.5);
//     float net_bgn = (total_usd * exchange_rate) * 0.75; 
    
//     printf("Средна чиста печалба на ден: %.2f лв.\n", net_bgn / 365.0);
//     return 0;
// }
 

  
 //ЗАДАЧА 13 
// int main() {
//     float a, b;
//     printf("Размери на двора a и b: ");
//     scanf("%f %f", &a, &b);
    
//     float min_side = (a < b) ? a : b; 
//     printf("Най-голям възможен радиус: %.2f\n", min_side / 2.0);
//     return 0;
// }
 

  
 //ЗАДАЧА 14 
// int main() {
//     float x, y, w;
//     printf("Размери на басейна x и y: ");
//     scanf("%f %f", &x, &y);
//     printf("Ширина на пътеката w: ");
//     scanf("%f", &w);
    
//     float outer_area = (x + 2 * w) * (y + 2 * w);
//     printf("Лицето на пътеката е: %.2f\n", outer_area - (x * y));
//     return 0;
// }
 

  
 //ЗАДАЧА 15 
// int main() {
//     int sum, coins = 0;
//     printf("Въведете сума в лева: ");
//     scanf("%d", &sum);
    
//     coins += sum / 10; sum %= 10;
//     coins += sum / 5;  sum %= 5;
//     coins += sum / 2;  sum %= 2;
//     coins += sum / 1;
    
//     printf("Минимален брой монети/банкноти: %d\n", coins);
//     return 0;
// }
 

  
 //ЗАДАЧА 16 
// int main() {
//     float L, x;
//     printf("Дължина на стената L: "); scanf("%f", &L);
//     printf("Метри на ден x: "); scanf("%f", &x);
    
//     int days = ceil(L / x);
//     printf("Необходими дни: %d\n", days);
//     return 0;
// }
 

  
 //ЗАДАЧА 17 
// int main() {
//     float x1, y1, x2, y2;
//     printf("Координати (x1 y1 x2 y2): ");
//     scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    
//     float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//     printf("Разстоянието е: %.2f\n", distance);
//     return 0;
// }
 

  
 //ЗАДАЧА 18 
// int main() {
//     float x1, y1, x2, y2;
//     printf("Координати (x1 y1 x2 y2): ");
//     scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    
//     printf("Координати на средата: (%.2f, %.2f)\n", (x1 + x2) / 2.0, (y1 + y2) / 2.0);
//     return 0;
// }
 

  
 //ЗАДАЧА 19 
// int main() {
//     int total_seconds;
//     printf("Въведете брой секунди: ");
//     scanf("%d", &total_seconds);
    
//     int hours = total_seconds / 3600;
//     int minutes = (total_seconds % 3600) / 60;
//     int seconds = total_seconds % 60;
    
//     printf("%d час(а), %d минута(и), %d секунда(и)\n", hours, minutes, seconds);
//     return 0;
// }
 

  
 //ЗАДАЧА 20 
// int main() {
//     char ch;
//     printf("Въведете символ: ");
//     scanf(" %c", &ch);
    
//     printf("Предишен символ: %c (ASCII: %d)\n", ch - 1, ch - 1);
//     printf("Следващ символ: %c (ASCII: %d)\n", ch + 1, ch + 1);
//     return 0;
// }
 

  
 //ЗАДАЧА 21 
// int main() {
//     char ch1, ch2;
//     printf("Въведете два символа: ");
//     scanf(" %c %c", &ch1, &ch2);
    
//     printf("Разликата между ASCII кодовете им е: %d\n", abs(ch1 - ch2));
//     return 0;
// }
 

  
// ЗАДАЧА 22 
// int main() {
//     int num;
//     printf("Въведете двуцифрено число: ");
//     scanf("%d", &num);
    
//     printf("Сумата от цифрите е: %d\n", (num / 10) + (num % 10));
//     return 0;
// }
 

  
// ЗАДАЧА 23 
// int main() {
//     int num;
//     printf("Въведете трицифрено число: ");
//     scanf("%d", &num);
    
//     int d1 = num / 100;
//     int d2 = (num / 10) % 10;
//     int d3 = num % 10;
    
//     printf("Обърнатото число е: %d\n", (d3 * 100) + (d2 * 10) + d1);
//     return 0;
// }
 
#include <stdio.h>

int main() {
    const char* numbers[] = {
        "Едно", "Две", "Три", "Четири", "Пет", 
        "Шест", "Седем", "Осем", "Девет", "Десет"
    };

    for(int i = 0; i < 10; i++) {
        printf("%s\n", numbers[i]);
    }

    return 0;
}


#include <stdio.h>

int main() {
    char symbol;

    printf("Вход: \n");
    scanf("%c", &symbol);

    printf("Изход:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            // Отпечатваме символа само по краищата на рамката
            if(i == 0  i == 4 
 j == 0 || j == 9) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
} 
#include <stdio.h>

int main() {
    double length_m, width_m;

    // Въвеждане на дължината и широчината в метри
    if (scanf("%lf %lf", &length_m, &width_m) != 2) {
        return 1;
    }

    // Преобразуване на метрите в сантиметри
    int length_cm = length_m * 100;
    int width_cm = width_m * 100;

    // Изчисляване на възможните редове (бюрата са дълги 120 см)
    int rows = length_cm / 120;

    // Изчисляване на бюрата на един ред (широки 70 см), като се изваждат 100 см за коридор
    int desks_per_row = (width_cm - 100) / 70;

    // Общият брой места е произведението от редовете и бюрата, минус 3 (за врата и катедра)
    int total_places = (rows * desks_per_row) - 3;

    printf("%d\n", total_places);

    return 0;
}
#include <stdio.h>

int main() {
    double N, W, L, M, O;

    // Въвеждане на размерите: страна на площадка, ширина/дължина на плочка, ширина/дължина на пейка
    scanf("%lf", &N);
    scanf("%lf %lf", &W, &L);
    scanf("%lf %lf", &M, &O);

    // Изчисляване на площите
    double total_area = N * N;
    double bench_area = M * O;
    double tile_area = W * L;

    // Площ за покриване (под пейката не се слагат плочки)
    double area_to_cover = total_area - bench_area;

    // Изчисляване на нужните плочки и времето
    double tiles_needed = area_to_cover / tile_area;
    double time_needed = tiles_needed * 0.2;

    printf("Необходими плочки: %.2f\n", tiles_needed);
    printf("Необходимо време: %.2f минути\n", time_needed);

    return 0;
}
#include <stdio.h>

int main() {
    // Отпечатва редове от 1 до 10 [cite: 3, 4, 12]
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    char symbol;
    printf("вход: ");
    scanf(" %c", &symbol); // [cite: 23]

    printf("изход:\n"); // [cite: 24]
    // Прав триъгълник
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", symbol);
        }
        printf("\n");
    }

    printf("\nОбърнат триъгълник:\n");
    // Обърнат триъгълник 
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", symbol);
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    double inches;
    printf("--- Конвертор на инчове ---\n");
    printf("Въведете стойност в инчове: ");
    scanf("%lf", &inches); // 

    double cm = inches * 2.54;

    printf("%.2f инча са:\n", inches);
    printf("- %.2f мм\n", cm * 10); // 
    printf("- %.2f см\n", cm); // 
    printf("- %.4f дм\n", cm / 10); // 
    printf("- %.4f м\n", cm / 100); // 
    return 0;
}
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    double celsius, angle_deg;

    // Целзий към Фаренхайт [cite: 32]
    printf("Въведете градуси по Целзий: ");
    scanf("%lf", &celsius);
    printf("По Фаренхайт: %.2f\n\n", (celsius * 9.0 / 5.0) + 32.0);

    // Градуси към радиани и тригонометрия [cite: 33, 36]
    printf("Въведете ъгъл в градуси: ");
    scanf("%lf", &angle_deg);

    double radians = angle_deg * (PI / 180.0);
    printf("В радиани: %.4f\n", radians); // [cite: 33]
    printf("Синус: %.4f\n", sin(radians)); // 
    printf("Косинус: %.4f\n", cos(radians)); // 
    printf("Тангенс: %.4f\n", tan(radians)); // 
    printf("Котангенс: %.4f\n", 1.0 / tan(radians)); // 

    return 0;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double x1, y1, x2, y2;
    double tx1, ty1, tx2, ty2, tx3, ty3;

    // Лице на правоъгълник 
    printf("Въведете координати на правоъгълник (x1 y1 x2 y2): ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    double rect_area = fabs(x1 - x2) * fabs(y1 - y2);
    printf("Лице на правоъгълника: %.2f\n\n", rect_area); // 

    // Лице на триъгълник 
    printf("Въведете координати на триъгълник (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &tx1, &ty1, &tx2, &ty2, &tx3, &ty3);
    double tri_area = 0.5 * fabs(tx1(ty2 - ty3) + tx2(ty3 - ty1) + tx3*(ty1 - ty2));
    printf("Лице на триъгълника: %.2f\n", tri_area); // 

    return 0;
}


int main() {
    double veg_price, fruit_price; // [cite: 52, 53]
    int veg_kg, fruit_kg; // [cite: 54, 55]

    scanf("%lf", &veg_price); // Първи ред [cite: 52]
    scanf("%lf", &fruit_price); // Втори ред [cite: 53]
    scanf("%d", &veg_kg); // Трети ред [cite: 54]
    scanf("%d", &fruit_kg); // Четвърти ред [cite: 55]

    double total_bgn = (veg_price * veg_kg) + (fruit_price * fruit_kg); // [cite: 49]
    double total_eur = total_bgn / 1.95; // 1 евро = 1.95 лв [cite: 50]

    printf("%.2f\n", total_eur); // [cite: 50]
    return 0;
}


int main() {
    int days_per_month;
    double money_per_day, usd_to_bgn_rate;

    // Четене на данни [cite: 70, 74]
    scanf("%d", &days_per_month); 
    scanf("%lf", &money_per_day);
    scanf("%lf", &usd_to_bgn_rate); // [cite: 74]

    double monthly_salary = days_per_month * money_per_day; // [cite: 70]
    double yearly_salary = monthly_salary * 12;
    double bonus = monthly_salary * 2.5; // [cite: 71]

    double total_income_usd = yearly_salary + bonus;
    double income_after_taxes_usd = total_income_usd * 0.75; // Удържат се 25% данъци [cite: 72]

    double total_income_bgn = income_after_taxes_usd * usd_to_bgn_rate; // [cite: 72]
    double avg_per_day_bgn = total_income_bgn / 365.0; // В годината има точно 365 дни [cite: 73]

    printf("%.2f\n", avg_per_day_bgn);
    return 0;
}