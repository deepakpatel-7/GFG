//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
         if(dividend == divisor){
            return 1;
        }
        bool sign = true;

        if(dividend >= 0 && divisor < 0 ) sign = false;
        else if(dividend <=0 && divisor > 0) sign = false;

        long n = abs(dividend);
        long d = abs(divisor);

        divisor = abs(divisor);
        long quotient = 0;

        while(n>=d){
            int cnt  = 0;
            while(n>=(d << (cnt+1))){
                cnt+=1;
            }
            quotient += 1<<cnt;
            n-= (d<<cnt);
        }

        if(quotient == (1<<31) && sign){
            return INT_MAX;
        }

        if(quotient == (1<<31) && !sign) {
            return INT_MIN;
        }

        return sign ? quotient: -quotient;

    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends