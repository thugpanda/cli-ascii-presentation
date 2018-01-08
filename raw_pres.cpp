#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> filenames;
int lines = 0;

string configstring = "┏━━━━━━━━                                                              ━━━━━━━━┓\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n                                                                                \n                                                                                \n                                                                                \n                             Fit me to your screen                              \n                                                                                \n                                                                                \n                                                                                \n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┗━━━━━━━━                                                              ━━━━━━━━┛\n";

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

int main(int argc, char *argv[]) {
	if(argc > 1) {
		for(int i=1; i<argc; i++) {
				if(strncmp(argv[i], "-f", 2) == 0) {
					system("clear");
					cout << configstring << endl;
					cin.ignore();
				}
		}
	}
	startupRead();
	for(int i=0; i<lines; i++) {
		printFile(i);
	}
	system("clear");
}
