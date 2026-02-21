#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m;
    cin>>m;
    vector<int> array(m);
    for(int i=0;i<m;i++){
        cin>>array[i];
    }
    int n;
    cin>>n;
    if(n<=0){
        cout<<"true";
        return 0;
    }
    int count=0;
    for(int i=0;i<m;i++){
        if(array[i]==0){
            bool left=(i==0||array[i-1]==0);
            bool right=(i==m-1||array[i+1]==0);
            if(left&&right){
                array[i]=1;
                count++;
                if(count>=n){
                    cout<<"true";
                    return 0;
                }
            }
        }
    }
    if(count>=n) cout<<"true";
    else cout<<"false";
    return 0;
}
