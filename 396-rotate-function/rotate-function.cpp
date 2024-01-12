class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int f=0;
        for(int i=0; i<n; i++){
            f+=i*nums[i];
            sum+=nums[i];
        }
        int cur=0,prev=f;
        int ind=n-1;
        int ans=INT_MIN;
        ans = max(ans, f);
        for(int i=1; i<n; i++){
            cur = prev + sum - n*nums[ind];
            ind--;
            ans = max(ans, cur);
            prev = cur;
        }
        return ans;
    }
};