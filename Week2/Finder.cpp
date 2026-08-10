#include "Finder.h"
using namespace std;
// s1: ababcabcdef, s2: abcd => {0, 0, 2, 5}
vector<int> Finder::findSubstrings(string s1, string s2) {
  vector<int> result;
  size_t start = 0;

  // Loops for length of s2
  // Loop starting with prefix size 1, then 2, ...
  for (size_t i = 1; i <= s2.size(); i++) {
    // Find substring of current index
    // s2.substr(0, i), index 0 to current loop index
    result.push_back(-1); // Default val to -1 and update it to found value

    // Start from start, last successful searches' index
    // Without start, starts from 0, doesn't mean end of match ends there
    size_t found = s1.find(s2.substr(0, i), start);

    if (found != string::npos) {  // npos = not found, so get opposite
      result[i - 1] = found; // Result vector stores index of substring, start at 0 obviously.
      start = found; // Start search from found index

    } else {
      // If prefix not found, NO LONGER prefix can be found either and ENDS loop
      // Without, will still continue remainder of for loop USELESSly

      // Adding -1 for remaining prefix of s2
      for (size_t j = i + 1; j <= s2.size(); j++) {
        result.push_back(-1);
      }

      break;
    }
  }

  return result;
}