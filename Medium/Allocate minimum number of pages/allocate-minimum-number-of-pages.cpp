//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int countStudents(int arr[] , int pages , int n) {
    int students = 1;
    long long pagesStudent = 0;

    for(int i = 0; i < n; i++) {
        if(pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students;
}
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
         if(M > N) return -1;
    int low = *max_element(A, A+N);
    int high = accumulate(A, A+N, 0); // Include <numeric> for accumulate

    while(low <= high) {
        int mid = (low + high) / 2; // Fixed typo

        int students = countStudents(A, mid,N);

        if(students > M) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends