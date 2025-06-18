#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key)
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

string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);  // Reverse the shift
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
    string text;
    cout<<"Enter Text to be Encrypted / Decrypted : ";
    getline(cin, text);

    string ciphertext = atbash(text);

    cout<<"The cipher text is : "<<ciphertext<<endl;
    return 0;
}