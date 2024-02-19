// This program reads data from two test files "Names1.txt" and "Names2.txt" it then merges the data from both files based on the alphebetical order of the names, writing the merged output to a new file and informs the user once the merging is complete
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream file1("Names1.txt");
	ifstream file2("Names2.txt");
	ofstream outputFile("output.txt");
	
	string line1, line2;

	getline(file1, line1);
	getline(file2, line2);

	while (!file1.eof() && !file2.eof()) {
		string key1 = line1.substr(0, line1.find_first_of(','));
		string key2 = line2.substr(0, line2.find_first_of(','));

		if (key1 < key2) {
			outputFile << line1 << endl;
			getline(file1, line1);
		}
		else {
			outputFile << line2 << endl;
			getline(file2, line2);

			}
		
	}

	while (!file1.eof()) {
		outputFile << line1 << endl;
		getline(file1, line1);
	}

	while (!file2.eof()) {
		outputFile << line2 << endl;
		getline(file2, line2);

	}

	file1.close();
	file2.close();
	outputFile.close();

	cout << "Merging Complete" << endl;

	return 0;


}

