#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> filenames;
int lines = 0;

string configstring = "┏━━━━━━━━                                                              ━━━━━━━━┓\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n                                                                                \n                                                                                \n                                                                                \n                             Fit me to your screen                              \n                                                                                \n                                                                                \n                                                                                \n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┃                                                                              ┃\n┗━━━━━━━━                                                              ━━━━━━━━┛\n";
string helpstring = "CLI ASCII PRESENTATION 1.1\n\nWrite paths to slide .txt relative to pres_conf.yml, each file on a seperate line\nrun in same directory as pres_config.yml\n\n-h\tdisplay help\n-f\tshow fitting slide\n";

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
				} else if(strncmp(argv[i], "-h", 2) == 0 || strncmp(argv[i], "-help", 5) == 0) {
					cout << helpstring << endl;
					exit(1);
				}
		}
	}
	startupRead();
	for(int i=0; i<lines; i++) {
		printFile(i);
	}
	system("clear");
}
