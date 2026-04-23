#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char name[100];
    double price;
    int id;
    int used;
} Product;

typedef struct {
    char address[200];
    int product_id;
    int fulfilled;
} Order;

typedef struct {
    int id;
    double hourly_rate;
    int hours_worked;
    double weekly_salary;
} Employee;

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
            case 0: printf("Край на програмата.\n"); break;
            default: printf("Невалиден избор! Опитайте отново.\n\n");
        }
    } while (choice != 0);

    return 0;
}

int zad1() {
    int guests;
    char item[50];
    double spent = 0.0;
    
    int b_table = 0, b_chair = 0, b_cups = 0, b_dishes = 0;
    
    printf("Въведете брой гости: ");
    scanf("%d", &guests);
    
    int req_tables = (guests + 7) / 8;
    int req_chairs = guests;
    int req_cups = (guests + 5) / 6;
    int req_dishes = (guests + 5) / 6;
    
    printf("Въвеждайте предмети (table, chair, cups, dishes) или 'party!':\n");
    
    while(1) {
        scanf("%s", item);
        if(strcmp(item, "party!") == 0) break;
        
        if(strcmp(item, "table") == 0) { b_table++; spent += 42.00; }
        else if(strcmp(item, "chair") == 0) { b_chair++; spent += 13.99; }
        else if(strcmp(item, "cups") == 0) { b_cups++; spent += 5.98; }
        else if(strcmp(item, "dishes") == 0) { b_dishes++; spent += 21.02; }
    }
    
    printf("%.2f\n", spent);
    
    if (req_tables > b_table) {
        int diff = req_tables - b_table;
        printf("%d Table%s\n", diff, diff > 1 ? "s" : "");
    }
    if (req_chairs > b_chair) {
        int diff = req_chairs - b_chair;
        printf("%d Chair%s\n", diff, diff > 1 ? "s" : "");
    }
    if (req_cups > b_cups) {
        int diff = req_cups - b_cups;
        printf("%d Cups\n", diff);
    }
    if (req_dishes > b_dishes) {
        int diff = req_dishes - b_dishes;
        printf("%d Dishes\n", diff);
    }
    return 0;
}

int zad2() {
    Product products[100];
    Order orders[100];
    int p_count = 0;
    int o_count = 0;
    char cmd[20];
    
    printf("Въвеждайте команди (product, order, end):\n");
    
    while(scanf(" %s", cmd) != EOF) {
        if(strcasecmp(cmd, "end") == 0) break;
        
        if(strcasecmp(cmd, "product") == 0) {
            while(getchar() != '\n'); 
            
            fgets(products[p_count].name, 100, stdin);
            products[p_count].name[strcspn(products[p_count].name, "\n")] = 0;
            
            scanf("%lf", &products[p_count].price);
            scanf("%d", &products[p_count].id);
            products[p_count].used = 0;
            
            for(int i = 0; i < o_count; i++) {
                if(!orders[i].fulfilled && orders[i].product_id == products[p_count].id) {
                    printf("Client %s ordered %s\n", orders[i].address, products[p_count].name);
                    orders[i].fulfilled = 1;
                    products[p_count].used = 1;
                    break;
                }
            }
            p_count++;
        } 
        else if (strcasecmp(cmd, "order") == 0) {
            while(getchar() != '\n');
            
            fgets(orders[o_count].address, 200, stdin);
            orders[o_count].address[strcspn(orders[o_count].address, "\n")] = 0;
            
            scanf("%d", &orders[o_count].product_id);
            orders[o_count].fulfilled = 0;
            
            for(int i = 0; i < p_count; i++) {
                if(!products[i].used && products[i].id == orders[o_count].product_id) {
                    printf("Client %s ordered %s\n", orders[o_count].address, products[i].name);
                    orders[o_count].fulfilled = 1;
                    products[i].used = 1;
                    break;
                }
            }
            o_count++;
        }
    }
    return 0;
}

int zad3() {
    FILE *in = fopen("input.txt", "r");
    if (!in) {
        printf("Файлът input.txt не е намерен! Моля създайте го и опитайте отново.\n");
        return 1;
    }

    char **words = NULL;
    int w_count = 0;
    char buffer[55];
    char target_char = '\0';

    while (fscanf(in, "%50s", buffer) == 1) {
        if (w_count == 0 || buffer[0] == target_char) {
            words = realloc(words, (w_count + 1) * sizeof(char*));
            words[w_count] = strdup(buffer);
            target_char = buffer[strlen(buffer) - 1];
            w_count++;
        }
    }
    fclose(in);

    FILE *out = fopen("output.bin", "wb");
    if (out) {
        for (int i = 0; i < w_count; i++) {
            fwrite(words[i], sizeof(char), strlen(words[i]), out);
            if (i < w_count - 1) {
                char space = ' ';
                fwrite(&space, sizeof(char), 1, out);
            }
        }
        fclose(out);
    }

    printf("Съдържание на бинарния файл:\n");
    FILE *bin_in = fopen("output.bin", "rb");
    if (bin_in) {
        char ch;
        while (fread(&ch, sizeof(char), 1, bin_in) == 1) {
            printf("%c", ch);
        }
        printf("\n");
        fclose(bin_in);
    }

    for (int i = 0; i < w_count; i++) free(words[i]);
    free(words);

    return 0;
}

int zad4() {
    char filename[100];
    char out_filename[105];
    int key;

    printf("Въведете име на файла за кодиране: ");
    scanf("%s", filename);
    
    printf("Въведете ключ (2-10): ");
    scanf("%d", &key);
    
    if (key < 2 || key > 10) {
        printf("Грешка: Ключът трябва да е между 2 и 10!\n");
        return 1;
    }

    FILE *in = fopen(filename, "r");
    if (!in) {
        printf("Файлът %s не е намерен!\n", filename);
        return 1;
    }

    sprintf(out_filename, "enc_%s", filename);
    FILE *out = fopen(out_filename, "w");
    if (!out) {
        printf("Грешка при създаване на изходния файл!\n");
        fclose(in);
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch + key, out);
    }

    printf("Файлът е кодиран успешно и запазен като %s\n", out_filename);

    fclose(in);
    fclose(out);
    return 0;
}

int zad5() {
    char word[] = "door";
    int len = strlen(word);
    char hidden[50];
    int max_guesses = len + 2;
    int current_guesses = 0;
    int guessed_letters = 0;
    
    for(int i = 0; i < len; i++) hidden[i] = '_';
    hidden[len] = '\0';
    
    printf("Добре дошли в Бесеница!\n");
    
    while(guessed_letters < len && current_guesses < max_guesses) {
        printf("\nДума: %s\n", hidden);
        printf("Опити до момента: %d / Максимум: %d\n", current_guesses, max_guesses);
        printf("Въведете буква: ");
        
        char guess;
        scanf(" %c", &guess);
        current_guesses++;
        
        int found = 0;
        for(int i = 0; i < len; i++) {
            if(word[i] == guess && hidden[i] == '_') {
                hidden[i] = guess;
                guessed_letters++;
                found = 1;
            }
        }
        
        if(!found) {
            printf("Буквата '%c' не се съдържа (или вече е разкрита).\n", guess);
        }
    }
    
    if(guessed_letters == len) {
        printf("\nПоздравления! Познахте думата: %s (с %d опита)\n", word, current_guesses);
    } else {
        printf("\nЗагубихте! Търсената дума беше: %s\n", word);
    }
    
    return 0;
}

int isAnagram(char *str1, char *str2) {
    int count1[256] = {0};
    int count2[256] = {0};
    
    if (strlen(str1) != strlen(str2)) return 0;
    
    for (int i = 0; str1[i] != '\0'; i++) {
        count1[(unsigned char)str1[i]]++;
        count2[(unsigned char)str2[i]]++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) return 0;
    }
    return 1;
}

int zad6() {
    char str1[100], str2[100];
    printf("Въведете първата дума: ");
    scanf("%s", str1);
    printf("Въведете втората дума: ");
    scanf("%s", str2);
    
    if (isAnagram(str1, str2)) {
        printf("1 (Думите са анаграма)\n");
    } else {
        printf("0 (Думите НЕ са анаграма)\n");
    }
    return 0;
}


int zad7() {
    int sub_choice;
    FILE *f;
    Employee emp;
    
    do {
        printf("\nСътрудници\n");
        printf("1. Добави нов сътрудник\n");
        printf("2. Изведи всички сътрудници и заплати\n");
        printf("0. Назад\n");
        printf("Избор: ");
        scanf("%d", &sub_choice);
        
        if (sub_choice == 1) {
            f = fopen("employees.bin", "ab");
            if(!f) { printf("Грешка при отваряне на файла.\n"); continue; }
            
            printf("ID: "); scanf("%d", &emp.id);
            printf("Почасово плащане: "); scanf("%lf", &emp.hourly_rate);
            printf("Отработени часове: "); scanf("%d", &emp.hours_worked);
            
            double gross;
            if (emp.hours_worked <= 40) {
                gross = emp.hours_worked * emp.hourly_rate;
            } else {
                gross = (40 * emp.hourly_rate) + ((emp.hours_worked - 40) * emp.hourly_rate * 1.5);
            }
            emp.weekly_salary = gross - (gross * 0.0365);
            
            fwrite(&emp, sizeof(Employee), 1, f);
            fclose(f);
            printf("Сътрудникът е добавен успешно.\n");
            
        } else if (sub_choice == 2) {
            f = fopen("employees.bin", "rb");
            if(!f) { printf("Няма налични записи.\n"); continue; }
            
            printf("\nСписък със сътрудници\n");
            while(fread(&emp, sizeof(Employee), 1, f) == 1) {
                printf("ID: %d | Ставка: %.2f | Часове: %d | Седмична заплата(нетно): %.2f\n", 
                       emp.id, emp.hourly_rate, emp.hours_worked, emp.weekly_salary);
            }
            fclose(f);
        }
    } while (sub_choice != 0);
    
    return 0;
}

// 1. Харалампий иска да организира рождения си ден, но за целта трябва да закупи инвентар за провеждането, който се изразява в следните предмети:
// Стол – 13,99; Маса за 8 човека – 42,00; комплект от 6 чаши – 5,98; комплект от 6 чинии с прибори – 21,02.
// От клавиатурата се въвеждат броя на гостите. Следват редове с неща, които до момента е купил Харалампий за партито до въвеждане на команда PARTY!. Сметнете колко пари е похарчил до момента Харалампий и колко още неща трябва да купи за да може да реализира своето парти и всички гости да имат стол, да седят на маса и да разполагат с чаша и прибори.
// Пример: 
// 10
// Table
// Chair 
// Chair
// Chair
// Cups
// Cups
// Dishes
// PARTY!
// Изход:
// 116,95 
// 1 Table
// 7 Chairs
// 1 Dishes
// (пояснение – поръчаните неща са на стойност 116,95. Има закупена една маса, а за сядането на 10 човека са нужни 2 маси. Има закупени 3 стола – нужни са още 7 за да може всеки да седи на стол. Приборите, които са нужни са още 4 броя, което значи закупуване на още един комплект).

// 2.Цецко е програмист и има хоби да прави сладкарски изделия. Помогнете му да напише програма, с която да менажира произведените сладка и техните доставки. За целта трябва да създадете структура за продукт, която да описва име на продукта, цена и уникален номер. Създайте и структура за поръчки, която да описва адрес на клиент и номер на продукт. 
// От стандартния вход постъпват множество продукти и поръчки. Когато Цецко прави сладко той го добавя в списък на създадените сладка, а когато се пуска поръчка тя се изпълнява при наличие на продукт, иначе чака до създаването му. 
// За входни данни ще получавате две команди:
// Product
// <име на продукт>
// <цена>
// <номер на продукта>
// Тази команда създава нов продукт и го добавя в списъка с продукти. Ако има поръчка за този продукт то поръчката се изпълнява незабавно и се маха от чакащите за изпълнение.
// Order
// <адрес>
// <номер на продукт>
// Ако има наличен вече произведен продукт се изпълнява поръчката, в противен случай чака за създаване на продукта. 
// При всяко изпълнение на поръчка изписвайте: Client <address> ordered <product name>
// Програмата приключва работа при въвеждане на команда END

// 3.Имате текстов файл, в който имате думи (на английски език и не повече от 50 знака). 
// Прочетете думите, и в динамичен масив запишете тези думи, които започват с последния знак на предходната дума(думите се гледат поред, записва за първата дума от файла след което се записва първата която се срещне и отговаря на условието и т.н).
// В бинарен файл запишете така направения масив от думи. 
// Направете  възможност за изкарване на екрана съдържанието на бинарния файл.

// изход на файла input.txt:   apple  car price elephant head tire cool soft eleven output night tent story  movies  pleasure memory  time search  shortcut  river  compare evening
// apple elephant tire eleven night tent time evening

// Пояснение - думите в бинарния файла за разделени със знака “ ” (интервал). 
// Използвайте  го за разделител и четете знак по знак.

// 4.Напишете програма , която кодира информацията в текстов файл символ по символ с ключ въведен от потребителя и записва кодираното съдържание в друг файл. Ключът е цяло число между 2 и 10. Името на файла, който ще бъде кодиран се чете от клавиатурата.

// 5.Напишете програма за компютърен вариант на играта „Бесеница“. В тази игра на играча се показва дължината на определена дума( използват се подчертаващи тирета) и той се опитва да отгатне думата като въвежда букви. При всяко въвеждане на нова буква се проверява дали думата съдържа тази буква. Ако това е така , съответната буква се показва. Бройте буквите , въведени до завършване на думата. Играчът печели ако познае думата с въвеждане на брой букви не повече от дължината на търсената дума +2 или по-малко от този брой. 
// Например , ако търсената дума е „concatenation“, то броят въведени букви трябва да е по-малък или равен на 15.

// 6.Напишете функция, която проверява дали два низа са анаграма. Функцията има два параметъра ,двата низа и връща като резултат 1 ако низовете са анаграма и 0 ако не са.
// Пояснение -  анаграма е дума или фраза, образувана от буквите на друга дума или фраза 
// Например    listen=silent  ,  peach = cheap,   players = parsley

// 7. Да се състави програма на C, която:
// •	създава двоичен файл със записи, представляващи данни за сътрудник във фирма: идентификационен номер на сътрудника, почасово плащане, брой отработени часове за една седмица, седмична заплата;
// •	Общият брой на сътрудниците да не превишава 30
// •	включва възможност за допълване на нови записи във файла;
// •	включва възможност за извеждане на изчислената седмична заплата на екрана. При изчисляване на работната заплата е необходимо да се знае, че всеки извънреден час (над 40 часа седмично) се заплаща 150%, а стойността на данъците е 3,65% от общата заработка.
// •	включва меню в главната функция main().


