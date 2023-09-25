/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include <bits/stdc++.h>
#include<stack>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(node* root, vector<int>& pre, vector<int>& in, vector<int>& post) {
    stack<pair<node*, int>> s;
    s.push({root, 1});

    while (!s.empty()) {
        int state = s.top().second;
        node* temp = s.top().first;

        if (state == 1) {
            pre.push_back(temp->data);
            s.top().second = state + 1;
            if (temp->left) {
                s.push({temp->left, 1});
            }
        }
        else if (state == 2) {
            in.push_back(temp->data);
            s.top().second = state + 1;
            if (temp->right) {
                s.push({temp->right, 1});
            }
        }
        else {
            post.push_back(temp->data);
            s.pop();
        }
    }
}

int main() {
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    solve(root, pre, in, post);

    cout << "Pre-order: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "In-order: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Post-order: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

