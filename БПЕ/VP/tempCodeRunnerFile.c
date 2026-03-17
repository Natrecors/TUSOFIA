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
