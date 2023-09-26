#include<iostream>
#include <bits/stdc++.h>
#include<stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

pair<bool, int> isSumTreeFast(Node* root) {
    //base case
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool isLeft = leftAns.first;
    bool isRight = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = (isLeft && isRight) && (root->data == leftSum + rightSum);

    pair<bool, int> ans;

    if (condn) {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else {
        ans.first = false;
    }
    return ans;
}

int main() {
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(10);
    root->left->right = new Node(10);
    root->right->right = new Node(30);

    bool isSumTree = isSumTreeFast(root).first;
    cout << isSumTree << endl;

    return 0;
}
