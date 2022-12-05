#ifndef TEXTMENU_HPP
#define TEXTMENU_HPP

#include <iostream>
using namespace std;

class TextMenu {
  private:
    const string menu = "a - Add User\nr - Remove User\nc - Change User Password\ne - Check Existence of a User\nv - Validate Password for a User\nn - Number of Users\nx - Exit program\n";
    char getChoice() {
      bool valid = false;
      char choice;

      cout << menu << "Enter choice : ";
      cin >> choice;
      cout << endl;

      valid = validateChoice(choice);
      
      while(!valid){
        cout << "Invalid choice! Please try again:\n" << menu << "Enter choice : ";
        cin >> choice;
        cout << endl;
      }
    }
    
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
    string getUsername();
    string getPass();

  public:
    TextMenu();
    void run();
};

#endif