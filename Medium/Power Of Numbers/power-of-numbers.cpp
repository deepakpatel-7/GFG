//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    
   long long power(int N, int R) {
        const int MOD = 1000000007;
        long long result = myPow(N, R);
        return result < 0 ? result + MOD : result;
    }
    
    const int MOD = 1000000007;

    long long myPow(long long x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        long long half = myPow(x, n / 2) % MOD;
        long long ans = (half * half) % MOD;

        if (n % 2 == 1) {
            ans = (ans * x) % MOD;
        }

        return ans;
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends