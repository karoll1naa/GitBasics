#pragma once
#include <string>
#include <sstream>
#include <regex>

using namespace std;

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