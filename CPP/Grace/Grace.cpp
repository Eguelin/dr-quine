#include <fstream>
#include <iostream>
#include <algorithm>

#define CODE "#include <fstream>%1$c#include <iostream>%1$c#include <algorithm>%1$c%1$c#define CODE %2$c%4$s%2$c%1$c#define FILE_NAME %2$cGrace_kid.cpp%2$c%1$c#define MAIN(code, file_name) int main() {	std::string	str = code;	std::string	format_str(str);	std::string::size_type	pos = format_str.find(%2$c%3$c1$c%2$c);	std::ofstream	file(file_name);	while (pos != std::string::npos) {		format_str.replace(pos, 4, 1, 10);		pos = format_str.find(%2$c%3$c1$c%2$c, pos + 1);	}	pos = format_str.find(%2$c%3$c2$c%2$c);	while (pos != std::string::npos) {		format_str.replace(pos, 4, 1, 34);		pos = format_str.find(%2$c%3$c2$c%2$c, pos + 1);	}	pos = format_str.find(%2$c%3$c3$c%2$c);	while (pos != std::string::npos) {		format_str.replace(pos, 4, 1, 37);		pos = format_str.find(%2$c%3$c3$c%2$c, pos + 1);	}	pos = format_str.find(%2$c%3$c4$s%2$c);	if (pos != std::string::npos) {		format_str.replace(pos, 4, str);	}	if (!file.is_open()) {return (1);};	file << format_str;	file.close();	return (0);}%1$c%1$c/*%1$c	Colleen in C++%1$c*/%1$cMAIN(CODE, FILE_NAME)%1$c"
#define FILE_NAME "Grace_kid.cpp"
#define MAIN(code, file_name) int main() {	std::string	str = code;	std::string	format_str(str);	std::string::size_type	pos = format_str.find("%1$c");	std::ofstream	file(file_name);	while (pos != std::string::npos) {		format_str.replace(pos, 4, 1, 10);		pos = format_str.find("%1$c", pos + 1);	}	pos = format_str.find("%2$c");	while (pos != std::string::npos) {		format_str.replace(pos, 4, 1, 34);		pos = format_str.find("%2$c", pos + 1);	}	pos = format_str.find("%3$c");	while (pos != std::string::npos) {		format_str.replace(pos, 4, 1, 37);		pos = format_str.find("%3$c", pos + 1);	}	pos = format_str.find("%4$s");	if (pos != std::string::npos) {		format_str.replace(pos, 4, str);	}	if (!file.is_open()) {return (1);};	file << format_str;	file.close();	return (0);}

/*
	Colleen in C++
*/
MAIN(CODE, FILE_NAME)
