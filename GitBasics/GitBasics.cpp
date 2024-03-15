#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string MarkdowntoHTML(const string& markdown) {

	///...

		return markdown;
}

string ReadFile(const string& filePath) {
	ifstream file(filePath);
	if (!file.is_open()) {
		cerr << " Sorry, the file cannot be opened :( " << filePath << endl;
		exit(EXIT_FAILURE);
	}
	stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

void WriteFile(const string& text, const string& filePath) {
	ofstream file(filePath);
	if (!file.is_open()) {
		cerr << " Sorry, the file cannot be opened for reading " << filePath <<  endl;
		exit(EXIT_FAILURE);
	}

	file << text;
	cout<< "The HTML format text was written to " << filePath <<endl;
}

int main(int args, char* argv[])
{
	if (args < 2) {
		cerr<<"Usage: "<<argv[0]<< "<input_file_path>[--out <output_file_path>]" << endl;
		return EXIT_FAILURE;
	}

	string inputFilePath = argv[1]; 
	string outputFilePath;
	bool WriteFileFlag = false; 
	if (args == 4 && string(argv[2]) == "--out") {
		outputFilePath = argv[3];
		WriteFileFlag = true;
	}

	string Markdown = ReadFile(inputFilePath);
	string HTML = MarkdowntoHTML(Markdown);

	if (WriteFileFlag) {
		WriteFile(HTML, outputFilePath);
	}
	else {
		cout <<HTML<<endl;
	}

	return EXIT_SUCCESS;
}

