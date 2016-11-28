#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    freopen("input.txt","r",stdin);
        
    string str,str2;
    map<int,int>a;

    getline(cin,str); 

    int n = atoi(str.c_str());
    int x;
    int cnt = 0;

    while(getline(cin,str)){
        if(str == "HELP") break;
        getline(cin,str2);
        stringstream ss;
        ss << str;

        while(ss >> x){
            if(str2 == "YES"){
                a[x]++;
                cnt = max(cnt,a[x]);
            }else{
                a[x] = -1000000;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        if(a[i] == cnt){
            cout << i << " ";
        }
    }

    return 0;
}