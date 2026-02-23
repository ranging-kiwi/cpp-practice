#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    int arr[n];
    long long sum=0;
    long long count=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left=0;
    for(int right=0;right<n;right++){
        sum+=arr[right];
        while(sum>=k){
            count+=(n-right);
            sum-=arr[left];
            left++;
        }
    }
    cout<<count;
    return 0;
}
