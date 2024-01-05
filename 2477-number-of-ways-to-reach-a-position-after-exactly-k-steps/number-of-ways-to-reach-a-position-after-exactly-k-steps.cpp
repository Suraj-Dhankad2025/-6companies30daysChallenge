class Solution {
public:
    int mod = 1e9+7;
    long long find(int s, int e, int k, vector<vector<int>>&dp){
        if(k==0){
            if(s==e){
                return 1;
            }
            return 0;
        }
        if(dp[s+999][k]!=-1)return dp[s+999][k];
        long long left = find(s-1, e, k-1, dp)%mod;
        long long right = find(s+1, e, k-1, dp)%mod;
        return dp[s+999][k] = (left + right)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3000, vector<int>(k+1, -1));
        return find(startPos, endPos, k, dp)%mod;
    }
};