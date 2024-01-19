class Solution {
public:
     int mod=1e9+7;
    int find(int prev, int ind, vector<int>&nums,int mask, vector<vector<int>>&dp){
        if(ind==nums.size()){
            return 1;
        }
        if(dp[prev][mask]!=-1)return dp[prev][mask];
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(mask & 1<<i) continue;
            if(mask!=0 && nums[prev]%nums[i]!=0 && nums[i]%nums[prev]!=0){
                continue;
            }   
            ans= (ans + find(i, ind+1, nums, mask | 1<<i, dp))%mod;
        }
        return dp[prev][mask] = ans%mod;
    }
    int specialPerm(vector<int>& nums) {
        int prev = 0;
        int n = nums.size();
        vector<vector<int>>dp(nums.size(), vector<int>(1<<(n), -1));
        int mask = 0;
        return find(prev, 0, nums, mask, dp);
    }
};