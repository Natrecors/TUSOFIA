#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ownerName[30];
    char chipNumber[8];
    float price;
} Patient;

//1 30
Patient createAndSavePatient() {
    Patient p;
    fflush(stdin); 

    printf("Въведете име на собственик: ");
    fgets(p.ownerName, 30, stdin);
    p.ownerName[strcspn(p.ownerName, "\n")] = 0;

    printf("Въведете номер на чип (формат A12345B): ");
    scanf("%7s", p.chipNumber);

    printf("Въведете цена за преглед: ");
    scanf("%f", &p.price);

    FILE *file = fopen("animalsText.txt", "a"); 
    if (file != NULL) {
        fprintf(file, "%s, %.2f\n", p.ownerName, p.price);
        fclose(file);
    } else {
        printf("Грешка при създаването на animalsText.txt\n");
    }

    return p;
}

// 2 30
void printPatientsByExactPrice(Patient patients[], int size, float targetPrice) {
    int found = 0;
    
    for (int i = 0; i < size; i++) {
        if (patients[i].price == targetPrice) {
            printf("%s - %s\n", patients[i].ownerName, patients[i].chipNumber);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Няма открит запис за пациент с цена за преглед %.2f\n", targetPrice);
    }
}

// 3 40
void printFromBinaryFile(float minPrice) {
    FILE *file = fopen("animalsBin.bin", "rb");
    if (file == NULL) {
        printf("Грешка: Бинарният файл 'animalsBin.bin' не може да бъде отворен (вероятно не съществува).\n");
        return;
    }

    int nameLength;
    char name[30];
    char chip[8];
    float price;

    while (fread(&nameLength, sizeof(int), 1, file) == 1) {
        
        fread(name, sizeof(char), nameLength, file);
        name[nameLength] = '\0'; 

        fread(chip, sizeof(char), 8, file);


        fread(&price, sizeof(float), 1, file);


        if (price >= minPrice) {
            printf("Bin OwnerName: %s\n", name);
            printf("Bin Chip: %s\n", chip);
            printf("Bin Price: %.2f\n", price);
            printf("-----\n");
        }
    }

    fclose(file);
}


int main() {

    printf("СЪЗДАВАНЕ НА ПАЦИЕНТ\n");
    Patient patients[10];
    patients[0] = createAndSavePatient();
    

    strcpy(patients[1].ownerName, "Stoyan Ivanov");
    strcpy(patients[1].chipNumber, "A12345B");
    patients[1].price = 45.50;
    int currentPatientsCount = 2;


    printf("\n ТЪРСЕНЕ ПО ТОЧНА ЦЕНА (45.50)\n");
    printPatientsByExactPrice(patients, currentPatientsCount, 45.50);


    printf("\n ЧЕТЕНЕ ОТ БИНАРЕН ФАЙЛ (Цена >= 40.00)\n");
    printFromBinaryFile(40.00);

    return 0;
}