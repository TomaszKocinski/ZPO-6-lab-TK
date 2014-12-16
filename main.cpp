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
	string dna_temp,name_temp;
	map<string,list<string>> mapa;
	while(getline(file, name_temp) && getline(file, dna_temp)){
		list<string> list_temp=mapa[dna_temp];
		list_temp.push_back(name_temp);
		mapa[dna_temp]=list_temp;
	}
	multimap<int,list<string>> final;
	for(map<string,list<string>>::iterator w=mapa.begin();w!=mapa.end();w++){
		pair<int,list<string>> temp;
		temp.first=(*w).second.size();
		temp.second=(*w).second;
		final.insert(temp);
	}
	mapa.clear();
	ofstream out("exx.txt");
	for(multimap<int,list<string>>::iterator ite=final.end();ite!=final.begin();ite--){
		if(ite==final.end()) ite--;
		out<<(*ite).first<<'\n';
		for(list<string>::iterator a=(*ite).second.begin();a!=(*ite).second.end();a++)
			out<<*a<<'\n';
		out<<'\n';
	}
}