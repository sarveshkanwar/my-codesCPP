#include<iostream>
#include <vector>
using namespace std;
int main()
{

    vector<int>v(4);

    v[3]=3;
    v[2]=2;
    v[1]=1;
    v[0]=0;

    for(auto i:v){
        cout<<i<<endl;
    }
    return 0;
}