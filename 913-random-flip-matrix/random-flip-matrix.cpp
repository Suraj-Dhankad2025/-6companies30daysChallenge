class Solution {
public:
    set<pair<int,int>>s;
    int M,N;
    Solution(int m, int n) {
        this->M = m;
        this->N = n;
    }
    vector<int> flip() {
        int x = rand()%M;
        int y = rand()%N;
        if(s.find({x, y})==s.end()){
            s.insert({x,y});
            return {x, y};
        }
        return flip();
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */