#include <iostream>
#include <string>

using namespace std;

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
    cout<<"Enter the message to Encrypt using ROT13\n";
    string input; 
    getline(cin,input);
    string cipher = rot13(input);

    cout<<"The Cipher is: "<<cipher;
    return 0;
}