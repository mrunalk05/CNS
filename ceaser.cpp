/*
    Caesar Cipher Encryption and Decryption
*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string encrypt(string text, int s)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
            continue;
        else if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else
            result += toupper(char(int(text[i] + s - 97) % 26 + 97));
    }
    return result;
}

string decrypt(string cipher, int s)
{
    string result = "";
    for (int i = 0; i < cipher.size(); i++)
    {
        if (cipher[i] == ' ' || cipher[i] == '\n')
            continue;
        else if (isupper(cipher[i]))
            result += char((int(cipher[i] - s - 65) + 26) % 26 + 65);
        else
            result += char((int(cipher[i] - s - 97) + 26) % 26 + 97);
    }
    return result;
}

int main()
{
    int choice;
    int datachoice;
    string sample;
    int shift;
    while (1)
    {
        cout << "Caesar Cipher\n 1. Encryption \n 2. Decryption\n 3. Exit\nEnter Choice: ";
        cin >> choice;
        if (choice > 2 || choice <= 0)
            break;
        switch (choice)
        {
        case 1:

            cout << "Enter data to be Encrypted:\n";
            cin.ignore();
            getline(cin, sample);
            cout << "Enter the shift value: ";
            cin >> shift;
            cout << "Encrypted String:\n";
            cout << encrypt(sample, shift) << endl;
            ;

            break;
        case 2:
            cout << "Enter data to be Decrypted:\n";
            cin.ignore();
            getline(cin, sample);
            cout << "Enter the shift value: ";
            cin >> shift;
            cout << "Decrypted String:\n";
            cout << decrypt(sample, shift) << endl;
            ;
            break;
        }
    }
    return 0;
}
