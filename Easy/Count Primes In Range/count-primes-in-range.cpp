//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPrimes(int L, int R) {
         if (R <= 1 || L > R) return 0;
        int limit = sqrt(R);
        std::vector<int> prime(R - L + 1, 1);

        // Special case for 0 and 1
        if (L <= 1) prime[0] = 0;

        for (int i = 2; i <= limit; ++i) {
            for (int j = std::max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
                if (j >= L && prime[j - L] == 1) {
                    prime[j - L] = 0;
                }
            }
        }

        int count = 0;
        for (int i = L; i <= R; ++i) {
            if (prime[i - L] == 1) {
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
// } Driver Code Ends