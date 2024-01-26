class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(auto i:asteroids){
            if(mass<i){
                return false;
            }
            if(mass<asteroids.back()){
                mass+=i;
            }
        }
        return true;
    }
};