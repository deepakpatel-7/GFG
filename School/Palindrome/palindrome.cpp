//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		     int rev = 0;
            int temp = n;  // Store the original number
            
            while(n > 0) {
                int last = n % 10;
                rev = rev * 10 + last;
                n = n / 10;
            }
            
            if(rev == temp) {
                return "Yes";
            } else {
                return "No";
            }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends