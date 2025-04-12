#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unistd.h>

#define CODE "#include <fstream>%1$c#include <sstream>%1$c#include <iostream>%1$c#include <algorithm>%1$c#include <unistd.h>%1$c%1$c#define CODE %2$c%5$s%2$c%1$c%1$cconst std::string	format (const std::string &str, int i);%1$c%1$cint main() {%1$c	int					i = %4$d;%1$c	int					pid;%1$c	std::ofstream		file;%1$c	std::stringstream	ss;%1$c	std::string			file_name;%1$c%1$c	if (i <= 0)%1$c		return (0);%1$c	if (std::string(%2$cSully.cpp%2$c) != __FILE__)%1$c		i--;%1$c	ss << %2$cSully_%2$c << i;%1$c	file_name = ss.str();%1$c%1$c	file.open(ss.str() + %2$c.cpp%2$c);%1$c	if (!file.is_open())%1$c		return (1);%1$c	file << format(CODE, i);%1$c	file.close();%1$c	ss.str(%2$c%2$c);%1$c	ss << %2$cc++ -Wall -Wextra -Werror %2$c << file_name << %2$c.cpp -o %2$c << file_name;%1$c	if (system(ss.str().c_str()))%1$c		return (1);%1$c	pid = fork();%1$c	if (pid == -1)%1$c		return (1);%1$c	if (pid == 0)%1$c		execl(file_name.c_str(), file_name.c_str(), NULL);%1$c	return (0);%1$c}%1$c%1$cconst std::string	format (const std::string &str, int i) {%1$c	std::string				format_str(str);%1$c	std::string::size_type	pos = format_str.find(%2$c%3$c1$c%2$c);%1$c%1$c	while (pos != std::string::npos) {%1$c		format_str.replace(pos, 4, 1, 10);%1$c		pos = format_str.find(%2$c%3$c1$c%2$c, pos + 1);%1$c	}%1$c%1$c	pos = format_str.find(%2$c%3$c2$c%2$c);%1$c	while (pos != std::string::npos) {%1$c		format_str.replace(pos, 4, 1, 34);%1$c		pos = format_str.find(%2$c%3$c2$c%2$c, pos + 1);%1$c	}%1$c%1$c	pos = format_str.find(%2$c%3$c3$c%2$c);%1$c	while (pos != std::string::npos) {%1$c		format_str.replace(pos, 4, 1, 37);%1$c		pos = format_str.find(%2$c%3$c3$c%2$c, pos + 1);%1$c	}%1$c%1$c	pos = format_str.find(%2$c%3$c4$d%2$c);%1$c	if (pos != std::string::npos)%1$c		format_str.replace(pos, 4, 1, i + '0');%1$c%1$c	pos = format_str.find(%2$c%3$c5$s%2$c);%1$c	if (pos != std::string::npos)%1$c		format_str.replace(pos, 4, str);%1$c%1$c%1$c	return (format_str);%1$c}%1$c"

const std::string	format (const std::string &str, int i);

int main() {
	int					i = 5;
	int					pid;
	std::ofstream		file;
	std::stringstream	ss;
	std::string			file_name;

	if (i <= 0)
		return (0);
	if (std::string("Sully.cpp") != __FILE__)
		i--;
	ss << "Sully_" << i;
	file_name = ss.str();

	file.open(ss.str() + ".cpp");
	if (!file.is_open())
		return (1);
	file << format(CODE, i);
	file.close();
	ss.str("");
	ss << "c++ -Wall -Wextra -Werror " << file_name << ".cpp -o " << file_name;
	if (system(ss.str().c_str()))
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		execl(file_name.c_str(), file_name.c_str(), NULL);
	return (0);
}

const std::string	format (const std::string &str, int i) {
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

	pos = format_str.find("%4$d");
	if (pos != std::string::npos)
		format_str.replace(pos, 4, 1, i + '0');

	pos = format_str.find("%5$s");
	if (pos != std::string::npos)
		format_str.replace(pos, 4, str);


	return (format_str);
}
