class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> dp;

    int solve(int n, int i){
        if(n == 1) return 1;

        if(dp[n][i] != -1) return dp[n][i];

        int ans = 0;

        for(auto it : mp[i]){
            ans = (ans + solve(n-1, it)) % mod;
        }

        return dp[n][i] = ans;
    }

    int knightDialer(int n) {
        mp = {
            {0, {4, 6}},
            {1, {6, 8}},
            {2, {7, 9}},
            {3, {4, 8}},
            {4, {0, 3, 9}},
            {5, {}},
            {6, {0, 1, 7}},
            {7, {2, 6}},
            {8, {1, 3}},
            {9, {2, 4}}
        };

        dp = vector<vector<int>>(n+1, vector<int>(10, -1));

        int ans = 0;

        for(int i = 0; i <= 9; i++){
            ans = (ans + solve(n, i)) % mod;
        }

        return ans;
    }
};