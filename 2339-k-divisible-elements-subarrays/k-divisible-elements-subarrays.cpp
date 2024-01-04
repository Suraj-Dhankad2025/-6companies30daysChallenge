class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>>st;
        int c=0;
        vector<int>temp;
        for(int i=0; i<n; i++){
            c=0;
            temp.clear();
            for(int j=i; j<n; j++){
                temp.push_back(nums[j]);
                if(nums[j]%p==0){
                    c++;
                }
                if(c>k)break;
                st.insert(temp);
            }
        }
        return st.size();
    }
};