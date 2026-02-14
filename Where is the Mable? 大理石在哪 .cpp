#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10000;
int main(){
    int n,q,x,arr[maxn],kase=1;
    while(scanf("%d%d",&n,&q)==2&&n){
        printf("CASE #%d:\n",kase++);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        while(q--){
            scanf("%d",&x);
            int p=lower_bound(arr,arr+n,x)-arr;
            if(arr[p]==x){
                printf("%d found at %d\n",x,p+1);
            }else{
                printf("%d not found.\n",x);
            }
        }
    }
    return 0;
}
