#include "../hashtable.hpp"
#include "catch/catch.hpp"
#include <string>

using namespace std;

TEST_CASE("HasKey, and exist ops") {
  HashTable<string, string> hashTable;
  CHECK(!hashTable.HasKey("abc"));
  CHECK(!hashTable.Exist("abc", "pass"));
  CHECK(hashTable.Insert("abc", "pass"));
  CHECK(hashTable.Exist("abc", "pass"));
  CHECK(!hashTable.Exist("bbc", "pass"));
  CHECK(!hashTable.Exist("abc", "bass"));
  CHECK(hashTable.HasKey("abc"));
  CHECK(!hashTable.HasKey("bbc"));
  CHECK(hashTable.Remove("abc"));
  CHECK(!hashTable.Exist("abc", "pass"));
  CHECK(!hashTable.HasKey("abc"));
}

