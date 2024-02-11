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
    this->parent = parent;
  }

  ~TreeNode() {}

  bool hasRightSubtree() { return this->right != nullptr; }

  bool hasLeftSubtree() { return this->left != nullptr; }

  bool isChild() { return this->parent != nullptr; }

  bool isRightChild() { return isChild() && this->parent->right == this; }

  bool isLeftChild() { return isChild() && !isRightChild(); }

  bool isLeaf() { return this->right == nullptr && this->left == nullptr; }

  TreeNode *digLeft() {
    TreeNode *current = this;

    while (current->hasLeftSubtree()) {
      current = current->getLeftChild();
    }

    return current;
  }

  TreeNode *digRight() {
    TreeNode *current = this;

    while (current->hasRightSubtree()) {
      current = current->getRightChild();
    }

    return current;
  }

  int getKey() { return this->key; }

  int getValue() { return this->value; }

  void setValue(int value) { this->value = value; }

  TreeNode *getRightChild() { return this->right; }

  void setRightChild(TreeNode *child) { this->right = child; }

  TreeNode *getLeftChild() { return this->left; }

  void setLeftChild(TreeNode *child) { this->left = child; }

  TreeNode *getParent() { return this->parent; }

  void setParent(TreeNode *parent) { this->parent = parent; }

protected:
  int key;
  TreeNode *right;
  TreeNode *left;
  TreeNode *parent;
};

class BSTTree {
public:
  TreeNode *root;

  BSTTree() { this->root = nullptr; }

  TreeNode *search(const int &key) {
    TreeNode *current = this->root;
    while (current != NULL) {
      if (current->getKey() == key)
        return current;

      if (key > current->getKey()) {
        current = current->getRightChild();
      } else {
        current = current->getLeftChild();
      }
    }

    return nullptr;
  }

  void insert(const int &key, const int &value) {
    if (this->root == nullptr) {
      this->root = new TreeNode(key, value, nullptr);
      return;
    }

    TreeNode *searched = this->root;

    while (searched != nullptr) {
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

  void recursiveRemove(TreeNode *node, const int &key) {
    if (node == nullptr)
      return;

    if (key < node->getKey()) {
      recursiveRemove(node->getLeftChild(), key);
    } else if (key > node->getKey()) {
      recursiveRemove(node->getRightChild(), key);
    } else {
      if (node->isLeaf()) {
        if (node->isRightChild()) {
          node->getParent()->setRightChild(nullptr);
        }
        if (node->isLeftChild()) {
          node->getParent()->setLeftChild(nullptr);
        }

        delete node;
      } else if (node->hasLeftSubtree() && !node->hasRightSubtree()) {
        // Set the parent node child to be the right subtree
        if (node == root) {
          this->root = node->getLeftChild();
        } else {
          if (node->isRightChild()) {
            node->getParent()->setRightChild(node->getLeftChild());
          }
          if (node->isLeftChild()) {
            node->getParent()->setLeftChild(node->getLeftChild());
          }
        }
        node->getLeftChild()->setParent(node->getParent());

        delete node;
      } else if (!node->hasLeftSubtree() && node->hasRightSubtree()) {
        // Set the parent node child to be the right subtree
        if (node == root) {
          this->root = node->getRightChild();
        } else {
          if (node->isRightChild()) {
            node->getParent()->setRightChild(node->getRightChild());
          }
          if (node->isLeftChild()) {
            node->getParent()->setLeftChild(node->getRightChild());
          }
          node->getRightChild()->setParent(node->getParent());

          delete node;
        }
      } else {
        TreeNode *inorderSucessor = node->getRightChild()->digLeft();

        if (node == this->root) {
          this->root = inorderSucessor;
        }

        TreeNode *inorderSucessorRightChild = inorderSucessor->getRightChild();

        if (inorderSucessorRightChild) {
          inorderSucessorRightChild->setParent(node);
        }

        if (node->getRightChild() != inorderSucessor)
          node->getRightChild()->setParent(inorderSucessor);
        node->getLeftChild()->setParent(inorderSucessor);

        if (node->getRightChild() != inorderSucessor)
          inorderSucessor->setRightChild(node->getRightChild());
        else
          inorderSucessor->setRightChild(nullptr);
        inorderSucessor->setLeftChild(node->getLeftChild());

        TreeNode *inorderParent = inorderSucessor->getParent();

        if (node->isLeftChild()) {
          node->getParent()->setLeftChild(inorderSucessor);
        }

        if (node->isRightChild()) {
          node->getParent()->setRightChild(inorderSucessor);
        }

        inorderSucessor->setParent(node->getParent());
        node->setParent(inorderParent);
        node->setRightChild(inorderSucessorRightChild);
        node->setLeftChild(nullptr);

        recursiveRemove(node, node->getKey());
      }
    }
  }

  void update(const int &key, const int &value) {
    TreeNode *node = search(key);
    if (node)
      node->setValue(value);
  }
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
  bst->insert(8, 90);
  bst->insert(150, -33);

  cout << "Inorder: " << endl;
  InorderBST(bst->root);

  cout << "Preorder: " << endl;
  Preorder(bst->root);

  cout << "Postorder: " << endl;
  Postorder(bst->root);

  cout << "Searching for 8" << endl;
  TreeNode *searchedNode = bst->search(8);
  cout << searchedNode->getKey() << " " << searchedNode->getValue() << endl;

  bst->update(8, -1);
  cout << "Searching for 8" << endl;
  searchedNode = bst->search(8);
  cout << searchedNode->getKey() << " " << searchedNode->getValue() << endl;

  cout << "Removing 122" << endl;
  bst->recursiveRemove(bst->root, 122);

  cout << bst->root->getKey() << endl;
  if (bst->root->getRightChild())
    cout << bst->root->getRightChild()->getKey() << endl;

  bst->insert(122, 104);
  bst->insert(-63, 0);
  bst->insert(-64, 0);
  bst->insert(-65, 0);
  bst->insert(987, 21);
  bst->insert(33, 22);
  cout << "Removing 33" << endl;
  bst->recursiveRemove(bst->root, 33);
  cout << "Removing 22" << endl;
  bst->recursiveRemove(bst->root, 22);
  cout << "Removing -63" << endl;
  bst->recursiveRemove(bst->root, -63);
  cout << "Removing 8" << endl;
  bst->recursiveRemove(bst->root, 8);

  cout << "Inorder: " << endl;
  InorderBST(bst->root);

  return 0;
}