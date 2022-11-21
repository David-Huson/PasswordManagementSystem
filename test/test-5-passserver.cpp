#include "../passserver.hpp"
#include "catch/catch.hpp"
#include <string>

using namespace std;

TEST_CASE("Add users") {
  PassServer passServer;
  CHECK(passServer.AddUser("bjohn", "123"));
  // duplicate add should fail
  CHECK(!passServer.AddUser("bjohn", "111"));
  CHECK(passServer.AddUser("clynn", "123"));
  PassServer passServer1(2);
  CHECK(passServer1.AddUser("bjohn", "123"));
  CHECK(passServer1.AddUser("clynn", "123"));
  // fail because beyond capacity
  CHECK(!passServer1.AddUser("jsmith", "123"));
}

TEST_CASE("Remove users") {
  PassServer passServer;
  CHECK(passServer.AddUser("bjohn", "123"));
  CHECK(passServer.RemoveUser("bjohn"));
  CHECK(!passServer.RemoveUser("notexist"));
}

TEST_CASE("Validate users") {
  PassServer passServer;
  CHECK(passServer.AddUser("bjohn", "123"));
  CHECK(passServer.Validate("bjohn", "123"));
  // wrong password
  CHECK(!passServer.Validate("bjohn", "111"));
  // user not exist
  CHECK(!passServer.Validate("ajohn", "111"));
}

TEST_CASE("Check existence of users") {
  PassServer passServer;
  CHECK(!passServer.HasUser("bjohn"));
  CHECK(passServer.AddUser("bjohn", "123"));
  CHECK(passServer.HasUser("bjohn"));
  CHECK(passServer.RemoveUser("bjohn"));
  CHECK(!passServer.HasUser("bjohn"));
  // other non-exist user
  CHECK(!passServer.HasUser("ajohn"));
}

TEST_CASE("Update passwords for users") {
  PassServer passServer;
  CHECK(passServer.AddUser("bjohn", "123"));
  CHECK(passServer.Validate("bjohn", "123"));
  // fail with wrong password
  CHECK(!passServer.UpdatePassword("bjohn", "111", "123"));
  // fail with wrong username
  CHECK(!passServer.UpdatePassword("ajohn", "123", "111"));
  CHECK(passServer.UpdatePassword("bjohn", "123", "111"));
  // password changed
  CHECK(passServer.Validate("bjohn", "111"));
}
