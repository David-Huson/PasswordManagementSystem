#include "../hashtable.hpp"
#include "catch/catch.hpp"
#include <string>

using namespace std;

TEST_CASE("Constructor, resize, get capacity, and get size ops") {
  HashTable<string, string> hashTable;
  CHECK(hashTable.GetSize() == 0);
  CHECK(hashTable.GetCapacity() == 101);
  hashTable.Resize(103);
  CHECK(hashTable.GetSize() == 0);
  CHECK(hashTable.GetCapacity() == 103);
}

TEST_CASE("Insert ops") {
  HashTable<string, string> hashTable;
  CHECK(hashTable.Insert("abc", "pass"));
  // duplicate insert will fail
  CHECK(!hashTable.Insert("abc", "pass1"));
  HashTable<string, string> hashTable1(2);
  CHECK(hashTable1.Insert("abc", "pass"));
  CHECK(hashTable1.Insert("bbc", "pass"));
  // will fail because the size is going beyond the capacity
  CHECK(!hashTable1.Insert("cbc", "pass"));
}
