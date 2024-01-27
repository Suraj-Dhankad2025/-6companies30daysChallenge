class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>>v;
        for(auto i:buildings){
            v.push_back({i[0], -i[2]});
            v.push_back({i[1], i[2]});
        }
        sort(v.begin(), v.end(), cmp);
        vector<vector<int>>ans;
        multiset<int>s;
        int curH = 0;
        s.insert(0);
        for(int i=0; i<v.size(); i++){
            int x = v[i].first;
            int h = v[i].second;
            if(h<0){
                s.insert(-h);
            }
            else{
                s.erase(s.find(h));
            }
            if(curH!=*s.rbegin()){
                ans.push_back({x, *s.rbegin()});
                curH = *s.rbegin();
            }
        }
        return ans;
    }
};