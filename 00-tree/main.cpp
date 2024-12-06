#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this-> data = data;
        left = NULL;
        right = NULL;
    }
};
Node* work(Node* root){
    if(root == NULL){
        return root;
    }
    Node* left = work(root -> left);
    Node* right = work(root -> right);
    root -> left = right;
    root -> right = left;
    return root;
}
int work(Node* root,int carry,int t,int &flag){
    if(root == NULL && carry == t){
        flag = 1;
        return t;
    }
    if(root == NULL){
        return 0;
    }
    carry = root -> data + carry;
    int ans;
    if(flag == 0) ans = work(root -> left, carry, t,flag);
    if(flag == 0) ans = work(root -> right , carry , t,flag);
    return ans;
}
bool fun(Node* root,int target,int flag){
    if(work(root,0,target,flag) == target){
        return true;
    }
    return false;
}
int main() {
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    
    Node* ans = work(head);
    cout << fun(head,50,0);
    return 0;
}