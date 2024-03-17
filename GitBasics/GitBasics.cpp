#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include<locale>

using namespace std;

string MarkdowntoHTML(const string& markdown) {
	stringstream HTMLstream;
	stringstream MarkdownStream(markdown);
	string line;
	while (getline(MarkdownStream, line)) {
		regex boldRegex("\\*\\*(.*?)\\*\\*");
		line = regex_replace(line, boldRegex, "<b>$1</b>");

		regex italicRegex("\\_(.*?)\\_");
		line = regex_replace(line, italicRegex, "<i>$1</i>");

		regex codeBlockRegex("```([^`]+)```");
		line = regex_replace(line, codeBlockRegex, "<pre>$1</pre>");

		regex codeRegex("`([^`]+)`");
		line = regex_replace(line, codeRegex, "<tt>$1</tt>");

		if (line.find("<") == string::npos && line.find(">") == string::npos) {
			HTMLstream << "<p>" << line << "</p>";
		}
		else {
			HTMLstream << line;
		}
	}
	return HTMLstream.str();
}

string ReadFile(const string& filePath) {
	wifstream file(filePath);
	if (!file.is_open()) {
		cerr << " Sorry, the file cannot be opened :( " << filePath << endl;
		exit(EXIT_FAILURE);
	}
	file.imbue(locale(file.getloc(), new codecvt_utf8<wchar_t>));

	wstringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

void WriteFile(const string& text, const string& filePath) {
	wofstream file(filePath);
	if (!file.is_open()) {
		cerr << " Sorry, the file cannot be opened for reading " << filePath << endl;
		exit(EXIT_FAILURE);
	}
	file.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	file << text;
	cout << "The HTML format text was written to " << filePath << endl;
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

