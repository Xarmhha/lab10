#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, ".UTF8");
    task1();
    task2();
}
double fa(double x) {
    if (x <= 3) {
        return (x * x) - (3 * x) + 9;
    }
    else {
        return 1.0 / ((x * x * x) + 3);
    }
}

double fb(double x) {
    return x * exp(sin(x * x));
}

int task1() {
    double x, f1, f2;
    int choice;

    printf("Введите значение x: ");
    scanf("%lf", &x);

    f1 = fa(x);
    f2 = fb(x);

    printf("\nЧто вы хотите вычислить?\n");
    printf("1. Только F1(x)\n");
    printf("2. Только F2(x)\n");
    printf("3. Произведение F1(x) * F2(x)\n");
    printf("4. Разность квадратов F1(x)^2 - F2(x)^2\n");
    printf("5. Удвоенную сумму 2 * (F1(x) + F2(x))\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("F1(x) = %lf\n", f1);
        break;
    case 2:
        printf("F2(x) = %lf\n", f2);
        break;
    case 3:
        printf("Произведение: %lf\n", f1 * f2);
        break;
    case 4:
        printf("Разность квадратов: %lf\n", (f1 * f1) - (f2 * f2));
        break;
    case 5:
        printf("Удвоенная сумма: %lf\n", 2 * (f1 + f2));
        break;
    default:
        printf("Неверный выбор!\n");
    }

    return 0;
}
double sin_n(double x, int N) {
    double sum = 0, t = x;

    for (int i = 1; i <= N; i++) {
        sum += t;
        t *= -x * x / ((2 * i) * (2 * i + 1));
    }
    return sum;
}

double sin_eps(double x, double eps) {
    double sum = 0, t = x;
    int i = 1;
    while (fabs(t) > eps) {
        sum += t;
        t *= -x * x / ((2 * i) * (2 * i + 1));
        i++;
    }
    return sum;
}

int task2() {
    double x, eps;
    int N;

    printf("Введите x (в радианах, например 0.785): ");
    scanf("%lf", &x);
    printf("Введите N (количество членов ряда): ");
    scanf("%d", &N);
    printf("Введите точность, например 0.0001: ");
    scanf("%lf", &eps);

    double std_sin = sin(x);
    double my_sin_n = sin_n(x, N);
    double my_sin_eps = sin_eps(x, eps);

    printf("\nСтандартная функция: %lf\n", std_sin);
    printf("Ряд (N = %d):       %lf\n", N, my_sin_n);
    printf("Ряд (eps = %lf): %lf\n", eps, my_sin_eps);

    return 0;
}