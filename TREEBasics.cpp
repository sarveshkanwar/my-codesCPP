#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;

    node *left;
    node *right;
    
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
        


    }

};

void preorder(node *root){
    if(root==NULL){
        return ;
     }
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);

}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void postorder(node *root){
    if(root==NULL)
    {
        return;
    }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    
}
node *makeTree(node *root){
   
        cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
     if(data==-1)return NULL;
     cout<<"enter data for inserting left of "<<root->data<<endl;

    root->left=makeTree(root->left);
     cout<<"enter data for inserting right of "<<root->data<<endl;
     root->right=makeTree(root->right);
    return root;
}
void buildFromLevelOrder(node *&root){
    queue<node*>q;
    cout<<"enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        cout<<"enter left node for"<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"enter righn node for:"<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }

}
int main()
{
    node *root=NULL;
   //root= makeTree(root);
   buildFromLevelOrder(root);
//    5 6 7 -1 -1 9 -1 -1 4 -1 -1
   // inorder(root);
    // cout<<endl;
    // postorder(root);


    return 0;
}