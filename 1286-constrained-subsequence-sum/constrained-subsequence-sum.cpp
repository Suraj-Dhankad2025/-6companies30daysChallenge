class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[0];
        priority_queue<pair<int, int>>pq;
        int sum=nums[0];
        pq.push({nums[0], 0});
        for(int i=1; i<n; i++){
           while(!pq.empty() && i - pq.top().second>k){
               pq.pop();
           }
           sum = max(0,pq.top().first) + nums[i];
           ans = max(ans, sum);
           pq.push({sum, i});
        }
        return ans;
    }
};