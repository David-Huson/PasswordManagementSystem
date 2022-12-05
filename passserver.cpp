#include "passserver.hpp"
#include "sha1.hpp"

PassServer::PassServer(int capacity) : table(capacity) {}

std::string PassServer::Hash(const std::string& password){
  SHA1 hash_func;
  hash_func.update(password);
  return hash_func.final();
}

bool PassServer::AddUser(const std::string& username, const std::string& password){
  std::string hashedPass = Hash(password);
  return table.Insert(username, hashedPass);
}
bool PassServer::RemoveUser(const std::string& username){
  return table.Remove(username);
}
bool PassServer::Validate(const std::string& username, const std::string& password){
  return table.Exist(username, Hash(password));
}
bool PassServer::UpdatePassword(const std::string& username, const std::string& oldPassword, const std::string& newPassword){
  if(Validate(username, oldPassword)){
    table.Remove(username);
    return table.Insert(username, Hash(newPassword));
  }
  return false;
}
bool PassServer::HasUser(const std::string& username){
  return table.HasKey(username);
}
int PassServer::GetSize(){
  return table.GetSize();
}