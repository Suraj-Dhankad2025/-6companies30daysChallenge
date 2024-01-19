class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
      int ans = 0;
        int n = words.size();
        unordered_map<string, int> m;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });

        for (int i = 0; i < n; i++) {
            m[words[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (m[words[i]] > 0) {
                ans += words[i].size() + 1;
                string suffix="";
                for (int j = words[i].size() - 1; j >= 0; j--) {
                    suffix = words[i][j] + suffix;
                    if (m[suffix] > 0) {
                        m[suffix] = 0;
                    }
                }
            }
        }
        return ans;
    }
};