#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

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

string AnsiFormat(const string& markdown) {
	stringstream ANSIstream;
	stringstream MarkdownStream(markdown);
	string line;
	while (getline(MarkdownStream, line)) {
		regex boldRegex("\\*\\*(.*?)\\*\\*");
		line = regex_replace(line, boldRegex, "\033[1m$1\033[0m");

		regex italicRegex("\\_(.*?)\\_");
		line = regex_replace(line, italicRegex, "\033[3m$1\033[0m");

		regex codeBlockRegex("```([^`]+)```");
		line = regex_replace(line, codeBlockRegex, "\033[47;30m$1\033[0m"); //Білий текст на чорному фоні

		regex codeRegex("`([^`]+)`");
		line = regex_replace(line, codeRegex, "\033[1;37;40m$1\033[0m"); //Жирний білий текст на чорному фоні

		ANSIstream << line;
	}
	return ANSIstream.str();
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
	if (format == "ansi" || format.empty()){
		FormattedText = AnsiFormat(Markdown);
	}
	else if (format == "html" || !outputFilePath.empty()) {
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

