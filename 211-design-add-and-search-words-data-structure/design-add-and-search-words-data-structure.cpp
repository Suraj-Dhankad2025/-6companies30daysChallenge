struct Node{
    Node* link[26];
    bool end = false;
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
        Node* head = root;
        for(int i=0; i<26; i++){
            head->link[i]=NULL;
        }
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++){
            if(temp->link[word[i]-'a']==NULL){
                temp->link[word[i]-'a'] = new Node();
            }
            temp = temp->link[word[i]-'a'];
        }
        temp->end = true;
    }
    bool find(Node* temp, string& word, int i) {
        if (i == word.length()) {
            return temp->end;
        }
        char c = word[i];
        if (c == '.') {
            for (auto child : temp->link) {
                if (child && find(child, word, i + 1)) {
                    return true;
                }
            }
            return false;
        } 
        else{
            int idx = c - 'a';
            if(!temp->link[idx]){
                return false;
            }
            return find(temp->link[idx], word, i + 1);
        }
    }
    bool search(string word) {
        return find(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */