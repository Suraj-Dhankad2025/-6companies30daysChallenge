class Solution {
public:
    vector<int>prime;
    int v[45];
    int mod = 1e9+7;
    bool check(int n){
        for(int i=2; i*i<=n ;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    long long find(int value, int mask, vector<vector<int>>&dp){
        if(value>30){
            return (mask>0);
        }
        if(dp[value][mask]!=-1){
            return dp[value][mask];
        }
        int newMask=0;
        long long product=1;
        for(int i=0; i<prime.size(); i++){
            if(value%prime[i]==0){
                newMask = newMask | (1<<i);
                product = product*prime[i];
            }
        }
        long long ans = find(value+1, mask, dp);
        if(product==value && v[value] && (mask & newMask)==0){
            ans = ans + find(value+1,mask|newMask, dp)*v[value];
        }
        return dp[value][mask] = ans%mod;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        for(auto i:nums){
            v[i]++;
        }
        for(int i=2; i<31; i++){
            if(check(i)){
                prime.push_back(i);
            }
        }
        int mask = 0;
        vector<vector<int>>dp(31, vector<int>(1<<12,-1));
        long long ans = find(2, mask,dp)%mod;
        for(int i=0; i<v[1]; i++){
            ans = (ans*2)%mod;
        }
        return ans%mod;
    }
};