//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* reverse(Node* head){
     if (head==NULL || head->next==NULL) return head;

      Node* newHead = reverse(head->next);

       Node* front = head->next;
       front->next  = head;
       head->next = NULL;
       return newHead;
   }
   
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head==NULL || head->next==NULL) return true;

        Node* slow = head;
        Node* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newHead = reverse(slow->next);
        Node* Firsthead = head;
        Node* Secondhead = newHead;

        while(Secondhead!=NULL){
            if(Firsthead->data!=Secondhead->data){
                reverse(newHead);
                return false;
            }
            Firsthead = Firsthead->next;
            Secondhead = Secondhead->next;

            
        }
        reverse(newHead);
            return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends