class Solution {
public:
    bool find(int a, int b){
        int n = min(a, b);
        int m = max(a, b);
        if(m>2300 && n<100){
            n += (2400-m);
            if(n<100)return 1;
            return 0;
        }
        if(abs(a-b)<100)return 1;
        return 0;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string>ans;
        int n = access_times.size();
        unordered_map<string, vector<int>>m;
        for(int i=0; i<n; i++){
            m[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }
        for(auto it:m){
            sort(it.second.begin(), it.second.end());
            int i=0,j=2;
            while(j<it.second.size()){
                if(find(it.second[i], it.second[j])==1){
                    ans.push_back(it.first);
                    break;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};