#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;

double get_distance(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

double calculate_time(double k,double ei){
    return 2.0*k+2.0*(ei/pow(2,k));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n)) return 0;

    vector<pair<double,double>> point(n);
    for(int i=0;i<n;i++){
        cin>>point[i].first>>point[i].second;
    }

    double total_time=0;
    for(int i=1;i<n;i++){
        double ei=get_distance(point[i-1].first,point[i-1].second,point[i].first,point[i].second);
        double low=0.0;
        double high=100.0;
        for(int iter=0;iter<100;iter++){
            double pt1=low+(high-low)/3.0;
            double pt2=high-(high-low)/3.0;
            if(calculate_time(pt1,ei)<calculate_time(pt2,ei)){
                high=pt2;
            }else{
                low=pt1;
            }
        }
        total_time+=calculate_time(low,ei);
    }
    cout<<fixed<<setprecision<<total_time<<endl;
    return 0;
}
