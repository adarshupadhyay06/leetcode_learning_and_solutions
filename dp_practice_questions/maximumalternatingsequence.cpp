class Solution {
public:

    long long solve(vector<int>& nums,int i,int id,vector<vector<long long>>& dp){

        if(i==nums.size()) return 0;

        if(dp[i][id]!=-1) return dp[i][id];

        long long take;

        if(id==0)
            take = nums[i] + solve(nums,i+1,1,dp);   
        else
            take = -nums[i] + solve(nums,i+1,0,dp); 

        long long skip = solve(nums,i+1,id,dp);

        return dp[i][id] = max(take,skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<long long>> dp(n,vector<long long>(2,-1));

        return solve(nums,0,0,dp);   
    }
};