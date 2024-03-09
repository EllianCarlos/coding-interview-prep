#include <bits/stdc++.h>
#define debug(args...)                                                         \
  printf(args);                                                                \
  fflush(stdout)
using namespace std;

typedef long long ll;
typedef double db;
typedef float fl;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

#define pb push_back
#define mk make_pair
#define se second
#define fi first
#define eb emplace_back
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]:" << x << endl;

class Node {
public:
  int key;
  int value;
  int height;
  int bf;
  Node *right;
  Node *left;
  Node *parent;

  Node(int key, int value, int height, Node *parent) {
    this->key = key;
    this->value = value;
    this->parent = parent;
    this->height = height;

    this->right = NULL;
    this->left = NULL;
  }

  Node (int key, int value, Node *parent) {
    this->key = key;
    this->value = value;
    this->parent = parent;
    this->height = 0;
    this->right = NULL;
    this->left = NULL;
  }

  Node *getGrandParent() {
    if (this->parent == NULL)
      return NULL;

    return this->parent->parent;
  }
};

class AVLTree {
public:
  Node *root;
  int count;

  AVLTree() { 
    this->root = nullptr;
    this->count = 0;
  }

  Node *search(int key) {
    Node *current = this->root;

    while (current != NULL && current->value != key) {
      if (key == current->value) {
        return current;
      }

      if (key > current->value) {
        current = current->right;
        continue;
      }

      current = current->left;
    }

    return NULL;
  }

  bool insert(int key, int value) {
    root = insert(root, key, value, nullptr);
    return true;
  }

private:
  Node* insert(Node *node, int key, int value, Node *pNode) {
    if (node == nullptr) return new Node(key, value, pNode);

    if (key < node->key) {
      node->left = insert(node->left, key, value, node);
    } else {
      node->right = insert(node->right, key, value, node);
    }

    update(node);

    return balance(node);
  }

  void update(Node* node) {
    int leftNodeHeight = (node->left == nullptr) ? -1 : node->left->height;
    int rightNodeHeight = (node->right == nullptr) ? -1 : node->right->height;

    node->height = 1 + max(leftNodeHeight, rightNodeHeight);

    node->bf = rightNodeHeight - leftNodeHeight;
  }

  Node* balance(Node* node) {
    if (node->bf == -2) {
      if (node->left->bf <= 0) {
	return leftLeftCase(node);
      } else {
	return leftRightCase(node);
      }
    } else if (node->bf == +2) {
      if (node->right->bf >= 0) {
	return rightRightCase(node);
      } else {
	return rightLeftCase(node);
      }
    }

    return node;
  }

  Node* leftLeftCase(Node* node) {
    return rightRotation(node);
  }

  Node* leftRightCase(Node* node) {
    node->left = leftRotation(node->left);
    return leftLeftCase(node);
  }

  Node* rightRightCase(Node* node) {
    return leftRotation(node);
  }
  
  Node* rightLeftCase(Node* node) {
    node->right = rightRotation(node);
    return rightRightCase(node);
  }

  Node* leftRotation(Node* node) {
    Node *newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;

    newParent->parent = node->parent;
    newParent->right->parent = newParent;
    newParent->left->parent = newParent;
    update(node);
    update(newParent);
    return newParent;
  }

  Node* rightRotation(Node* node) {
    Node *newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;

    newParent->parent = node->parent;
    newParent->right->parent = newParent;
    newParent->left->parent = newParent;
    update(node);
    update(newParent);
    return newParent;
  }
};


void dfs(Node *n) {
  if (n == nullptr) return;
  dfs(n->left);
  cout << "Key: " << n->key << " V: " << n->value << endl;
  dfs(n->right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  AVLTree *tree = new AVLTree();
  
  tree->insert(0, 1);
  tree->insert(1, 1);
  tree->insert(2, 1);
  tree->insert(3, 1);
  tree->insert(4, 1);

  // traversing

  Node *n = tree->root;

  dfs(n);

  return 0;
}
