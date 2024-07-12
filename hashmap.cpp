#ifdef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <list>
#include <string>
#include <functional>

template <class K, class V>
class HashMap {
  public:
    HashMap(int tableSize);
    void insert(const K& key, const V& val);
    V* search(const K& key);

  private:
    struct HashTableItem {
      K key;
      V val;
    };

  std::vector<std::list<HashTableItem>> table;
};

unsigned int Hash(const int& i) {
  return i;
}

unsigned int Hash(const char& c) {
  return c;
}

unsigned int Hash(const std::string& s) {
  int num = 0;
  for (int i = 0; i < s.size(); i++) {
    num += s.at(i);
  }
  return num;
}

unsigned int Hash(const double& d) {
  return int(d);
}

template<classK, class V>
void HashMap<K, V>::insert(const K& key, const V& val) {
  int keyIndex = Hash(key) % table.size();
  HashTableItem newItem = {key, val};
  for (HashTableItem &h : table.at(keyIndex)) {
    if (h.key == key) {
      h.val = val;
      return;
    }
  }
  (table.at(keyIndex)).push_back(newItem);
}

template<classK, class V>
V* HashMap<K, V>::search(const K& key) {
  int newIndex = Hash(key) % table.size();
  for (HashTableItem &h : table.at(newIndex)) {
    if (h.key == key) {
      return &(h.val);
    }
  }
  return nullptr;
}

#endif /* HASHMAP_H */
