#include "../hashtable.hpp"
#include "catch/catch.hpp"
#include <string>

using namespace std;

TEST_CASE("Get size ops") {
  HashTable<string, string> hashTable;
  CHECK(hashTable.Insert("abc", "pass"));
  CHECK(hashTable.GetSize() == 1);
  CHECK(hashTable.Insert("bbc", "pass"));
  CHECK(hashTable.GetSize() == 2);
  CHECK(hashTable.Remove("abc"));
  CHECK(hashTable.GetSize() == 1);
  CHECK(hashTable.Remove("bbc"));
  CHECK(hashTable.GetSize() == 0);
}

TEST_CASE("Clear ops") {
  HashTable<string, string> hashTable;
  CHECK(hashTable.Insert("abc", "pass"));
  CHECK(hashTable.HasKey("abc"));
  CHECK(hashTable.Insert("bbc", "pass"));
  CHECK(hashTable.HasKey("bbc"));
  CHECK(hashTable.GetSize() == 2);
  hashTable.Clear();
  CHECK(hashTable.GetSize() == 0);
  CHECK(!hashTable.HasKey("abc"));
  CHECK(!hashTable.HasKey("bbc"));
}
