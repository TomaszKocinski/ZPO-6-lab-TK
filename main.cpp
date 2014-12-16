#include<fstream>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<iterator>
#include<algorithm>
using namespace std;
int main(int argc, char* argv[]) {
	ifstream file("genyEColi.txt");
	string line,line2;
	vector<pair<string,string>> wekt;
	while(getline(file, line) && getline(file, line2)){
		pair<string,string> sad;
		sad.first=line2;
		sad.second=line;
		wekt.push_back(sad);
	}
	map<string,list<string>> mapa;
	for(vector<pair<string,string>>::iterator w=wekt.begin();w!=wekt.end();w++){
		list<string> list_temp;
		string str_temp;
		list_temp=mapa[(*w).first];
		str_temp=(*w).second;
		list_temp.push_back(str_temp);
		mapa[(*w).first]=list_temp;
	}
	multimap<int,list<string>> final;
	for(map<string,list<string>>::iterator w=mapa.begin();w!=mapa.end();w++){
		pair<int,list<string>> temp;
		temp.first=(*w).second.size();
		temp.second=(*w).second;
		final.insert(temp);
	}
	ofstream out("exx.txt");
	for(multimap<int,list<string>>::iterator ite=final.end();ite!=final.begin();ite--){
		if(ite==final.end()) ite--;
		out<<(*ite).first<<'\n';
		for(list<string>::iterator a=(*ite).second.begin();a!=(*ite).second.end();a++)
			out<<*a<<'\n';
		out<<'\n';
	}
}