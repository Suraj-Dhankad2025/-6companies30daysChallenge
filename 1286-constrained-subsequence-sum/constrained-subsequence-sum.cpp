class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans=nums[0];
        priority_queue<pair<int, int>>pq;
        pq.push({nums[0], 0});
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            while(!pq.empty() && i-pq.top().second>k){
                pq.pop();
            }
            sum = max(0, pq.top().first) + nums[i];
            ans = max(ans, sum);
            pq.push({sum, i});
        }
        return ans;
    }
};