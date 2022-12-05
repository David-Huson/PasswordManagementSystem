#ifndef PASS_SERVER_HPP
#define PASS_SERVER_HPP

#include "hashtable.hpp"

class PassServer {

  private:
    HashTable<std::string, std::string> table;
    std::string Hash(const std::string& password);

  public:
    explicit PassServer(int capacity = 101);
    bool AddUser(const std::string& username, const std::string& password);
    bool RemoveUser(const std::string& username);
    bool Validate(const std::string& username, const std::string& password);
    bool UpdatePassword(const std::string& username, const std::string& oldPassword, const std::string& newPassword);
    bool HasUser(const std::string& username);
    int GetSize();
};

#endif