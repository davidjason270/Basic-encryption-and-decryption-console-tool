#include <iostream>
#include <string>
using namespace std;

string reverse_text(string text){
    string cipher = "";
    int size = text.size();

    for(int i = (size-1); i >= 0; i--){
        cipher += text[i];
    }
    return cipher;
}

string reverse(string text){
    string cipher = "";
    int size = text.size();

    for(int i = 0; i<size; i++){
        cipher += text[size - (i+1)];
    }
    return cipher;
}

int main()
{
    cout<<"Enter text to encrpt using reverse cipher";
    string text; cin>>text;
    cout<<reverse_text(text);
    return 0;
}