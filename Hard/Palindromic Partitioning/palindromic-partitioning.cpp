//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPallindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    int find(int i, string s, vector<int>&dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int ans = INT_MAX;
        for(int j=i; j<s.size(); j++){
            string t = s.substr(i, j-i+1);
            if(isPallindrome(t)){
                ans = min(ans, 1 + find(j+1, s, dp));
            }
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string str)
    {
        vector<int>dp(str.size(), -1);
        return find(0,str, dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends