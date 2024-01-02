class Solution {
public:
    vector<vector<int>>ans;
    void find(int i, int k, int sum, vector<int>a){
        if(i==10){
            if(k==0 && sum==0){
                ans.push_back(a);
            }
            return ;
        }
        find(i+1, k, sum, a);
        if(sum>=i){
            a.push_back(i);
            find(i+1, k-1, sum-i, a);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a;
        find(1,k,n,a);
        return ans;
    }
};