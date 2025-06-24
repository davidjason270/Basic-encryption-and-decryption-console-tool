#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string caeser_cipher(string text, int key)
{
    string result = "";

    for(char c : text){
        if(isalpha(c)){
            char base = 'a';
            c = (c - base + key) % 26 + base;
            result += c; 
        }else{
           result += c;  
        }
    }

    return result;
}

string decrypt(string text, int key) {
    return caeser_cipher(text, 26 - key);  // Reverse the key
}

string atbash(string text)
{
    string result = "";
    for(char c : text){

        if(isalpha(c)){
            char first = 'a';
            char last = 'z';
            result += last - (c-first);
        }else{
            result += c;
        }
    }
    return result;
}

int main()
{
    while(true){
        cout << "\n---------------------------------\n";
        cout << "Basic Encryption / Decrytion Tool\n";
        cout << "---------------------------------\n";
        cout << "Encrypt or Decrypt your message using\n";
        cout << "a. Caeser Cipher\n";
        cout << "b. Atbash Cipher\n";
        cout << "c. Reverse Cipher\n";
        cout << "d. Rot13 Cipher\n";
        cout << "e. Exit\n";

        char choice;
        cout<<"Enter an Option from a - d:";
        cin>>choice;

        if(choice == 'a' || choice == 'A'){
             system("cls");
            cout<<"\n\nCaeser Cipher\n\n";

            cout<<"Enter the key:";
            int key; cin>>key;
            cin.clear(); cin.ignore();

            cout<<"Enter a message:";
            string message; 
            getline(cin, message);

            string cipher = caeser_cipher(message, key);

            cout<<"The Cipher text is: "<< cipher<<endl;
            system("pause");


        }else if(choice == 'b' || choice == 'B'){
             system("cls");
            cout<<"\n\nAtBash Cipher\n\n";
        }else if(choice == 'c' || choice == 'C'){
             system("cls");
            cout<<"\n\nReverse Cipher\n\n";
        }else if(choice == 'd' || choice == 'D'){
             system("cls");
            cout<<"\n\nROT13 Cipher\n\n";
        }else if(choice == 'e' || choice == 'E'){
             system("cls");
            cout<<"\n\nGOOD BYE!\n\n";
            exit(0);
        }else{
            cout<<"\n\nInvalid input\n\n";
        }
    }
    return 0;
}
