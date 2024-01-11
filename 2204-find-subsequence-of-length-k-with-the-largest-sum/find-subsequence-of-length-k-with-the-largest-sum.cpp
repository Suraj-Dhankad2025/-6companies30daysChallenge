class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        vector<int> ans(k);
        for(int i=0; i<n; ++i) v[i] = {nums[i],i};
        sort(rbegin(v),rend(v));
        sort(begin(v),begin(v)+k,[](auto a,auto b){return a.second < b.second;});
        for(int i=0; i<k; ++i) ans[i] = v[i].first;
        return ans;
    }
};