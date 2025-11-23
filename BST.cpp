#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
         data = val;
         left = right = NULL;
    }
};

// insert :

Node* insert(Node* root , int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right , val);
    }

    return root;
}

// buld bst:

Node* buildBST(int arr[], int n){
    Node* root = NULL;

    // for(int val : arr){
    //     root = insert(root,val);
    // }

    for(int i=0; i<n;i++){
        root = insert(root,arr[i]);
    }

    return root;
}

// search 

Node* search(Node* root , int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        cout<<"value found ";
        return root;
    }

    if(key < root->data){
        return search(root->left , key);

    }
    else{
        return search(root->right, key);
    }
}

// get inorder successr for delete function:

Node* getinorderSuccessor(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }

    return root;
}
// delete:

Node*  deletenode(Node* root, int key){
  if(root == NULL){
    return NULL;
  }

  if(key <root->data){
    root->left = deletenode(root->left,key);
  }
  else if(key > root->data){
    root->right = deletenode(root->right , key);
  }
  else{
    // key == root->data
    // 0 chld + 1 child 

    if(root->left == NULL){
        Node* temp = root->right;
        delete root;
        return temp;
    }else if(root->right == NULL){
         Node* temp = root->left;
        delete root;
        return temp;   
    }
    else{
        // 2 children 
        Node* IS = getinorderSuccessor(root->right); // successor is left most val of right sub tree of node 
        root->data = IS->data;  // now yoir rrot is successor 
        root->right= deletenode(root->right,IS->data);  // now successor right will delete 
    }
    
    return root;
  }

}

// min :
Node* min(Node* root){
    if(root ==NULL){
        return NULL;
    }

    if(root->left == NULL){
        return root;
    }

    return  min(root->left);
}

// max 
Node* max(Node* root){
     if(root ==NULL){
        return NULL;
    }

    if(root->right == NULL){
        return root;
    }

    return  max(root->right);
}

// sucessor 
Node* successor(Node* root , int key){
    if(root== NULL) return  NULL;

    Node* curr = search(root,key);
    if(curr == NULL){
        return NULL;
    }

    if(curr->right == NULL){
        return NULL;
    }else{
        return min(curr->right);
    }

}

// predecessor
Node* predecessor(Node* root, int key){
    if(root== NULL) return  NULL;

    Node* curr = search(root,key);
    if(curr == NULL){
        return NULL;
    }

    if(curr->left == NULL){
        return NULL;
    }else{
        return max(curr->left);
    }
    
}
// height 
int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height,right_height)+1;

}


// dfs

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root){
    if(root == NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//bfs

void levelorder_traversal(Node* root){
    queue<Node*> q;
    
    q.push(root);

    while(q.size()>0 ){

       Node* curr = q.front();
       q.pop();
       cout<<curr->data<<" ";

       if(curr->left != NULL){
       q.push(curr->left);
       }

       if(curr->right != NULL){
       q.push(curr->right);
    } 

}
  
}

void level_order_travesal_level_by_level(Node* root){
  queue<Node*> q;

  q.push(root);
  q.push(NULL);
  while(q.size()>0){
    Node* curr = q.front();
    q.pop();

    if(curr==NULL){
        if(!q.empty()){
            cout<<endl;
            q.push(NULL);
            continue;
        }else{
            break;
        }
    }

    cout<<curr->data<<" ";

    if(curr->left != NULL){
        q.push(curr->left);
    }

    if(curr->right != NULL){
        q.push(curr->right);
    }
  }

}


int main(){
    int arr[6] = {3,2,1,5,6,4};
    Node* root = buildBST(arr,6);
    cout<<"root : "<<root->data<<endl;

    cout<<"trversal in inorder:";
    inorder(root);
    cout<<endl;

    
    //  cout<<" data found : 1 for yes and 0 for no :"<<search(root,5)<<endl;
    // cout<<" data found : 1 for yes and 0 for no :"<<search(root,7)<<endl;

    //root= deletenode(root,3);   // reassign root 

    //cout<<" updated root : "<<root->data<<endl;
    // cout<<"trversal in inorder:";
    // inorder(root);
    //  cout<<endl;


    Node* minimum = min(root);
    cout<<"mimimum value of bst: "<<minimum->data<<endl; 
    


    Node* maximum = max(root);
     cout<<"miximum value of bst: "<<maximum->data<<endl; 


    
     Node* suc= successor(root,3);
     if(suc != NULL){
     cout<<"SUCCESSOR :"<<suc->data<<endl;
     }else{
        cout<<"successor not found"<<endl;
     }


      Node* pre= predecessor(root,3);
     if(pre!= NULL){
     cout<<"PREDECESSOR: "<<pre->data<<endl;
     }else{
        cout<<"PREDECESSOR not found"<<endl;
     }

     cout<<"height of bst:"<<height(root)<<endl;
     
     cout<<"preorder: "<<" ";
     preorder(root);
     cout<<endl;

     cout<<"post order: "<<" ";
     postorder(root);
     cout<<endl;

     cout<<"level  order (bfs): "<<endl;
     levelorder_traversal(root);
     cout<<endl;

    cout<<"level  order  level by level (bfs): "<<endl;
     level_order_travesal_level_by_level(root);
     cout<<endl;


    cout<<" data found : 1 for yes and 0 for no :"<<search(root,5)<<endl;
    cout<<" data found : 1 for yes and 0 for no :"<<search(root,7)<<endl;

    root= deletenode(root,3);   // reassign root 

    cout<<" updated root : "<<root->data<<endl;
    cout<<"trversal in inorder:";
    inorder(root);
     cout<<endl;

    return 0;
}
