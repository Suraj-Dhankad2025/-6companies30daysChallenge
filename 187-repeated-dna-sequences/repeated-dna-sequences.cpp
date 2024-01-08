class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
         vector<string>ans;
        int j=0;
        map<string, int>m;
        string st="";
        while(j<s.size()){
            if(j<9){
                st+=s[j];
                j++;
            }
            else{
                st+=s[j];
                m[st]++;
                st.erase(st.begin(), st.begin()+1);
                j++;
            }
        }
        for(auto i:m){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};