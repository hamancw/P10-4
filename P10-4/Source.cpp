#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isNumeric(string s) {
    for (char c : s) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isCorrectLength(string s) {
    return (s.length() == 16);
}

bool isCardValid(string cardNumber) {
    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}

int main() {
    string input;

    while (true) {
        cout << "Enter 16-digit credit card # or Q to quit: ";
        getline(cin, input);

        if (input == "Q" || input == "q")
            break;

        if (!isNumeric(input)) {
            cout << "Error - card number must contain only digits.\n";
            continue;
        }

        if (!isCorrectLength(input)) {
            cout << "Error - card number must contain 16 digits.\n";
            continue;
        }

        bool result = isCardValid(input);

        if (result)
            cout << "Card is valid.\n";
        else
            cout << "Card is not valid.\n";
    }
}
