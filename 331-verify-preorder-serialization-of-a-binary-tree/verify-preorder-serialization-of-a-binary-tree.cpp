class Solution {
public:
    bool isValidSerialization(string preorder) {
        int node=1;
        stringstream ss(preorder);
        string s;
        while(getline(ss, s, ',')){
            node--;
            if(node<0)return false;
            if(s!="#")node+=2;
        }
        return node==0;
    }
};