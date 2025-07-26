#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //  Memoization (Top-Down)
    int PossibleUniquePath(int i, int j, vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int up = PossibleUniquePath(i - 1, j, dp);
        int left = PossibleUniquePath(i, j - 1, dp);
        return dp[i][j] = up + left;
    }

    int uniquePathsMemo(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return PossibleUniquePath(m - 1, n - 1, dp);
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;

    cout << "Unique Paths using Memoization: " << sol.uniquePathsMemo(m, n) << endl;
    return 0;
}
