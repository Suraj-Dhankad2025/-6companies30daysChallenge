class Solution {
public:
   string getHint(string secret, string guess) {
        string ans="";
        int a=0;
        int b=0;
        unordered_map<int, int>m;
        for(int i=0; i<secret.size(); i++){
            if(secret[i]!=guess[i])
            m[secret[i]]++;
        }
        for(int i=0; i<secret.size(); i++){
            if(secret[i]==guess[i]){
                a++;
            }
            else if(m.find(guess[i])!=m.end() && m[guess[i]]>0){
                m[guess[i]]--;
                b++;
            }
        }
        ans+=to_string(a);
        ans+="A";
        ans+=to_string(b);
        ans+="B";
        return ans;
    }
};