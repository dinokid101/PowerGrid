#ifndef STRINGMAP_H
#define STRINGMAP_H

#include "stdafx.h"
#include <vector>

namespace cache {

  template<typename T> class StringMapEntry {
    private:
      cstring key;
      T *value;
    public:
      StringMapEntry();
      StringMapEntry(cstring k, T *v);

      cstring GetKey();
      T* GetValue();
  };

  template<typename T> StringMapEntry<T>::StringMapEntry() {
      key = NULL;
      value = NULL;
  }

  template<typename T> StringMapEntry<T>::StringMapEntry(cstring k, T* v) {
      key = k;
      value = v;
  }

  template<typename T> cstring StringMapEntry<T>::GetKey() {
    return key;
  }

  template<typename T> T* StringMapEntry<T>::GetValue() {
    return value;
  }

  template<typename T> class StringMap {
    private:
      /// Returns the hash code of the given string
      uint GetHash(cstring key);
      /// Rehashes the entire map and makes it the required size.
      void Rehash(uint newSize);

      StringMapEntry<T>* entries;

      uint reserved_size;
    public:
      /// Creates a StringMap with capacity 16
      StringMap();
      /// Creates a StringMap with capacity @c init_size
      StringMap(uint init_size);

      /// destructor for this StringMap, deletes all bindings
      ~StringMap();

      /// Ensures the capacity of the Map is at least @c minLength
      void ensureCapacity(uint minLength);
      /// Shrinks the Map to the minimum of the amount of elements and @c minLength
      void shrink(uint minLength);

      /// Returns the binding for the given key
      T Get(cstring key);

      /// Sets a binding for a key, possibly overwriting an already existing binding
      T Set(cstring key, T elem);
      /// Removes the binding for the given key
      T Remove(cstring key);

      /// Returns true iff the StringMap contains a binding for the given key
      bool contains(cstring key);

      /// Returns a vector of all keys in this StringMap
      std::vector<cstring> GetKeys();
      /// Returns a copy of all entries in this StringMap
      std::vector<StringMapEntry<T>> GetEntries();

  };


  template<typename T> uint StringMap<T>::GetHash(cstring key) {
    uint h = 0;
    for (uint i = 0; key[i] != 0;) {
      h = 31 * h + key[i++];
    }
    return h;
  }

  template<typename T> StringMap<T>::StringMap() {
    reserved_size = 16;
    entries = new StringMapEntry<T>[reserved_size];
  }

  template<typename T> StringMap<T>::StringMap(uint init_size) {
    reserved_size = init_size;
    entries = new StringMapEntry<T>[reserved_size];
  }

  template<typename T> StringMap<T>::~StringMap() {
    delete entries;
  }
}

#endif // STRINGMAP_H