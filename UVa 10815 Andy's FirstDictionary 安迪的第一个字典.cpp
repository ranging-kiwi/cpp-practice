#include<iostream>
#include<string>
#include<sstream>
#include<set>
using namespace std;

set<string> dictionary;

int main(){
    string s,buf;
    while(cin>>s){
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        stringstream ss(s);
        while(ss>>buf) dictionary.insert(buf);
    }
    for(set<string>::iterator it=dictionary.begin();it!=dictionary.end();it++){
        cout<<*it<<'\n';
    }
    return 0;
}
