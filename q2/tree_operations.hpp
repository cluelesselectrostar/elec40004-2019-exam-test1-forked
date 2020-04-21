#ifndef tree_operations_hpp
#define tree_operations_hpp

template<class Node, class Key>
bool tree_is_less_than(const Node *n, const Key &k)
 { //largest value on the left tree smaller than value.
    return (n==nullptr) || (
      ( n->value < k )
      && tree_is_less_than(n->left, k)
      && tree_is_less_than(n->right, k)
    );
}

template<class Node, class Key>
bool tree_is_greater_than(const Node *n, const Key &k)
 { //smaller value on the right tree larger than value.
    return (n==nullptr) || (
      ( k < n->value )
      && tree_is_greater_than(n->left, k)
      && tree_is_greater_than(n->right, k)
    );
}


template<class Node>
bool tree_is_search_tree(const Node *n)
{
    return (n == nullptr) || (
      tree_is_search_tree(n->left)
      && tree_is_search_tree(n->right)
      && tree_is_less_than(n->left, n->key)
      && tree_is_greater_than(n->right, n->key)
    );
}

template<class Node, class Key>
const Node *tree_lookup(const Node *n, const Key &k)
{
    if (n==nullptr) {
      return nullptr;
    } else {
      if(k < n->key){
          return tree_lookup(n->left, k);
      }else if(k > n->key){
          return tree_lookup(n->right, k);
      }else{
          assert(k = n->key);
          return n;
      }
    }

}

template<class Node>
void tree_delete(Node *n)
{
    if(n!=nullptr){
      tree_delete(n->left);
      tree_delete(n->right);
      delete n;
    }
}

#endif
