class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        int i=0,j=1;
        sort(nums.begin(), nums.end());
        while(j<n && i<n){
            if(i==j || nums[j]-nums[i]<k){
                j++;
            }
            else if(nums[j]-nums[i]>k){
                i++;
            }
            else{
                ans++;
                i++;
                while(i<n && nums[i]==nums[i-1]){
                    i++;
                }
        
            }
        }
        return ans;
    }
};