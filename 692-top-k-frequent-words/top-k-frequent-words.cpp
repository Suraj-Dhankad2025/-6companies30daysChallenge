class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<int>pq;
        map<string, int>m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        for(auto i:m){
            pq.push(i.second);
        }
        vector<string>ans;
        while(!pq.empty() && ans.size()<k){
            int f = pq.top();
            pq.pop();
            for(auto i:m){
                if(i.second==f){
                    ans.push_back(i.first);
                    m.erase(i.first);
                    break;
                }
            }
        }
        return ans;
    }
};