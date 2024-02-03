class Solution {
public:
   int find(vector<int>&nums, int s, int e, vector<vector<int>>&dp){
        if(s>e){
            return 0;
        }
        if(dp[s][e]!=-1)return dp[s][e];
        int ans = INT_MIN;
        for(int i=s; i<=e; i++){
            int sum = nums[s-1]*nums[i]*nums[e+1] + find(nums, s, i-1, dp) + find(nums, i+1, e, dp);
            ans = max(ans, sum);
        }
        return dp[s][e] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        return find(nums, 1, nums.size()-2, dp);
    }
};