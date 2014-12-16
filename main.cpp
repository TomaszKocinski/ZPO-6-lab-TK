#include<fstream>	//ifstream ofstream
#include<iostream>	//cout
#include<string>	//string
#include<list>		//list
#include<map>		//map,multimap
#include<iterator>	//iteratory dla map i multimap
using namespace std;
int main(int argc, char* argv[]) {
	ifstream file("genyEColi.txt");
	string dna_temp,name_temp;
	map<string,list<string>> mapa;
	cout<<"wstawianie do map\n";
	while(getline(file, name_temp) && getline(file, dna_temp)){
		list<string> list_temp=mapa[dna_temp];
		list_temp.push_back(name_temp);
		mapa[dna_temp]=list_temp;
	}
	file.close();
	cout<<"wstawianie do multimap\n";
	multimap<int,list<string>> final;
	for(map<string,list<string>>::iterator w=mapa.begin();w!=mapa.end();w++){
		pair<int,list<string>> temp;
		temp.first=(*w).second.size();
		temp.second=(*w).second;
		final.insert(temp);
	}
	cout<<"wypisywanie do pliku\n";
	mapa.clear();
	ofstream out("exx.txt");
	for(multimap<int,list<string>>::reverse_iterator ite=final.rbegin();ite!=final.rend();ite++){
		out<<(*ite).first<<'\n';
		for(list<string>::iterator a=(*ite).second.begin();a!=(*ite).second.end();a++)
			out<<*a<<'\n';
		out<<'\n';
	}
	out.close();
}