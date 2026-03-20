class Solution {
public:
    int dp[101][101];
    bool vis[101][101];

    int solve(vector<vector<int>>& matrix, int i, int j, int n) {
        if (j < 0 || j >= n) return 1e9;
        if (i == n - 1) return matrix[i][j];

        if (vis[i][j]) return dp[i][j];

        vis[i][j] = true;

        int left  = matrix[i][j] + solve(matrix, i + 1, j - 1, n);
        int down  = matrix[i][j] + solve(matrix, i + 1, j, n);
        int right = matrix[i][j] + solve(matrix, i + 1, j + 1, n);

        return dp[i][j] = min(left, min(down, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        memset(vis, false, sizeof(vis));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(matrix, 0, j, n));
        }

        return ans;
    }
};