//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
    string ans="";
    int i=0,j=0;
    int n = src.size();
    while(j<n){
        ans+=src[i];
        int c=0;
        while(src[j]==src[i]){
            j++;
            c++;
        }
        i = j;
        ans+=c+'0';
    }
    return ans;
}     
 
