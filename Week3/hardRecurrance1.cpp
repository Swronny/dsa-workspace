// Write tail a recursive function to check whether a string is a palindrome

#include <string>

using namespace std;

bool palindrome(string str) {
  // Base case
  if (str.length() <= 1) {
    return true;
  }

  if (str[0] != str[str.length() - 1]) { // If first and last don't match, false
    return false;
  }

  str.erase(0, 1); // Remove 1st and last chars in string.
  str.erase(str.length() - 1, 1);

  return palindrome(str);
}