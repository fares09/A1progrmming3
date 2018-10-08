#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool Anagram(string , string);

int main()
{
    // works well.
    string str1, str2;
    cout<<"Enter first string:"<<endl;
    getline(cin,str1);

    cout<<"Enter second string:"<<endl;

    getline(cin,str2);



    if(Anagram(str1,str2))
        cout<<"they are anagram"<<endl;
    else
        cout << "they are not anagram"<<endl;

    return 0;
}

bool Anagram(string str1 , string str2)
{
    string s1="" , s2="";
    for(int i=0; i<str1.length(); i++){
        if(str1[i] != ' ' && str1[i] != ',' && str1[i] != '?' && str1[i] != '.' && str1[i] !='"' && str1[i] != ';' && str1[i] !=':')
            s1+=tolower(str1[i]);
    }


    for(int i=0; i<str2.length(); i++){
        if(str2[i] != ' ' && str2[i] != ',' && str1[i] != '?' && str1[i] != '.' && str1[i] !='"' && str1[i] != ';' && str1[i] !=':')
            s2+=tolower(str2[i]);
    }

    for(int i=0; i<s1.length(); i++){
        bool found = false;
        for(int j=0; j<s2.length(); j++){
            if(s1[i] == s2[j]){
                found = true;
                //cout << s1[i] << endl;
                s2[j] = '?'; // just a replace to avoid double count.
                break;

            }
        }
            if(found == false)
                return false;
    }


    return true;
}

