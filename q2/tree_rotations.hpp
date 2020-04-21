#ifndef tree_rotations_hpp
#define tree_rotations_hpp

#include <cassert>

template<class Node>
Node *tree_rotate_right(Node *N4)
{
    Node *newparent = N4->left;
    N4->left = (N4->left)->right;
    newparent->right = N4;
    return newparent;
}

template<class Node>
Node *tree_rotate_left(Node *N2)
{
  Node *newparent = N2->right;
  N2->right = (N2->right)->left;
  newparent->left = N2;
  return newparent;
}

#endif
