#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> dp2(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            g[i][j] = x;
        }
    }

    dp[0][n-1] = g[0][n-1];
    dp2[0][n-1] = g[0][n-1];
    for (int j = n - 1; j > 0; --j) {
        if (g[0][j] < g[0][j - 1]) {
            dp[0][j-1] = dp[0][j] + g[0][j - 1];
            dp2[0][j-1] = dp2[0][j] + g[0][j - 1];
        } else {
            dp[0][j-1] = dp[0][j];
            dp2[0][j-1] = dp2[0][j];
        }
    }

    for (int i = 1; i < n; ++i) {
        if (g[i-1][n-1] < g[i][n-1]) {
            dp[i][n-1] = dp[i-1][n-1] + g[i][n-1];
            dp2[i][n-1] = dp2[i-1][n-1] + g[i][n-1];
        } else {
            dp[i][n-1] = dp[i-1][n-1];
            dp2[i][n-1] = dp2[i-1][n-1];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = n - 2; j > -1; --j) {
            if (g[i][j] > g[i-1][j] and g[i][j] > g[i][j+1]) {
                dp[i][j] = max(dp[i][j+1], dp[i-1][j]) + g[i][j];
                dp2[i][j] = min(dp2[i][j+1], dp2[i-1][j]) + g[i][j];
            } else if (g[i][j] <= g[i-1][j] and g[i][j] <= g[i][j+1]) {
                dp[i][j] = max(dp[i][j+1], dp[i-1][j]);
                dp2[i][j] = min(dp2[i][j+1], dp2[i-1][j]);
            } else {
                if (g[i][j] > g[i-1][j] and g[i][j] <= g[i][j+1]) {
                    if (dp[i-1][j] + g[i][j] >= dp[i][j+1]) {
                        dp[i][j] = dp[i-1][j] + g[i][j];
                    } else {
                        dp[i][j] = dp[i][j+1];
                    }

                    if (dp2[i-1][j] + g[i][j] >= dp2[i][j+1]) {
                        dp2[i][j] = dp2[i][j+1];
                    } else {
                        dp2[i][j] = dp2[i-1][j] + g[i][j];
                    }
                } else if (g[i][j] <= g[i-1][j] and g[i][j] > g[i][j+1]) {
                    if (dp[i][j+1] + g[i][j] >= dp[i-1][j]) {
                        dp[i][j] = dp[i][j+1] + g[i][j];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }

                    if (dp2[i][j+1] + g[i][j] >= dp2[i-1][j]) {
                        dp2[i][j] = dp2[i-1][j];
                    } else {
                        dp2[i][j] = dp2[i][j+1] + g[i][j];
                    }
                }
            }
        }
    }

    cout << "max = " << dp[n-1][0];
    cout << endl;
    cout << "min = " << dp2[n-1][0];

    "в итоге ответ: максимальное = 1524; минимальное = 598"
    return 0;
}
