//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        vector<int> arr3;
        int n1 = array1.size(), n2 = array2.size();
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (array1[i] < array2[j]) 
                arr3.push_back(array1[i++]);
            else 
                arr3.push_back(array2[j++]);
        }

        while (i < n1)
            arr3.push_back(array1[i++]);
        while (j < n2)
            arr3.push_back(array2[j++]);

        int n = n1 + n2;
        if (n % 2 == 1) {
            return arr3[n / 2];
        }
        return (double)(arr3[n / 2] + arr3[n / 2 - 1]) / 2.0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends