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

class TreeNode {
public:
  int value;

  TreeNode(int key, int value, TreeNode *parent) {
    this->key = key;
    this->value = value;
    this->right = nullptr;
    this->left = nullptr;
  }

  bool isLeaf() { return this->right == nullptr && this->left == nullptr; }

  int getKey() { return this->key; }

  int getValue() { return this->value; }

  void setValue(int value) { this->value = value; }

  TreeNode *getRightChild() { return this->right; }

  void setRightChild(TreeNode *child) { this->right = child; }

  TreeNode *getLeftChild() { return this->left; }

  void setLeftChild(TreeNode *child) { this->left = child; }

protected:
  int key;
  TreeNode *right;
  TreeNode *left;
};

class BSTTree {
public:
  TreeNode *root;

  BSTTree() { this->root = nullptr; }

  TreeNode *search(const int &key) { return this->root; }

  void insert(const int &key, const int &value) {
    if (this->root == nullptr) {
      this->root = new TreeNode(key, value, nullptr);
      return;
    }

    TreeNode *searched = this->root;

    while (searched != nullptr) {
      if (searched == nullptr) {
        cerr << "Could not find where to update node." << endl;
        return;
      }

      if (searched->getKey() == key) {
        cerr << "Key already exists in tree, updating instead." << endl;
        searched->setValue(value);
        return;
      }

      if (key > searched->getKey()) {
        if (searched->getRightChild() == nullptr) {
          TreeNode *newNode = new TreeNode(key, value, searched);
          searched->setRightChild(newNode);
          return;
        } else {
          searched = searched->getRightChild();
        }
      } else {
        if (searched->getLeftChild() == nullptr) {
          TreeNode *newNode = new TreeNode(key, value, searched);
          searched->setLeftChild(newNode);
          return;
        } else {
          searched = searched->getLeftChild();
        }
      }
    }
  }

  void removed(const int &key) {}

  void update(const int &key) {}
};

void InorderBST(TreeNode *root) {
  if (root == nullptr)
    return;
  InorderBST(root->getLeftChild());
  cout << "key: " << root->getKey() << " value: " << root->getValue() << endl;
  InorderBST(root->getRightChild());
}

void Preorder(TreeNode *root) {
  if (root == nullptr)
    return;
  cout << "key: " << root->getKey() << " value: " << root->getValue() << endl;
  InorderBST(root->getLeftChild());
  InorderBST(root->getRightChild());
}

void Postorder(TreeNode *root) {
  if (root == nullptr)
    return;
  InorderBST(root->getLeftChild());
  InorderBST(root->getRightChild());
  cout << "key: " << root->getKey() << " value: " << root->getValue() << endl;
}

int main() {
  BSTTree *bst = new BSTTree();

  bst->insert(122, 344);
  bst->insert(1, 110);
  bst->insert(8, 0);
  bst->insert(150, -33);

  cout << "Inorder: " << endl;
  InorderBST(bst->root);
  cout << "Preorder: " << endl;
  Preorder(bst->root);
  cout << "Postorder: " << endl;
  Postorder(bst->root);

  return 0;
}