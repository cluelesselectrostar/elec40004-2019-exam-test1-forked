#include <string>
#include "tree_operations.hpp"
#include "tree_rotations.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

struct Node
{
    string key;
    int value;
    Node *left;
    Node *right;
};

int main () {

  Node *n1 = new Node;
  Node *n2 = new Node;
  Node *n3 = new Node;
  Node *n4 = new Node;
  Node *n5 = new Node;
  cerr << "initialised nodes and assigned with pointers" << endl;

  //Define original tree (lefted)
  n2->left = n1;
  n2->right = n3;
  n4->left = n2;
  n4->right = n5;
  cerr << "defined tree" << endl;

  cerr << "rotate right" << endl;
  tree_rotate_right(n4);
  //cerr << (n2->left == n1) << (n2->right == n4) << (n4->left == n3) << (n4->right == n5) << endl;
  if ((n2->left == n1) && (n2->right == n4) && (n4->left == n3) && (n4->right == n5)) {
    cerr << "rotated right correctly" << endl;
  } else {
    cerr << "rotate right function incorrect";
    exit(1);
  }

  cerr << "rotate left" << endl;
  tree_rotate_left(n2);
  //cerr << (n2->left == n1) << (n2->right == n3) << (n4->left == n2) << (n4->right == n5) << endl;
  if ((n2->left == n1) && (n2->right == n3) && (n4->left == n2) && (n4->right == n5)) {
    cerr << "rotated left (back to original state) correctly" << endl;
    return 0;
  } else {
    cerr << "rotate left function incorrect";
    exit(1);
  }

}
