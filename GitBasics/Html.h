#pragma once
#include <string>
#include <sstream>
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