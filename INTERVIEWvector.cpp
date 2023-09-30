#include<iostream>
#include<vector>
using namespace std;
int main()
{

    vector<int>ans;
	map<int,vector<int>>m;
	

	m[3].push_back(1);
	m[3].push_back(2);
     m[5].push_back(7);

	 for(auto i:m){
		for(j:i.second){
			ans.push_back(j);
		}

	 }


	
	return 0;
}