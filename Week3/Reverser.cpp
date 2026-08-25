#include "Reverser.h"

int Reverser::reverseDigit(int value) {
  if (value < 0) {  // Error input
    return -1;
  }

  if (value < 10) {  // Return single digit
    return value;
  }

  int lastDigit = value % 10;  // Grab last digit
  int remaining = value / 10;  // Value w/out last digit

  int multiplier = 1;  // How many 10s
  int temp =
      remaining;  // To find how many 10s in remaining digits (always => 10)

  while (temp > 0) {  // Find how many 10s
    multiplier *= 10;
    temp /= 10;
  }

  return (lastDigit * multiplier) + reverseDigit(remaining);
}

std::string Reverser::reverseString(std::string characters) {
  if (characters.empty()) {
    return "ERROR";
  }

  if (characters.length() == 1) { // If 1 letter or last
    return characters;
  }

  char last = characters.back(); // Last letter
  characters.pop_back(); // Remove last

  return last + reverseString(characters);
}