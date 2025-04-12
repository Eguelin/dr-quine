#include <fstream>
#include <iostream>
#include <algorithm>
/*
	Colleen in C++
*/

const std::string	format (const std::string &str) {
	std::string				format_str(str);
	std::string::size_type	pos = format_str.find("%1$c");

	while (pos != std::string::npos) {
		format_str.replace(pos, 4, 1, 10);
		pos = format_str.find("%1$c", pos + 1);
	}

	pos = format_str.find("%2$c");
	while (pos != std::string::npos) {
		format_str.replace(pos, 4, 1, 34);
		pos = format_str.find("%2$c", pos + 1);
	}

	pos = format_str.find("%3$c");
	while (pos != std::string::npos) {
		format_str.replace(pos, 4, 1, 37);
		pos = format_str.find("%3$c", pos + 1);
	}

	pos = format_str.rfind("%4$s");
	if (pos != std::string::npos) {
		format_str.replace(pos, 4, str);
	}

	return (format_str);
}

int main() {
	/*
		Main function
	*/
	std::string str = "#include <fstream>%1$c#include <iostream>%1$c#include <algorithm>%1$c/*%1$c	Colleen in C++%1$c*/%1$c%1$cconst std::string	format (const std::string &str) {%1$c	std::string				format_str(str);%1$c	std::string::size_type	pos = format_str.find(%2$c%3$c1$c%2$c);%1$c%1$c	while (pos != std::string::npos) {%1$c		format_str.replace(pos, 4, 1, 10);%1$c		pos = format_str.find(%2$c%3$c1$c%2$c, pos + 1);%1$c	}%1$c%1$c	pos = format_str.find(%2$c%3$c2$c%2$c);%1$c	while (pos != std::string::npos) {%1$c		format_str.replace(pos, 4, 1, 34);%1$c		pos = format_str.find(%2$c%3$c2$c%2$c, pos + 1);%1$c	}%1$c%1$c	pos = format_str.find(%2$c%3$c3$c%2$c);%1$c	while (pos != std::string::npos) {%1$c		format_str.replace(pos, 4, 1, 37);%1$c		pos = format_str.find(%2$c%3$c3$c%2$c, pos + 1);%1$c	}%1$c%1$c	pos = format_str.rfind(%2$c%3$c4$s%2$c);%1$c	if (pos != std::string::npos) {%1$c		format_str.replace(pos, 4, str);%1$c	}%1$c%1$c	return (format_str);%1$c}%1$c%1$cint main() {%1$c	/*%1$c		Main function%1$c	*/%1$c	std::string str = %2$c%4$s%2$c;%1$c%1$c	std::cout << format(str);%1$c	return (0);%1$c}%1$c";

	std::cout << format(str);
	return (0);
}
