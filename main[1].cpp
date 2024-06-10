#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string password;
    cout << "Enter your password: ";
    cin >> password;

    int score = 0;
    if (password.length() >= 12) {
        score += 5;
    } else if (password.length() >= 8) {
        score += 3;
    } else {
        score += 1;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    for (char c : password) {
        if (isupper(c)) {
            hasUpper = true;
        } else if (islower(c)) {
            hasLower = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        } else if (!isalnum(c)) {
            hasSpecial = true;
        }
    }

    if (hasUpper) {
        score += 2;
    }
    if (hasLower) {
        score += 2;
    }
    if (hasDigit) {
        score += 2;
    }
    if (hasSpecial) {
        score += 3;
    }

    cout << "Password strength score: " << score << endl;

    if (score >= 10) {
        cout << "Strong password!" << endl;
    } else if (score >= 5) {
        cout << "Medium strength password." << endl;
    } else {
        cout << "Weak password. Please choose a stronger one." << endl;
    }

    return 0;
}