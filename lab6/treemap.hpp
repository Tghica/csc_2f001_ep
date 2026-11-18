
#include <iostream>
#include <string>

template <class K, class V>
struct treemap_t {
  struct pair_t {
    K key;
    V value;
  };
  struct node_t:pair_t{
    node_t* left;
    node_t* right;
    node_t* parent;
    node_t(node_t* parent);
  };
  struct iterator_t {
    node_t* cur;
    iterator_t(node_t* cur);
    void next();
  };
  node_t* root = nullptr;
  node_t* lookup(node_t** pcur, node_t* parent, const K* key, bool create);
  void set_at(const K key, const V value);
  V at(const K key);
  void display();
  void display_behind(node_t* cur, std::string prefix);
  iterator_t begin();
};

template <class K, class V>
treemap_t<K, V>::node_t::node_t(node_t* parent)
    : left(nullptr), right(nullptr), parent(parent) {}

template <class K, class V>
typename treemap_t<K, V>::node_t*
treemap_t<K, V>::lookup(
    node_t** pcur,
    node_t* parent,
    const K* key,
    bool create
) {
  node_t* current = *pcur;

  if (current == nullptr) {
    if (!create) {
      return nullptr;
    }

    *pcur = new node_t(parent);
    (*pcur)->key = *key;
    return *pcur;
  }

  if (*key == current->key) {
    return current;
  }

  if (*key < current->key) {
    return lookup(&current->left, current, key, create);
  }

  return lookup(&current->right, current, key, create);
}


template <class K, class V>
V treemap_t<K, V>::at(const K key) {
  node_t* node = lookup(&root, nullptr, &key, false);
  if (node == nullptr) {
    return V(false);
  }
  return node->value;
}

template <class K, class V>
void treemap_t<K, V>::set_at(const K key, const V value) {
  node_t* node = lookup(&root, nullptr, &key, true);
  node->value = value;
}

template <class K, class V>
void treemap_t<K, V>::display() {
  display_behind(root, "");
}

template <class K, class V>
void treemap_t<K, V>::display_behind(node_t* cur, std::string prefix) {
  if (cur == nullptr) {
    return;
  }

  display_behind(cur->left, prefix + "  ");

  std::cout << prefix << "(" << cur->key << ", " << cur->value << ")" << std::endl;

  display_behind(cur->right, prefix + "  ");
}

template <class K, class V>
treemap_t<K, V>::iterator_t::iterator_t(node_t* cur) {
  while (cur != nullptr && cur->left != nullptr) {
    cur = cur->left;
  }
  this->cur = cur;
}

template <class K, class V>
void treemap_t<K, V>::iterator_t::next() {
  iterator_t& it = *this;
  if (it.cur == nullptr) {
    it.cur = nullptr;
    return;
  }
  if (it.cur->right != nullptr) {
    it.cur = it.cur->right;
    return;
  }
  node_t* parent = it.cur->parent;
  while (parent != nullptr && it.cur == parent->right) {
    it.cur = parent;
    parent = parent->parent;
  }
  it.cur = parent;
  return;
}

template <class K, class V>
typename treemap_t<K, V>::iterator_t
treemap_t<K, V>::begin() {
  return iterator_t(root);
}