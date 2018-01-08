#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> filenames;
int lines = 0;

void startupRead() {
	string line;
	ifstream file("pres_conf.yml");
	if(file == NULL) {
		cout << "Please provide pres_conf.yml file in directory." << endl;
		exit(0);
	}
	if(file.is_open()) {
		while(getline(file,line)) {
			filenames.push_back(line);
			lines++;
		}
		file.close();
	}
}

void printFile(int id) {
	string line;
	ifstream myfile(filenames.at(id));
	if(myfile.is_open()) {
		system("clear");
		while(getline(myfile,line)) {
			cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Unable to open file " << filenames[id];

	cin.ignore();
}

int main() {
	startupRead();
	for(int i=0; i<lines; i++) {
		printFile(i);
	}
	system("clear");
}
