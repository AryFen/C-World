#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * left;
  struct Node * right;
};

struct Node* newNode(int data);
void Insert(struct Node* root);
void Delete(struct Node* root);
void printTreePre(struct Node *root);
void printTreeIn(struct Node *root);
void printTreePost(struct Node *root);
void Search(struct Node* root);
void padding(char ch, int n );
void structure( struct Node *root, int level);

int main(void) {

  int rootData;

  printf("Root: ");
  scanf("%d", &rootData);

  struct Node* root = newNode(rootData);

  while (1) {
    int choice;
    printf("Choice (1: Insert, 2: Delete, 3: Search, 4: Print, 5: Quit): ");
    scanf("%d", &choice);

    if (choice == 1) {
      Insert(root);
    }
    else if (choice == 2) {
      Delete(root);
    }
    else if (choice == 3) {
      Search(root);
    }
    else if (choice == 4) {
      int style;
      printf("Style (1: Prefix, 2: Infix, 3: Postfix, 4: Graphics): ");
      scanf("%d", &style);

      if (style == 1) {
        printTreePre(root);
      }
      else if (style == 2) {
        printTreeIn(root);
      }
      else if (style == 3) {
        printTreePost(root);
      }
      else if (style == 4) {
        structure(root, 0);
      }
      else {
        printf("Error: Option does not exist!\n");
      }
    }
    else if (choice == 5) {
      printf("Quitting...\n");
      break;
    }
    else {
      printf("Error: Option does not exist!\n");
    }
  }
}

struct Node* newNode(int data) {
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void Insert(struct Node* root) {

  int data;

  printf("Insert: ");
  scanf("%d", &data);
  struct Node* curr = root;
  while (curr != NULL) {
    if (curr->data == data) {
      printf("Duplicates not allowed!\n");
      return;
    }
    if (data < curr->data) {
      if (curr->left == NULL) {
        break;
      }
      curr = curr->left;
    }
    else {
      if (curr->right == NULL) {
        break;
      }
      curr = curr->right;
    }
  }
  if (data < curr->data) {
    curr->left = newNode(data);
    return;
  }
  curr->right = newNode(data);
  return;
}

void Delete(struct Node* root) {

  int data;

  printf("Delete: ");
  scanf("%d", &data);
  struct Node* curr = root;

  if (root->left == NULL && root->right == NULL && root->data == data) {
    printf("Full deletion not allowed!\n");
    return;
  }
  if (root->data == data) {
    printf("Root node cannot be deleted.\n");
    return;
  }

  while (curr != NULL) {
    if (data < curr->data) {
      if (curr->left == NULL) {
        break;
      }
      if (curr->left->data == data) {
        struct Node* temp = curr->left;
        if (temp->right != NULL) {
          temp->right->left = temp->left;
          curr->left = temp->right;
          return;
        }
        else if (temp->left != NULL) {
          temp->left->right = temp->right;
          curr->left = temp->left;
          return;
        }
        else {
          free(temp);
          curr->left = NULL;
          return;
        }
      }
      curr = curr->left;
    }
    else if (data > curr->data) {
      if (curr->right == NULL) {
        break;
      }
      if (curr->right->data == data) {
        struct Node* temp = curr->right;
        if (temp->left != NULL) {
          temp->left->right = temp->right;
          curr->right = temp->left;
          return;
        }
        else if (temp->right != NULL) {
          temp->right->left = temp->left;
          curr->right = temp->right;
          return;
        }
        else {
          free(temp);
          curr->right = NULL;
          return;
        }
      }
      curr = curr->right;
    }
  }
  printf("Data is not found!\n");
  return;
}

void printTreePre(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printf("Data: %d\n", root->data);
  printTreePre(root->left);
  printTreePre(root->right);
}

void printTreeIn(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printTreeIn(root->left);
  printf("Data: %d\n", root->data);
  printTreeIn(root->right);
}

void printTreePost(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printTreePost(root->left);
  printTreePost(root->right);
  printf("Data: %d\n", root->data);
}

void Search(struct Node* root) {

  int data;

  printf("Search: ");
  scanf("%d", &data);

  struct Node* curr = root;

  while (curr != NULL) {
    if (data < curr->data) {
      curr = curr->left;
    }
    else if (data > curr->data) {
      curr = curr->right;
    }
    else {
      printf("Found!\n");
      return;
    }
  }
  printf("Not Found!\n");
  return;
}

void padding(char ch, int n ){
  int i;
  
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void structure(struct Node *root, int level) {

  int i;
  
  if (root == NULL) {
    padding('\t', level);
    puts("~");
  }
  else {
    structure(root->right, level + 1);
    padding('\t', level);
    printf("%d\n", root->data);
    structure(root->left, level + 1);
  }
}
