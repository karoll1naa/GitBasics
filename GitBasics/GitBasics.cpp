#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include "Html.h"
#include "Ansi.h"

using namespace std;

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
		cerr << " Sorry, the file cannot be opened for reading " << filePath << endl;
		exit(EXIT_FAILURE);
	}

	file << text;
	cout << "The HTML format text was written to " << filePath << endl;
}

int main(int args, char* argv[])
{
	if (args < 2) {
		cerr << "Usage: " << argv[0] << "<input_file_path>  [--format=<value>] [--out <output_file_path>]" << endl;
		return EXIT_FAILURE;
	}

	string inputFilePath = argv[1];
	string outputFilePath;
	string format;
	bool WriteFileFlag = false;
	for (int i = 2; i < args; ++i) {
		string arg = argv[i];
		if (arg == "--out") {
			if (i + 1 < args) {
				outputFilePath = argv[i + 1];
				WriteFileFlag = true;
			}
		}
		else if (arg.find("--format=") == 0) {
			format = arg.substr(9);
		}
	}
	string Markdown = ReadFile(inputFilePath);
	string FormattedText;
	if (format.empty()) {
		if (!outputFilePath.empty()) {
			FormattedText = MarkdowntoHTML(Markdown);
		}
		else {
			FormattedText = AnsiFormat(Markdown);
		}
	}
	else if (format == "ansi") {
		FormattedText = AnsiFormat(Markdown);
	}
	else if (format == "html") {
		FormattedText = MarkdowntoHTML(Markdown);
	}
	else {
		cerr << "Format error!" << endl;
		return EXIT_FAILURE;
	}
	if (WriteFileFlag) {
		WriteFile(FormattedText, outputFilePath);
	}
	else {
		cout << FormattedText << endl;
	}

	return EXIT_SUCCESS;
}

