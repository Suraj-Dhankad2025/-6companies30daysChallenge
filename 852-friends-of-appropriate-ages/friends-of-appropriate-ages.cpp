class Solution {
public:
    bool check(int a, int b){
        if(a<=0.5*b + 7 || a>b || (a>100 && b<100)){
            return false;
        }
        return true;
    }
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int ans=0;
        unordered_map<int, int>m;
        for(int i=0; i<n; i++){
            m[ages[i]]++;
        }
        for(auto a:m){
            for(auto b:m){
                if(check(a.first, b.first)){
                    ans += a.second*(b.second - (a.first==b.first));
                }
            }
        }
        return ans;
    }
};