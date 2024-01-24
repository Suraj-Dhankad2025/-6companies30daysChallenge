class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>ans;
        int len = nums[0].size();
        for(auto it:queries){
            int k = it[0];
            int trim = it[1];
            priority_queue<pair<string, int>>pq;
            for(int i=0; i<nums.size(); i++){
                string st = nums[i].substr(len - trim);
                pq.push({st, i});
                if(pq.size()>k){
                    pq.pop();
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};