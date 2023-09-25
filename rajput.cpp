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

void solve(node* root) {
    stack<pair<node*, int>> s;
    s.push({root, 1});
    string pre = "";
    string in = "";
    string post = "";

    while (!s.empty()) {
        int state = s.top().second;
        node* temp = s.top().first;

        if (state == 1) {
            pre += to_string(temp->data);
            s.top().second = state + 1;
            if (temp->left) {
                s.push({temp->left, 1});
            }
        }
        else if (state == 2) {
            in += to_string(temp->data);
            s.top().second = state + 1;
            if (temp->right) {
                s.push({temp->right, 1});
            }
        }
        else {
            post += to_string(temp->data);
            s.pop();
        }
    }
    cout << pre << endl;
    cout << in << endl;
    cout << post << endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    solve(root);
    return 0;
}

