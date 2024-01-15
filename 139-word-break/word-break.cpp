class Node{
  public:
  bool flag;
  Node* links[26];
  Node(){
    flag = 0;
    for(int i = 0;i < 26;i++) links[i] = NULL;
  }
};

class Trie{
  public:
  Node* root;
  Trie(){
    root = new Node();
  }
  void insert(string s){
    Node* node = root;
    for(int i = 0;i < s.size();i++){
      if(node->links[s[i] - 'a']==NULL) node->links[s[i] - 'a'] = new Node();
      node = node->links[s[i] - 'a'];
    }

    node->flag= 1;
  }

  bool find(string s){
    Node* node = root;
    for(int i = 0;i < s.size();i++){
      if(node->links[s[i] - 'a']==NULL) return 0;
      node = node->links[s[i] - 'a'];
    }
    return node->flag;
  }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, 0);
        dp[0] = true;
        Trie trie;
        for(auto it:wordDict) trie.insert(it);
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if(dp[j] && trie.find(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};