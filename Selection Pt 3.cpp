// Insert libraries 
#include <iostream>
#include <fstream>
#include <string>

// Open and read File1 and File2 
void mergeFiles(const std::string& inputFile1, const std::string& inputFile2, const std::string& outputFile) {
	std::ifstream file1(inputFile1);
	std::ifstream file2(inputFile2);
	std::ofstream output(outputFile);

	std::string name1, name2, grade1, grade2;
	// Determine first name as well as grade from each file 
	file1 >> name1 >> grade1;
	file2 >> name2 >> grade2; 

    // Create while loop to merge files and get names in alphabetical order 
	while (!file1.eof() || !file2.eof()) {
		if (name1 < name2 || file2.eof()) {
			output << name1 << '\t' << grade1 << '\n';
			file1 >> name1 >> grade1;
		} else { 
			output << name2 << '\t' << grade2 << '\n';
			file2 >> name2 >> grade2;
		}
	}
	// Close files 
	file1.close();
	file2.close(); 
	output.close();
}
// Call main function and merge files 
int main() {
	std::string inputFile1 = "file1.txt";
	std::string inputFile2 = "file2.txt";
	std::string outputFile = "output.txt";

	mergeFiles(inputFile1, inputFile2, outputFile); 
	
	return 0; 

}