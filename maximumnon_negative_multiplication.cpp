class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> mx(m, vector<long long>(n));
        vector<vector<long long>> mn(m, vector<long long>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0){
                    mx[i][j] = grid[i][j];
                    mn[i][j] = grid[i][j];
                }

                else if(i == 0){
                    mx[i][j] = mx[i][j-1] * grid[i][j];
                    mn[i][j] = mn[i][j-1] * grid[i][j];
                }

                else if(j == 0){
                    mx[i][j] = mx[i-1][j] * grid[i][j];
                    mn[i][j] = mn[i-1][j] * grid[i][j];
                }

                else{
                    long long a = mx[i-1][j] * grid[i][j];
                    long long b = mn[i-1][j] * grid[i][j];
                    long long c = mx[i][j-1] * grid[i][j];
                    long long d = mn[i][j-1] * grid[i][j];

                    mx[i][j] = max(max(a,b), max(c,d));
                    mn[i][j] = min(min(a,b), min(c,d));
                }
            }
        }

        if(mx[m-1][n-1] < 0) return -1;

        return mx[m-1][n-1] % 1000000007;
    }
};