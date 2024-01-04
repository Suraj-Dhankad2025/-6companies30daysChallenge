class DataStream {
public:
      int val;
    int K;
    int cnt;
    DataStream(int value, int k) {
        this->val = value;
        this->K = k;
        this->cnt = 0;
    }
    
    bool consec(int num) {
        if(num==val){
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(cnt>=K)return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */