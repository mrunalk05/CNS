#include <iostream>
#include <vector>

using namespace std;

string encryptRailFence(const string& plaintext, int rails) {
    vector<string> railMatrix(rails);
    int currentRail = 0;
    int direction = 1;

    for (char ch : plaintext) {
        railMatrix[currentRail] += ch;

        if (currentRail == 0) {
            direction = 1;
        } else if (currentRail == rails - 1) {
            direction = -1;
        }

        currentRail += direction;
    }

    string ciphertext;
    for (const string& rail : railMatrix) {
        ciphertext += rail;
    }

    return ciphertext;
}

string decryptRailFence(const string& ciphertext, int rails) {
    vector<string> railMatrix(rails);

    int len = ciphertext.length();
    int currentRail = 0;
    int direction = 1;

    for (int i = 0; i < len; i++) {
        railMatrix[currentRail] += " ";
        currentRail += direction;

        if (currentRail == 0) {
            direction = 1;
        } else if (currentRail == rails - 1) {
            direction = -1;
        }
    }

    int charIndex = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < railMatrix[i].length(); j++) {
            railMatrix[i][j] = ciphertext[charIndex++];
        }
    }

    currentRail = 0;
    direction = 1;
    string plaintext;
    for (int i = 0; i < len; i++) {
        plaintext += railMatrix[currentRail][0];
        railMatrix[currentRail] = railMatrix[currentRail].substr(1);
        currentRail += direction;

        if (currentRail == 0) {
            direction = 1;
        } else if (currentRail == rails - 1) {
            direction = -1;
        }
    }

    return plaintext;
}

int main() {
    int choice;
    string text;
    int rails;

    cout << "Rail Fence Cipher Program" << endl;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the plaintext: ";
                cin.ignore();
                getline(cin, text);
                cout << "Enter the number of rails: ";
                cin >> rails;
                cout << "Encrypted message: " << encryptRailFence(text, rails) << endl;
                break;
            case 2:
                cout << "Enter the ciphertext: ";
                cin.ignore();
                getline(cin, text);
                cout << "Enter the number of rails: ";
                cin >> rails;
                cout << "Decrypted message: " << decryptRailFence(text, rails) << endl;
                break;
            case 3:
                // cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    } while (choice != 3);

    return 0;
}
