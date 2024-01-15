class Solution {
public:
    string frequencySort(string s) {
        map<char, int>m;
        for(auto i:s){
            m[i]++;
        }
        string ans="";
        priority_queue<int>pq;
        for(auto i:m){
            pq.push(i.second);
        }
        while(!pq.empty()){
            int f = pq.top();
            pq.pop();
            char ch;
            for(auto i:m){
                if(i.second==f){
                    ch = i.first;
                    m.erase(i.first);
                    break;
                }
            }
            while(f--){
                ans+=ch;
            }
        }
        return ans;
    }
};