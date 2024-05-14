//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
     vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = S.size();
      int len = 0;
      while (right < n) {
        if (mpp[S[right]] != -1)
          left = max(mpp[S[right]] + 1, left);

        mpp[S[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
}