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

  Node *getGrandParent() {
    if (this->parent == NULL)
      return NULL;

    return this->parent->parent;
  }

  void rotateLeft() {
    Node *x = this;
    Node *z = this->right;

    if (x->parent->left == x)
      x->parent->left = z;
    if (x->parent->right == x)
      x->parent->right = z;

    x->right = z->left;
    if (z->left) {
      z->left->parent = x;
    }
    z->left = x;
    z->parent = x->parent;
    x->parent = z;

    if (z->height == 0) {
      z->height = -1;
      x->height = 1;
    } else {
      z->height = 0;
      x->height = 0;
    }
  }

  void doubleRotateRight() {}
};

class AVLTree {
public:
  Node *root;

  AVLTree() { this->root = nullptr; }

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

  void insert(int key, int value) {
    Node *parent = this->root;
    Node *searchedNode = parent;

    while (searchedNode != NULL) {
      if (searchedNode >= )
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  quicksort(a, 0, a.size() - 1);

  for (int i = 0; i < (int)a.size(); ++i) {
    cout << a[i] << endl;
  }

  return 0;
}