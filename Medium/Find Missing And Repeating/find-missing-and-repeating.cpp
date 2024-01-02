//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int a=0, b=0;
        unordered_map<int, int>m;
        for(int i=0; i<n; i++){
            if(m.find(arr[i])!=m.end()){
                b=arr[i];
            }
            m[arr[i]]++;
        }
        for(int i=0; i<n; i++){
            if(m.find(i+1)==m.end()){
                a = i+1;
            }
        }
        return {b,a};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends