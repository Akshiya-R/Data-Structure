#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// code to insert or create new node
struct node* NewNode(int element)
{
 
 struct node* newNode = new node();
 newNode->key = element;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}

// code to find the node with minimum value
struct node* minNode(struct node* node)
{
    struct node* current = node;
 
    // loop will continue until it find the leftmost node which is the node with minimum value
    while (current && current->left != NULL)
        current = current->left;
    return current;
} 

// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root!=NULL){
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);
  }
    
  
}

// Insert a node
struct node *insertNode(struct node *node, int key) {

  if(node==NULL){
    return NewNode(key);
  }
    
  if(key<node->key){
    node->left=insertNode(node->left,key);
  }
  else if(key>node->key){
    node->right=insertNode(node->right,key);
  }
  return node;

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if(root==NULL){
    return root;
  }
  if (key < root->key){
    root->left = deleteNode(root->left,key);
  }
  else if(key > root->key){
    root->right = deleteNode(root->right,key);
  }
  else{
        // if there is no left child 
        if (root->left == NULL) {
                struct node* temp_Node = root->right;
                delete root;
                return temp_Node;
        
        // if there is no right child
        } else if (root->right == NULL) {
            struct node* temp_Node = root->left;
            delete root;
            return temp_Node;
        }
        
        struct node* temp_Node = root->right;
        while (temp_Node && temp_Node->left != NULL) {
            temp_Node = temp_Node->left;
        }
        root->key = temp_Node->key;
        root->right = deleteNode(root->right, temp_Node->key);
        }
    return root;
}
 


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}