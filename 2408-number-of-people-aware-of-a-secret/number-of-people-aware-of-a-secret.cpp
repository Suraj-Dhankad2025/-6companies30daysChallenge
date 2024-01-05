class Solution {
public:
    int mod = 1e9+7;
    int find(int day, int n, int delay, int forget, vector<int>&dp){
        if(day+delay>n){
            return 1;
        }
        if(dp[day]!=-1)return dp[day];
        long long ans = 1;
        for(int i=day+delay; i<=min(day+forget, n); i++){
            if(i==day+forget){
                ans--;
                break;
            }
            ans+=find(i, n, delay, forget, dp)%mod;
        }
        return dp[day] = ans%mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,-1);
        return find(1, n, delay, forget, dp)%mod;
    }
};