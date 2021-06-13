#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
  
    // Given String
    string str("Welcome to GeeksforGeeks!");
  
    // Character to be found
    char ch = 'e';
  
    // To store the index of last
    // character found
    size_t found;
  
    // Position till search is performed
    int pos = 6;
  
    // Function to find the last
    // character ch in str[0, pos]
    found = str.find_last_of(ch, pos);
  
    // If string doesn't have
    // character ch present in it
    if (found == string::npos) {
        cout << "Character " << ch
             << " is not present in"
             << " the given string.";
    }
  
    // Else print the last position
    // of the character
    else {
        cout << "Character " << ch
             << " is found at index: "
             << found << endl;
    }
}
