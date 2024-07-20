//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int largestel(vector<int> &arr, int n)
    {
        int max = 0;
        
        for(int i =0;i<n;i++){
            if(max<arr[i]){
                max = arr[i];
            }
        }
        
        return max;
    }
    
    int print2largest(vector<int> &arr) {
        int n = arr.size();
        int largest = largestel(arr , n);
        
        int res = -1;
        
        for(int i =0;i<n;i++){
            if(arr[i]!=largest){
                if(res == -1){
                    res = arr[i];
                }
                
                else if(arr[i] > res){
                    res = arr[i];
                }
            }
            
            
            
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends