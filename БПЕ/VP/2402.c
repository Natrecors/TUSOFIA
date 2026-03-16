#include <stdio.h>

int main() {
    float length, width, area, perimeter;

    printf("a: \n");
    scanf("%f", &length);

    printf("shirina: \n");
    scanf("%f", &width);
    area = length * width;
    perimeter = 2 * (length + width);
    printf("plosht: %.2f\n", area);
    printf("perimeurx: %.2f\n", perimeter);

    return 0;
}