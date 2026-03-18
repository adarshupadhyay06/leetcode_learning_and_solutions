class Solution {
public:
    int integerBreak(int n) {
        vector<int> t(n+1);

        t[2]=1;

        for(int i=3;i<=n;i++){
            int ans=0;
            for(int j=2;j<i;j++){
                ans=max(ans,max(j*(i-j),j*t[i-j]));
            }
            t[i]=ans;
        }
        return t[n];
    }
};