#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> filenames;
int lines = 0;
int width = 0;
int height = 0;

vector<string> configstring;
string helpstring = "CLI ASCII PRESENTATION 1.1a\n\nWrite paths to slide .txt relative to pres_conf.yml, each file on a seperate line\nrun in same directory as pres_config.yml\n\n-h\t\t\tDisplay help\n-f width height\t\tCreates fitting slide with size w*h for fitting to screen\n";

void generateFittingScreen() {
	for(int i=0; i<height; i++) {
		configstring.push_back("");
	}
	configstring.at(0).append(".");
	configstring.back().append(".");
	for(int i=0; i<width-2;i++) {
		configstring.at(0).append(" ");
		configstring.back().append(" ");
	}
	configstring.at(0).append(".");
	configstring.back().append(".");
	for(int i=1;i<height-1;i++) {
		for(int j=0;j<width;j++) {
			configstring.at(i).append(" ");
		}
	}
}

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
					width = stoi(argv[i+1]);
					height = stoi(argv[i+2]);
					generateFittingScreen();
					system("clear");
					for(int i=0; i<configstring.size();i++) {
						cout << configstring.at(i) << '\n';
					}
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
