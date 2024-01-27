class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        priority_queue<pair<int, int>>pq;
        for(int i=0;i<a.size(); i++){
            pq.push({a[i]+b[i], i});
        }
        int alice=0;
        int bob = 0;
        bool f=0;
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
            if(f==0){
                alice+=a[ind];
                f=1;
            }
            else{
                bob+=b[ind];
                f=0;
            }
        }
        if(alice==bob)return 0;
        if(alice>bob)return 1;
        return -1;
    }
};