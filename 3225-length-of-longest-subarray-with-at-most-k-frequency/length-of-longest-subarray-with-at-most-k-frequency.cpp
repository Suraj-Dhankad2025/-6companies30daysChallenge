class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        map<int, int>m;
        int ans=0;
        while(j<n){
            m[nums[j]]++;
            while(i<n && m[nums[j]]>k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};