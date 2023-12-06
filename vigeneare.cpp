#include <iostream>
#include <string>
using namespace std;

class Vigenere
{
public:
    string key;

    void createKey(string k)
    {
        key.clear();
        for (int i = 0; i < k.size(); ++i)
        {
            if (isupper(k[i]))
                key += k[i];
            else if (islower(k[i]))
                key += toupper(k[i]);
        }
    }

    string encrypt(string text)
    {
        string output;
        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];
            if (c == ' ')
                continue;
            if (islower(c))
                c = toupper(c);
            else if (!isupper(c))
                continue;
            output += ((c + key[j] - 2 * 'A') % 26) + 'A';
            j = (j + 1) % key.length();
        }
        return output;
    }

    string decrypt(string text)
    {
        string output;
        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];
            if (islower(c))
                c = toupper(c);
            else if (!isupper(c))
                continue;
            output += ((c - key[j] + 26) % 26) + 'A';
            j = (j + 1) % key.length();
        }
        return output;
    }
};

int main()
{
    Vigenere vigenere;
    int choice;
    string text, key;

    while (true)
    {
        cout << "Vigenere Cipher" << endl;
        cout << "1. Encryption" << endl;
        cout << "2. Decryption" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice < 1 || choice > 3)
            break;

        switch (choice)
        {
        case 1:
            cout << "Enter data to be Encrypted:" << endl;
            cin.ignore();
            getline(cin, text);
            cout << "Enter the key: ";
            getline(cin, key);
            vigenere.createKey(key);
            cout << "Encrypted String:" << endl;
            cout << vigenere.encrypt(text) << endl;
            break;

        case 2:
            cout << "Enter data to be Decrypted:" << endl;
            cin.ignore();
            getline(cin, text);
            cout << "Enter the key: ";
            getline(cin, key);
            vigenere.createKey(key);
            cout << "Decrypted String:" << endl;
            cout << vigenere.decrypt(text) << endl;
            break;
        }
    }

    return 0;
}
