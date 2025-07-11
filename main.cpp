#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string reverse_text(string text){
    string cipher = "";
    int size = text.size();

    for(int i = (size-1); i >= 0; i--){
        cipher += text[i];
    }
    return cipher;
}

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

string rot13(string text)
{
    string result = "";
    for(char c : text){

        if(isalpha(c)){
            char base = 'a';
            result += (c - base + 13) % 26 + base;
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
            cout<<"Select one of the options:\n";
            cout<<"1. Encryption\n";
            cout<<"2. Decryption\n";
            cout<<"3. Back";

            int choice; cin>>choice;
            if(choice == 1){
                cout<<"Encrypt Message\n";
                cout<<"Enter the key:";
                int key; cin>>key;
                cin.ignore();

                cout<<"Enter a message:";
                string message; 
                getline(cin, message);

                string cipher = caeser_cipher(message, key);
                cout<<"The Cipher text is: "<< cipher<<endl;
            }else if(choice == 2){
                cout<<"Decrypt Message\n";
                cout<<"Enter the key:";
                int key; cin>>key;
                cin.ignore();

                cout<<"Enter a message:";
                string message; 
                getline(cin, message);
                string text = decrypt(message, key);

                cout<<"The text is: "<< text<<endl;
            }else if(choice == 3){
               
            }




          
            system("pause");


        }else if(choice == 'b' || choice == 'B'){
             system("cls");
             cout<<"\n----------------------------\n\tAtBash Cipher\n----------------------------------------\n";
            
            //1. input variable
            string text;
            //2. ask the user
            cout<<"Enter text to Encrypt / Decrypt\n";
            //3. clear the input buffer and allow the user to enter
            cin.ignore();
            getline(cin, text);
            //encrypt / decrpt using atbash function 
            string cipher = atbash(text);
            //display result
            cout<<"\n The output is :"<<cipher<<endl;
            system("pause");
        }else if(choice == 'c' || choice == 'C'){
             system("cls");
            cout<<"\n\nReverse Cipher\n\n";
            cout<<"Enter text to encrpt using reverse cipher";
            cin.ignore();
            string text; getline(cin,text);
            cout<<reverse_text(text);
            system("pause");

        }else if(choice == 'd' || choice == 'D'){
            system("cls");
            cout<<"\n\nROT13 Cipher\n\n";
            cout<<"Enter the message to Encrypt using ROT13\n";
            string input; 
            cin.ignore();
            getline(cin,input);
            string cipher = rot13(input);

            cout<<"The Cipher is: "<<cipher<<endl;
            system("pause");

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
