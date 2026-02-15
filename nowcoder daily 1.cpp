#include<iostream>
#include<numeric>
using namespace std;
long long gcd(long long a,long long b){
    while(a>0){
        long long temp=a;
        a=b%a;
        b=temp;
    }
    return b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n; cin>>n;
        long long a=n/2, b=n-a;
        while(gcd(a,b)!=1) a--, b++;
        cout<<a<<' '<<b<<'\n';
    }
    return 0;
}


#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        long long a,b;
        cin>>n;
        if(n%2==1){
            a=(n-1)/2;
            b=(n+1)/2;
        }else{
            long long k=n/2;
            if(k%2==0){
                a=k-1;
                b=k+1;
            }else{
                if(n==2){
                    a=1;b=1;
                }else{
                    a=k-2;
                    b=k+2;
                }
            }
        }
        cout<<a<<' '<<b<<'\n';
    }
    return 0;
}

#include<iostream>
using namespace std;
