// Write a tail recursive function to reverse a string

#include <string>

using namespace std;

string reverse(string str) {
    if (str.length() <= 1) {
        return str;
    }

    return str.back() + reverse(str.substr(0, str.length() - 1));
}

/*
reverse("cat")
= "t" + reverse("ca")
= "t" + "a" + reverse("c")
= "t" + "a" + "c"
= "tac"
*/