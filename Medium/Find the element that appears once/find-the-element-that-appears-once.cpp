//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	     int n  = N;
        if(n==1) return A[0];
        if(A[0]!=A[1]) return A[0];
        if(A[n-1]!=A[n-2]) return A[n-1];

        int low = 1 ; 
        int high = n-2;

        while(low<=high){
            int mid = (low+high)/2;

            if(A[mid] != A[mid+1] && A[mid]!=A[mid-1]){
                return A[mid];
            }
            //left half
            if((mid%2==1 && A[mid]==A[mid-1]) || (mid%2==0 && A[mid]==A[mid+1])){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;


	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends