class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> t(m, vector<int>(n));

        bool obs = false;

        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 1) obs = true;

            if(obs) t[i][0] = 0;
            else t[i][0] = 1;
        }

        obs = false;

        for(int j = 0; j < n; j++){
            if(obstacleGrid[0][j] == 1) obs = true;

            if(obs) t[0][j] = 0;
            else t[0][j] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                if(obstacleGrid[i][j] == 1)
                    t[i][j] = 0;
                else
                    t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];
    }
};