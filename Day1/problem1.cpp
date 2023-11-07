#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data):data(data),next(NULL){}
};
Node* make(int n){
    if(n==0) return NULL;
    int data;
    cin >> data;
    Node* head=new Node(data);
    Node* tail=head;
    for(int i=1;i<n;i++)
    {
        cin >> data;
        Node* nn=new Node(data);
        tail->next=nn;
        tail=nn;
    }
    return head;
}
void print(Node* root){
    while(root){
        cout << root-> data << " ";
        root = root->next;
    }
    cout << endl;
}

Node* reverse(Node* &head, vector<int> v, int i = 0) {
    if(!head or i>=v.size() or v[i]==0) return head;
    Node* next = NULL;
    Node* prev = NULL;
    Node* current = head;
    while (v[i]-- and current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if (next) head->next = reverse(next, v, ++i);
    else head->next = NULL;
    return prev;
}
void helper(Node* &head, vector<int> v, int i = 0){
    if (head == NULL) return;
    Node* nn = reverse(head, v, i);
    head = nn;
}
int main()
{

    /* 
    Input format
    12
    1 2 3 4 5 6 7 8 9 10 11 -1
    3
    2 3 4
    */
    int n;
    cin >> n;
    Node* root = make(n);
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    helper(root, v);
    print(root);
    return 0;
}
