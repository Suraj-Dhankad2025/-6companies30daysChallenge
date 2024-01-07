class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int med;
        sort(nums.begin(), nums.end());
        if(n%2==0){
            med = nums[n/2] + nums[n/2 - 1];
            med = med/2;
        }
        else{
            med = nums[n/2];
        }
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans += abs(med - nums[i]);
        }
        return ans;
    }
};