#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};

void GetAllBalanceFactorsPreorder(struct Node* root);

int height(struct Node* node)
{
  if (node == NULL)
    return 0;
  return node->height;
}
 
int max(int a, int b)
{
  if (a > b) {
    return a;
  }
  else {
    return b;
  }
}
 
struct Node* NewNode(int key)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}
 
struct Node* RightRotate(struct Node* y)
{
    struct Node* x = y->left;
    struct Node* z = x->right;

    printf("In %s Node: %d\n", __func__, y->data);
 
    // Perform rotation
    x->right = y;
    y->left = z;
 
    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    // Return new root
    return x;
}
 
struct Node* LeftRotate(struct Node* x)
{
  struct Node* y = x->right;
  struct Node* z = y->left;

  printf("In %s Node: %d\n", __func__, x->data);
 
  // Perform rotation
  y->left = x;
  x->right = z;
 
  //  Update heights
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  // Return new root
  return y;
}
 
int GetBalance(struct Node* node)
{
  if (node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}
 
struct Node* Insert(struct Node* node, int data)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(NewNode(data));
    if (data < node->data)
        node->left  = Insert(node->left, data);
    else if (data > node->data)
        node->right = Insert(node->right, data);
    else 
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));
 
    /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
    int balance = GetBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return RightRotate(node);
 
    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return LeftRotate(node);
 
    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left =  LeftRotate(node->left);
        return RightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }
 
  return node;
}
 
int main(void)
{
  struct Node *root = NULL;
 
  root = Insert(root, 10);
  GetAllBalanceFactorsPreorder(root);
  printf("\n");
  root = Insert(root, 20);
  GetAllBalanceFactorsPreorder(root);
  printf("\n");
  root = Insert(root, 30);
  GetAllBalanceFactorsPreorder(root);
  printf("\n");
  root = Insert(root, 40);
  GetAllBalanceFactorsPreorder(root);
  printf("\n");
  root = Insert(root, 50);
  GetAllBalanceFactorsPreorder(root);
  printf("\n");
  root = Insert(root, 25);
  GetAllBalanceFactorsPreorder(root);
}

void GetAllBalanceFactorsPreorder(struct Node* root) {
  if (root == NULL) {
    return;
  }
  printf("Data: %d, BF: %d\n", root->data, GetBalance(root));
  GetAllBalanceFactorsPreorder(root->left);
  GetAllBalanceFactorsPreorder(root->right);
}