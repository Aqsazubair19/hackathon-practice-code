#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
public:

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


static int idx = -1;
Node* BuildTree(int preorder[],int n){
     idx++;
    if(preorder[idx] == -1 || idx >=n ){
        return NULL;
    }
   
    Node* root = new Node(preorder[idx]);
    root->left = BuildTree(preorder,n);  // left subtree of root 
    root->right = BuildTree(preorder,n);  // right subtree of root
    
     return root;

}

// preorder traversal (ROOT-LEFT-RIGHT)
void preorder_traversal(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";           // root

    preorder_traversal(root->left);  // left
    preorder_traversal(root->right); // right

}

// identical trees:
bool identical(Node* p , Node* q){
    if(p ==NULL || q == NULL){
        return p==q;
    }

   bool  isleft_same = identical(p->left,q->left);
   bool  isright_same = identical(p->right,q->right);

   return isleft_same && isright_same && p->data == q->data ;
}

// is subtree of another tree :
bool isSubtree(Node* root , Node* subroot){
  if (root == NULL || subroot == NULL){
    return root == subroot;
  }

    if(root->data == subroot->data && identical(root,subroot)){
        return true;
    }

    return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
}


  int main(){
 // int  preorder[7]={1,2,-1,-1,3,-1,-1};
   int  preorder[11]={1,2,-1,-1,3,4,-1,-1,5,-1,-1};



    Node* root = BuildTree(preorder,11);
   cout<<"root note: "<<root->data<<endl;
  
   cout<<"perorder traversel: ";
   preorder_traversal(root);
   cout<<endl; 

   //int  preorder_1[7]={1,2,-1,-1,3,-1,-1}; 
    int  preorder_1[7]={3,4,-1,-1,5,-1,-1};

   idx = -1;  // reset idx because its static so it reach to 7 already when build first tree;
   Node* root1 = BuildTree(preorder_1,7);
   cout<<"root note: "<<root1->data<<endl;
  
   cout<<"perorder-1 traversel: ";
   preorder_traversal(root1);
   cout<<endl;

   cout<<"identical(1) or not identical(0) :"<<identical(root,root1)<<endl;


   cout<<"is one tree is subtree of another :"<<isSubtree(root,root1);
  }
