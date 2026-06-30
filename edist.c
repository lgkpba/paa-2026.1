#include <stdio.h>
#include <string.h>

#define MAX 2000

int dp[MAX + 1][MAX + 1];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char A[MAX + 1], B[MAX + 1];

        scanf("%s", A);
        scanf("%s", B);

        int n = strlen(A);
        int m = strlen(B);

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;

        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(
                        dp[i - 1][j],
                        min(dp[i][j - 1], dp[i - 1][j - 1])
                    );
                }
            }
        }

        printf("%d\n", dp[n][m]);
    }

    return 0;
}