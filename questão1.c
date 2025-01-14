#include <stdio.h>

int fatorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int binominal(int n, int k) {
    return fatorial(n) / (fatorial(k) * fatorial(n - k));
}

int main() {
    int N;

    printf("Insira a altura do triangulo de Pascal: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N - i - 1; j++) {
            printf("  ");
        }

        for (int j = 0; j <= i; j++) {
            printf("%d   ", binominal(i, j));
        }

        printf("\n");
    }

    return 0;
}
