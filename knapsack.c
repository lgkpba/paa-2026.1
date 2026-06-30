#include <stdio.h>

#define MAXS 2000

int dp[MAXS + 1];

int main() {
    int S, N;
    scanf("%d %d", &S, &N);

    for (int i = 0; i < N; i++) {
        int peso, valor;
        scanf("%d %d", &peso, &valor);

        for (int j = S; j >= peso; j--) {
            if (dp[j] < dp[j - peso] + valor)
                dp[j] = dp[j - peso] + valor;
        }
    }

    printf("%d\n", dp[S]);

    return 0;
}