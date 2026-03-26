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
int zad13();
int zad14();
int zad15(); 
int zad16(); 

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
            case 13: zad13(); break;
            case 14: zad14(); break;
            case 15: zad15(); break;
            case 16: zad16(); break;
            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n");
        }
    } while (choice != 0);

    return 0;
}

// Зад 1. Напишете програма, която отпечатва числата от 1 до 10 като текст;
int zad1() {
    int num;
    printf("Въведете число от 1 до 10: ");
    scanf("%d", &num);
    
    switch(num) {
        case 1: printf("Едно\n"); break;
        case 2: printf("Две\n"); break;
        case 3: printf("Три\n"); break;
        case 4: printf("Четири\n"); break;
        case 5: printf("Пет\n"); break;
        case 6: printf("Шест\n"); break;
        case 7: printf("Седем\n"); break;
        case 8: printf("Осем\n"); break;
        case 9: printf("Девет\n"); break;
        case 10: printf("Десет\n"); break;
        default: printf("Невалидно число!\n");
    }
    
    return 0;
}

// Зад 2. Напишете програма, която отпечатва триъгълник от 55 звездички:
int zad2() {
    int i, j;

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

// Зад 3. Напишете програма, която отпечатва рамка с размер 10х5 изградена от знак, въведен от потребителя:
int zad3() {
    char symbol;
    int width = 10;
    int height = 5;

    printf("Въведете знак за рамката (Enter a character for the frame): ");
    scanf(" %c", &symbol);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            if (i == 1 || i == height || j == 1 || j == width) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

// Зад 4. Направете програма, която рисува триъгълник с въведен знак от потребителя:
int zad4() {
    char symbol[10];
    int n = 5;

    printf("вход: ");
    scanf("%9s", symbol);

    printf("изход:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        if (i == 0) {
            printf("%s\n", symbol);
        } else if (i == n - 1) {
            for (int j = 0; j < 2 * n - 1; j++) {
                printf("%s", symbol);
            }
            printf("\n");
        } else {
            printf("%s", symbol);
            for (int j = 0; j < 2 * i - 1; j++) {
                printf(" ");
            }
            printf("%s\n", symbol);
        }
    }

    printf("\nНаобратно:\n");

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        if (i == 0) {
            printf("%s\n", symbol);
        } else if (i == n - 1) {
            for (int j = 0; j < 2 * n - 1; j++) {
                printf("%s", symbol);
            }
            printf("\n");
        } else {
            printf("%s", symbol);
            for (int j = 0; j < 2 * i - 1; j++) {
                printf(" ");
            }
            printf("%s\n", symbol);
        }
    }

    return 0;
}

// 5. Конвертор инчове в мм,см,дм и м.
int zad5(){
    double inches;
    printf("Конвертор на дължина\n");
    printf("Въведете дължина в инчове: ");
    scanf("%lf", &inches);

    printf("\n%.2f инча са равни на:\n", inches);
    printf("- %.2f милиметра (mm)\n", inches * 25.4);
    printf("- %.2f сантиметра (cm)\n", inches * 2.54);
    printf("- %.2f дециметра (dm)\n", inches * 0.254);
    printf("- %.4f метра (m)\n", inches * 0.0254);

    return 0;
}

// 6. Градуси по Целзий в Фаренхайт
int zad6() {
    double celsius, fahrenheit;

    printf("Въведете градуси по Целзий (°C): ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    printf("\nРезултат: %.2f °C = %.2f °F\n", celsius, fahrenheit);

    return 0;
}

// 7. Конвертор от градуси в радиани
int zad7() {
    double degrees, radians;
    float pi = 3.14159265358979323846;
    printf("Въведете ъгъл в градуси: ");
    scanf("%lf", &degrees);

    radians = degrees * pi / 180.0;

    printf("\nРезултат: %.2f градуса = %.6f радиана\n", degrees, radians);

    return 0;
}

// 8. Конвертор от левове в долари, евро и паундове
int zad8() {
    double bgn;

    double rate_eur = 1.95583; 
    double rate_usd = 1.17;    
    double rate_gbp = 0.87;    

    printf("Въведете сума в левове (BGN): ");
    scanf("%lf", &bgn);

    printf("\n%.2f лв. са равни на:\n", bgn);
    printf("- %.2f EUR (Евро)\n", bgn / rate_eur);
    printf("- %.2f USD (Щатски долар)\n", bgn / rate_usd);
    printf("- %.2f GBP (Британски паунд)\n", bgn / rate_gbp);

    return 0;
}

// 9. Лице на трапец
int zad9(){
    float a,b,h,s;
    printf("Въведете a: ");
    scanf("%f", &a);
    printf("Въведете b: ");
    scanf("%f", &b);
    printf("Въведете h: ");
    scanf("%f", &h);
    
    if (a <= 0 || b <= 0 || h <= 0) {
        printf("Грешка: Параметрите трябва да бъдат положителни числа!\n");
    } else {
        s = ((a + b) / 2) * h;
        printf("\nЛицето на трапеца е: %.2f\n", s);
    }

    return 0;
}

// 10. Тригонометрични функции
int zad10(){
    double degrees, radians;
    printf("Въведете градуси на ъгъл: ");
    scanf("%lf", &degrees);
    float pi = 3.14159265358979323846;

    radians = degrees * (pi / 180.0);

    printf("Синус (sin): %.4f\n", sin(radians));
    printf("Косинус (cos): %.4f\n", cos(radians));
    printf("Тангенс (tan): %.4f\n", tan(radians));
    printf("Котангенс (cot): %.4f\n", 1.0 / tan(radians));

    return 0;
}

// 11. Лице на правоъгълник по координатите на два срещуположни ъгъла
int zad11() {
    double x1, y1, x2, y2, width, height, area;
    printf("Въведете координати на точка A (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Въведете координати на точка B (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);
    
    width = fabs(x1 - x2);
    height = fabs(y1 - y2);
    area = width * height;
    
    printf("Лицето на правоъгълника е: %.2lf\n", area);
    return 0;
}

// 12. Лице на триъгълник по координатите на три точки
int zad12() {
    double x1, y1, x2, y2, x3, y3, area;
    printf("Въведете координати на точка 1 (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Въведете координати на точка 2 (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Въведете координати на точка 3 (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);

    area = fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    
    printf("Лицето на триъгълника е: %.2lf\n", area);
    return 0;
}

// 13. Учебна зала
int zad13() {
    double w, h;
    printf("Въведете w и h в метри (разделени с интервал): ");
    scanf("%lf %lf", &w, &h);
    
    int w_cm = round(w * 100);
    int h_cm = round(h * 100);
    int rows = w_cm / 120;
    int cols = (h_cm - 100) / 70;
    int total_places = (rows * cols) - 3;

    printf("Брой работни места: %d\n", total_places);

    return 0;
}

// 14. Градинар
int zad14(){
    double veg_price, fruit_price;
    int veg_kg, fruit_kg;

    printf("Въведете цена на зеленчуци за кг: ");
    scanf("%lf", &veg_price);
    printf("Въведете цена на плодове за кг: ");
    scanf("%lf", &fruit_price);
    printf("Въведете килограми зеленчуци: ");
    scanf("%d", &veg_kg);
    printf("Въведете килограми плодове: ");
    scanf("%d", &fruit_kg);

    double veg_total_bgn = veg_price * veg_kg;
    double fruit_total_bgn = fruit_price * fruit_kg;
    double total_bgn = veg_total_bgn + fruit_total_bgn;

    double total_eur = total_bgn / 1.95;

    printf("Приходи в евро: %.2f\n", total_eur);

    return 0;
}

// 15. Поставяне на плочки
int zad15() {
    double N, W, L, M, O;
    
    printf("Въведете дължина на страната на площадката (N): ");
    scanf("%lf", &N);
    printf("Въведете широчина на плочка (W): ");
    scanf("%lf", &W);
    printf("Въведете дължина на плочка (L): ");
    scanf("%lf", &L);
    printf("Въведете широчина на пейката (M): ");
    scanf("%lf", &M);
    printf("Въведете дължина на пейката (O): ");
    scanf("%lf", &O);

    double playground_area = N * N;
    double bench_area = M * O;
    double tile_area = W * L;
    
    double area_to_cover = playground_area - bench_area;
    double tiles_needed = area_to_cover / tile_area;
    double time_needed = tiles_needed * 0.2;

    printf("\nПлощ за покриване: %.2lf кв.м.\n", area_to_cover);
    printf("Необходими плочки: %.2lf\n", tiles_needed);
    printf("Необходимо време: %.2lf минути\n", time_needed);

    return 0;
}

// 16. Иван програмистът
int zad16() {
    int work_days_per_month;
    double daily_earnings_usd, usd_to_bgn_rate;

    printf("Работни дни в месеца (N): ");
    scanf("%d", &work_days_per_month);
    printf("Изкарани долари на ден (M): ");
    scanf("%lf", &daily_earnings_usd);
    printf("Курс на долара спрямо лева: ");
    scanf("%lf", &usd_to_bgn_rate);

    double monthly_salary_usd = work_days_per_month * daily_earnings_usd;
    double annual_salary_usd = monthly_salary_usd * 12;
    double bonus_usd = monthly_salary_usd * 2.5;
    double total_gross_usd = annual_salary_usd + bonus_usd;
    
    double net_income_usd = total_gross_usd * 0.75; 
    
    double net_income_bgn = net_income_usd * usd_to_bgn_rate;
    double avg_daily_profit_bgn = net_income_bgn / 365.0;

    printf("\nЧиста средна печалба на ден: %.2lf лв.\n", avg_daily_profit_bgn);

    return 0;
}