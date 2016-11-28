#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

using namespace std;


vector<set<long long> > a;
set<long long> no;

int main(){

    freopen("input.txt","r",stdin);
        
    string str,str2;
    int x;
    
    getline(cin,str); 

    int n = atoi(str.c_str());

    int cnt = 0;

    while(getline(cin,str)){
        if(str == "HELP") break;
        getline(cin,str2);
        set<long long> numbers;
        stringstream ss;
        ss << str;

        while(ss >> x){
            if(str2 == "YES"){
            	numbers.insert(x);
            }else{
            	no.insert(x);
            }
        }

        if(str2 == "YES"){
        	a.push_back(numbers);
        }
    }

    set<long long> yes,res;

    if(a.size() > 0){
    	set<long long> t;
	    yes.insert(a[0].begin(),a[0].end());
    	for(int i = 1; i < a.size(); ++i){
    		
    		t.clear();
    		t.insert(yes.begin(),yes.end());
    		yes.clear();

    		set_intersection(a[i].begin(),a[i].end(),
		             t.begin(),t.end(),
		             inserter(yes,yes.begin()));

    	}
	}

	if(!yes.empty()){
	   	set_difference(yes.begin(),yes.end(),
			             no.begin(),no.end(),
			             inserter(res,res.begin()));

		for(set <long long>:: iterator it = res.begin(); it != res.end(); ++it ){
	    	cout << *it  << " ";
	    }

	}else{
		for(long long i = 1; i <= n; ++i){
			if(no.find(i) == no.end()){
				cout << i << " ";
			}
		}
	}
	
	cout << endl;


    return 0;
}