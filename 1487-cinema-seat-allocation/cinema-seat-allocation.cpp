class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        map<int, vector<int>>m;
        for(int i=0; i<r.size(); i++){
            m[r[i][0]].push_back(r[i][1]);
        }
        int ans = (n - m.size())*2;
        
        for(auto i:m){
            bool f1=0, f2=0,f3=0;
            vector<int>v = i.second;
            for(int j=0; j<v.size(); j++){
                if(v[j]>=2 && v[j]<=5){
                    f1 = 1;
                }
                if(v[j]>=4 && v[j]<=7){
                    f2 = 1;
                }
                if(v[j]>=6 && v[j]<=9){
                    f3 = 1;
                }
            }
            if(f1==0 && f3==0){
                ans+=2;
            }
            else if(f1==0 || f2==0 || f3==0){
                ans+=1;
            }
        }
        return ans;
    }
};