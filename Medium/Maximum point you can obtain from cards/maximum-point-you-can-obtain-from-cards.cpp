//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
    int n = cardPoints.size();
    int left_sum = 0;
    int right_sum = 0;
    int max_sum = 0;
    
    // Calculate the initial left sum
    for (int i = 0; i < k; ++i) {
        left_sum += cardPoints[i];
    }
    
    max_sum = left_sum;
    
    // Iterate through the array, sliding the window and updating sums
    int right_index = n - 1;
    for (int i = k - 1; i >= 0; --i) {
        left_sum -= cardPoints[i];
        right_sum += cardPoints[right_index];
        max_sum = std::max(max_sum, left_sum + right_sum);
        right_index--;
    }
    
    return max_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends