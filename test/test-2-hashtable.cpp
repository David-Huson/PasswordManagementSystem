#include "../hashtable.hpp"
#include "catch/catch.hpp"
#include <string>

using namespace std;

TEST_CASE("Remove ops") {
  HashTable<string, string> hashTable;
  CHECK(hashTable.Insert("abc", "pass"));
  CHECK(hashTable.Insert("bbc", "pass"));
  CHECK(hashTable.Remove("abc"));
  CHECK(!hashTable.Remove("abc"));
  CHECK(!hashTable.Remove("aaa"));
  CHECK(hashTable.Remove("bbc"));
}

TEST_CASE("Resize") {
  HashTable<string, string> hashTable;
  CHECK(hashTable.Insert("abc", "pass"));
  CHECK(hashTable.Insert("bbc", "pass"));
  CHECK(hashTable.GetSize() == 2);
  CHECK(hashTable.GetCapacity() == 101);
  hashTable.Resize(5);
  CHECK(hashTable.GetSize() == 0);
  CHECK(hashTable.GetCapacity() == 5);
}
