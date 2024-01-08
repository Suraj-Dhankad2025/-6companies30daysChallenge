class Solution {
public:
        int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int c=0;
        int ans=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0; i<n; i++){
            c+=nums[i]%2;
            if(m.find(c-k)!=m.end()){
                ans+=m[c-k];
            }
            m[c]++;
        }
        return ans;
    }
};