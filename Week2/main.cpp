#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "Finder.h"

using namespace std;

int main() {
    Finder finder;

    string s1 = "ababcabcdef";
    string s2 = "abcd";

    auto start = chrono::high_resolution_clock::now(); // Represents the current time point

    vector<int> result = finder.findSubstrings(s1, s2);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    // Display the result vector
    cout << "Result: {";

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        // Add a comma unless this is the last element
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }

    cout << "}" << endl;

    // Display findSubstrings duration
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}