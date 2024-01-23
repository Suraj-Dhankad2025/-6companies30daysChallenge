class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string>s;
        for(auto i:startWords){
            string temp = i;
            sort(temp.begin(), temp.end());
            s.insert(temp);
        }
        int ans=0;
        for(auto i:targetWords){
            string temp = i;
            sort(temp.begin(), temp.end());
            for(int ind=0; ind<temp.size(); ind++){
                // string t = temp.substr(0,ind) + temp.substr(ind+1);
                if(s.find(temp.substr(0,ind) + temp.substr(ind+1))!=s.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};