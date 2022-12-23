#include <stdio.h>
#include <stdlib.h>


struct Node {
  int val;
  struct Node *left_node;
  struct Node *right_node;
  int length;
};

int max(int a, int b) {
  return (a > b) ? a : b;
}

int length(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->length;
}




struct Node *newNode(int val) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->val = val;
  node->left_node = NULL;
  node->right_node = NULL;
  node->length = 1;
  return (node);
}





struct Node *rotate_left_node(struct Node *x) {
  struct Node *y = x->right_node;
  struct Node *switch = y->left_node;

  y->left_node = x;
  x->right_node = switch;

  x->length = max(length(x->left_node), length(x->right_node)) + 1;
  y->length = max(length(y->left_node), length(y->right_node)) + 1;

  return y;
}
struct Node *rotate_right_node(struct Node *y) {
  struct Node *x = y->left_node;
  struct Node *switch = x->right_node;

  x->right_node = y;
  y->left_node = switch;

  y->length = max(length(y->left_node), length(y->right_node)) + 1;
  x->length = max(length(x->left_node), length(x->right_node)) + 1;

  return x;
}


int balance(struct Node *N) {
  if (N == NULL)
    return 0;
  return length(N->left_node) - length(N->right_node);
}


struct Node *inser_node(struct Node *node, int val) {

  if (node == NULL)
    return (newNode(val));

  if (val < node->val)
    node->left_node = inser_node(node->left_node, val);
  else if (val > node->val)
    node->right_node = inser_node(node->right_node, val);
  else
    return node;


  node->length = 1 + max(length(node->left_node),
               length(node->right_node));

  int balance = balance(node);
  if (balance > 1 && val < node->left_node->val)
    return rotate_right_node(node);

  if (balance < -1 && val > node->right_node->val)
    return rotate_left_node(node);

  if (balance > 1 && val > node->left_node->val) {
    node->left_node = rotate_left_node(node->left_node);
    return rotate_right_node(node);
  }

  if (balance < -1 && val < node->right_node->val) {
    node->right_node = rotate_right_node(node->right_node);
    return rotate_left_node(node);
  }

  return node;
}

struct Node *minode(struct Node *node) {
  struct Node *current = node;

  while (current->left_node != NULL)
    current = current->left_node;

  return current;
}


struct Node *delete_node(struct Node *parent, int val) {

  if (parent == NULL)
    return parent;

  if (val < parent->val)
    parent->left_node = delete_node(parent->left_node, val);

  else if (val > parent->val)
    parent->right_node = delete_node(parent->right_node, val);

  else {
    if ((parent->left_node == NULL) || (parent->right_node == NULL)) {
      struct Node *temp = parent->left_node ? parent->left_node : parent->right_node;

      if (temp == NULL) {
        temp = parent;
        parent = NULL;
      } else
        *parent = *temp;
      free(temp);
    } else {
      struct Node *temp = minode(parent->right_node);

      parent->val = temp->val;

      parent->right_node = delete_node(parent->right_node, temp->val);
    }
  }

  if (parent == NULL)
    return parent;


  parent->length = 1 + max(length(parent->left_node),
               length(parent->right_node));

  int balance = balance(parent);
  if (balance > 1 && balance(parent->left_node) >= 0)
    return rotate_right_node(parent);

  if (balance > 1 && balance(parent->left_node) < 0) {
    parent->left_node = rotate_left_node(parent->left_node);
    return rotate_right_node(parent);
  }

  if (balance < -1 && balance(parent->right_node) <= 0)
    return rotate_left_node(parent);

  if (balance < -1 && balance(parent->right_node) > 0) {
    parent->right_node = rotate_right_node(parent->right_node);
    return rotate_left_node(parent);
  }

  return parent;
}


void print_it(struct Node *parent) {
  if (parent != NULL) {
    printf("%d ", parent->val);
    print_it(parent->left_node);
    print_it(parent->right_node);
  }
}

int main() {
  struct Node *parent = NULL;

  parent = inser_node(parent, 1);
  parent = inser_node(parent, 2);
  parent = inser_node(parent, 3);
  parent = inser_node(parent, 4);
  parent = inser_node(parent, 5);
  parent = inser_node(parent, 6);
  parent = inser_node(parent, 7);
  parent = inser_node(parent, 8);
  parent = inser_node(parent, 9);
  parent = inser_node(parent, 10);
  parent = inser_node(parent, 11);
  parent = inser_node(parent, 12);
  parent = inser_node(parent, 13);
  parent = inser_node(parent, 14);

  print_it(parent);

  parent = delete_node(parent, 3);

  printf("\nAfter deletion: ");
  print_it(parent);

  return 0;
}
