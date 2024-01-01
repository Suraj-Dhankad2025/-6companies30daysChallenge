class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
         vector<int>ans;
        int len = nums[0].size();
        int ind=len-1;
        for(int i=0; i<q.size(); i++){
            int k = q[i][0];
            int x = q[i][1];
            priority_queue<pair<string, int>>pq;
            for(int j=0; j<nums.size(); j++){
                ind = len-x;
                string s = nums[j].substr(ind, len);
                pq.push({s, j});
                if(pq.size()>k){
                    pq.pop();
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};