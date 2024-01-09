class Solution {
public:
    int ans=0;
    bool check(string &a, string &b){
        int i=0,j=a.size()-1;
        while(i<j){
            if(a[i]!=a[j]){
                return false;
            }
            j--;
            i++;
        }
        i = 0;
        j = b.size()-1;
        while(i<j){
            if(b[i]!=b[j]){
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
    void find(int i, string &s, string &p, string &q){
        if(i>=s.size()){
            if(check(p, q)){
                ans = max(ans, (int)p.size()*(int)q.size());
            }
            return ;
        }
        p.push_back(s[i]);
        find(i+1, s, p, q);
        p.pop_back();

        q.push_back(s[i]);
        find(i+1, s, p, q);
        q.pop_back();
        find(i+1, s, p, q);
        
    }
    int maxProduct(string s) {
        string p="",q="";
        find(0, s, p, q);
        return ans;
    }
};