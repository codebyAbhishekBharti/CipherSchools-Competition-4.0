#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(NULL), prev(NULL) {}
};

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;
    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == NULL) ? low : i->next;
            swap(i->data, j->data);
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i->data, high->data);
    return i;
}

void quick_sorst_helper(Node* low, Node* high) {
    if (high != NULL && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quick_sorst_helper(low, pivot->prev);
        quick_sorst_helper(pivot->next, high);
    }
}

Node* quickSort(Node* head) {
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    quick_sorst_helper(head, tail);
    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int data;
    cin >> data;
    Node* head = new Node(data);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        cin >> data;
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    quickSort(head);
    print(head);

    return 0;
}
