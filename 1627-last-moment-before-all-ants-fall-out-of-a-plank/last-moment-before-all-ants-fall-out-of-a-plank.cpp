class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        for(auto i:left){
            ans = max(ans, abs(i-0));
        }
        for(auto i:right){
            ans = max(ans, abs(i-n));
        }
        return ans;
    }
};