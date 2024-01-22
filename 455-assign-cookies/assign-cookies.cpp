class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int, int>m;
        for(auto i:s){
            m[i]++;
        }
        int ans=0;
        for(auto i:g){
            for(auto it:m){
                if(it.first>=i){
                    ans++;
                    m[it.first]--;
                    if(m[it.first]==0){
                        m.erase(it.first);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};