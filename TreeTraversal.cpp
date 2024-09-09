#include <iostream>
using namespace std;
#include<queue>

// Make class for tree
class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
      this->data = val;
      this->left = NULL;
      this->right = NULL;
    }

};

// Function to create tree
Node* createTree(){
  // take input for data from user
  cout<<"enter data for node"<<endl;
  int data;
  cin>>data;

  if(data == -1){
    return NULL;
  }
  // create a node
  Node* newNode = new Node(data);

  // create leftNode
  cout<<"enter data for leftNode of: "<<data<<endl;
  newNode->left = createTree();
  // create rightNode
  cout<<"enter data for right node of: "<<data<<endl;
  newNode->right = createTree();

  return newNode;

}

// function to print NLR
void preOrderTraversal(Node* root){
  if(root == NULL){
    return;
  }
  // NLR
  cout<<root->data<<" ";
  // print left node
  preOrderTraversal(root->left);
  // print right node
  preOrderTraversal(root->right);
  
}

// Function to print LNR
void inOrderTraversal(Node* root){
  if(root == NULL){
    return;
  }
  // LNR
  // print left node
  inOrderTraversal(root->left);
  // print node
  cout<<root->data<<" ";
  // print right node
  inOrderTraversal(root->right);

}

// Function to print LRN
void postOrderTraversal(Node* root){
  if(root == NULL){
    return;
  }
  // LRN
  // print left node
  postOrderTraversal(root->left);
  // print right node
  postOrderTraversal(root->right);
  // print node
  cout<<root->data<<" ";

}

// function to print levelOrderTraversal
void levelOrderTraversal(Node* root){
  // make a queue
  queue<Node*> q;
  q.push(root);

  // push and pop in queue and print data until queue is empty
  while(!q.empty()){
    // access the front element from queue
    Node* front = q.front();
    cout<<front->data<< " ";
    // delete front element from queue
    q.pop();

    // push in queue child of front element
    if(front->left != NULL){
      q.push(front->left);
    }
    if(front->right != NULL){
      q.push(front->right);
    }
  }
}

// main function
int main() {
  Node* root = createTree();
  // cout<<root->data<<endl;
  cout<<"preOrderTraversal"<<endl;
  preOrderTraversal(root);
  cout<<endl;
  cout<<"inOrderTraversal"<<endl;
  inOrderTraversal(root);
  cout<<endl;
  cout<<"postOrderTraversal"<<endl;
  postOrderTraversal(root);
  cout<<endl;
  cout<<"levelOrderTraversal"<<endl;
  levelOrderTraversal(root);
  
  return 0;
}
