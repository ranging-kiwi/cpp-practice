#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<string> words;
map<string,int> cnt;

string standard(const string &s){
    string ans=s;
    for(int i=0;i<s.length();i++){
        ans[i]=tolower(ans[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s;
    while(cin>>s){
        if(s[0]=='#') break;
        words.push_back(s);
        string r=standard(s);
        if(!cnt.count(r)) cnt[r]=0;
        cnt[r]++;
    }
    vector<string> ans;
    for(int i=0;i<words.size();i++){
        if(cnt[standard(words[i])]==1) ans.push_back(words[i]);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<'\n';
    return 0;
}
