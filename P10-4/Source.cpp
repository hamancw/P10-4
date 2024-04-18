#include <iostream>
using namespace std;

bool isCardValid(int digits[], int size) {
    int sum = 0;
    bool doubleDigit = false;

    for (int i = size - 1; i >= 0; i--) {
        int digit = digits[i];

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
    char input[9];

    while (true) {
        cout << "Enter 8-digit credit card # or Q to quit: ";
        cin.getline(input, 9);

        if (input[0] == 'Q' || input[0] == 'q')
            break;

        int digits[8];
        bool valid = true;

        for (int i = 0; i < 8; i++) {
            if (isdigit(input[i]))
                digits[i] = input[i] - '0';
            else {
                cout << "Invalid input. Please enter 8 digits.\n";
                valid = false;
                break;
            }
        }

        if (valid) {
            bool result = isCardValid(digits, 8);
            if (result)
                cout << "Card is valid.\n";
            else
                cout << "Card is not valid.\n";
        }
    }
}
