#include <stdio.h>
#include <string.h>
#include <windows.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void apply_discount(int* price, int n, int percent) {
    for (int i = 0; i < n; i++) {
        price[i] = price[i] * (100 - percent) / 100;
    }
}

void print_prices(int* price, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }
    printf("\n");
}

void to_hms(int total, int* h, int* m, int* s) {
    *h = total / 3600;
    *m = (total % 3600) / 60;
    *s = total % 60;
}

int main(void) {
    SetConsoleOutputCP(65001);

    // #실습1
    char str[100];
    int count = 0;
    printf("영문 문장을 입력하시오 : ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }
    str[strcspn(str, "\n")] = '\0';

    for (char* p = str; *p != '\0'; p++) {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32;
        }
        if (*p != ' ') {
            count++;
        }
    }
    printf("대문자 : %s\n", str);
    printf("글자 수 (공백 제외) : %d\n\n", count);

    // #실습2
    int num1 = 45510;
    int num2 = 2023;
    swap(&num1, &num2);
    printf("num1 value : %d\n", num1);
    printf("num2 value : %d\n\n", num2);

    // #실습3
    int prices[5] = { 12000, 8500, 3000, 45000, 990 };
    int percent;
    printf("할인율(%%)을 입력하시오 : ");
    scanf_s("%d", &percent);
    printf("할인 전 : ");
    print_prices(prices, 5);
    apply_discount(prices, 5, percent);
    printf("할인 후 : ");
    print_prices(prices, 5);
    printf("\n");

    // #실습4
    int total, h, m, s;
    printf("총 시간(초)을 입력하시오 : ");
    scanf_s("%d", &total);
    to_hms(total, &h, &m, &s);
    printf("%d시간 %d분 %d초\n", h, m, s);

    return 0;
}