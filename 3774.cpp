#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<string,string> a;
map<string,int> cnt;
set<string> names;
map<string, vector<string> > b;

void f(string parent_name){
	vector<string> children = b[parent_name];
	cnt[parent_name] = children.size();

	for(int i = 0; i < children.size(); ++i){
		f(children[i]);
		cnt[parent_name] += cnt[children[i]];
	}

}



int main(){

	freopen("input.txt","r",stdin);

	int n;
	cin >> n;

	string child_name, parent_name;
	

	for(int i = 0 ; i < n - 1 ; ++i){
		cin >> child_name >> parent_name;

		a[child_name] = parent_name;
		b[parent_name].push_back(child_name);

		names.insert(child_name);
		names.insert(parent_name);
	}


	for(set<string>::iterator it = names.begin();it!=names.end();++it){
		if(a[*it] == "") {
			f(*it);
			break;
 		}
	}


	for(set<string>::iterator it = names.begin();it!=names.end();++it){
		cout << *it << " " << cnt[*it] << endl;
	}

 	return 0;
}


