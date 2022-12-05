
#include "passserver.hpp"
#include <iostream>

using namespace std;


bool validateChoice(char choice) {
  bool valid = false;
  switch(choice){
    case('a'):
    case('r'):
    case('c'):
    case('e'):
    case('v'):
    case('n'):
    case('x'):
      valid = true;
      break;
    default:
      break;
  }

  return valid;
}

const string menu = "a - Add User\nr - Remove User\nc - Change User Password\ne - Check Existence of a User\nv - Validate Password for a User\nn - Number of Users\nx - Exit program\n\n";

char getChoice() {
  bool valid = false;
  char choice;

  cout << menu << "Enter choice : ";
  cin >> choice;
  cout << choice << endl;

  valid = validateChoice(choice);
  
  while(!valid){
    cout << "Invalid choice! Please try again:\n" << menu << "Enter choice : ";
    cin >> choice;
    cout << choice << endl;
  }

  return choice;
}

string getUsername() {
  string username;

  cout << "Please enter the username:\n";
  cin >> username;
  cout << username << endl;

  return username;
}

string getPass() {
  string password;

  cout << "Please enter the current password:\n";
  cin >> password;
  cout << password << endl;

  return password;
}

string getNewPass() {
  string password;

  cout << "Please enter the new password:\n";
  cin >> password;
  cout << password << endl;

  return password;
}

int main() {
  char choice;
  PassServer ps;

  do {
    choice = getChoice();

    // add user
    if(choice == 'a'){
      string username = getUsername();
      string password = getPass();

      if(ps.AddUser(username, password))
        cout << "    Succesfully added the user: " << username << '\n' << endl;
      else
        cout << "    Failed to add the user: " << username << '\n' << endl;
    }

   // remove user
    if(choice == 'r'){
      string username = getUsername();
    
      if(ps.HasUser(username)){
        string password = getPass();
        if(ps.Validate(username, password)){
          if(ps.RemoveUser(username))
            cout << "    Successfully removed the user: " << username << "\n\n" << endl;
        }
        else
          cout << "    Failed to remove the user: " << username << "\n\n" << endl;
      }
      else {
        cout << "    Could not find user: " << username << "\n\n" << endl;
      }
    }

    // change user password
    if(choice == 'c'){
      string username = getUsername();
      string password = getPass();   
      string newPass = getNewPass();

      if(ps.UpdatePassword(username, password, newPass))
        cout << "    Succeed to update the user " << username << "\n\n" << endl;
      else
        cout << "    Fail to update the user " << username << "\n\n" << endl;
    }

    // add user
    if(choice == 'e'){
      string username = getUsername();

      if(ps.HasUser(username))
        cout << "    Found user: " << username << " in the database" << "\n\n" << endl;
      else
        cout << "    Could not find user: " << username << "\n\n" << endl;
    }

    // validate user
    if(choice == 'v'){
      string username = getUsername();
      string password = getPass();
      if(ps.Validate(username, password)) 
        cout << "    Succeed to validate the user " << username << "\n\n" << endl;
      else
        cout << "    Fail to validate the user " << username << "\n\n" << endl;     
    }

    // add user
    if(choice == 'n'){
      cout << "    The current number of users is: " << ps.GetSize() << "\n\n" << endl;
    }

  } while(choice != 'x');

  // cout << "Goodbye! :)" << endl;
  return 0;
}