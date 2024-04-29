//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int findMax(vector <int> &v){
        int maxi = INT_MIN;
        int n = v.size();

        for( int i = 0; i<n ; i++){
            maxi = max(maxi , v[i]);
        }

        return maxi;
    }

    int CalculateTotalHours(vector <int> &v , int hourly){
    long long totalH = 0; 

    int n = v.size();

    for (int i = 0; i < n; i++) {
       
        totalH += (v[i] + hourly - 1) / hourly; 

        
        if (totalH > INT_MAX) return INT_MAX;
    }

    return totalH;
    }
  
    int Solve(int N, vector<int>& piles, int H) {
    int low = 1, high = findMax(piles);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long totalH = CalculateTotalHours(piles, mid);

        if (totalH <= H) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends