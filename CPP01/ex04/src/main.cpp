#include "../includes/loserSed.hpp"

int main(int argc, char **argv) {
	if (is_input_good(argc, argv) == false) return 1;

	std::ifstream ifs;
	std::ofstream ofs;
	std::string infile = argv[1];

	if (fstream_setup(infile, ifs, ofs) == false)
		return 1;
	else
		replace_strings(argv[2], argv[3], ifs, ofs);
	ifs.close();
	ofs.close();
	return 0;
}

int is_input_good(int argc, char **argv) {
	if (argc != 4) return std::cerr << BAD_ARG_COUNT << std::endl, false;
	for (int i = 0; i < argc; ++i)
		if (std::string(argv[i]).empty()) return std::cerr << EMPTY_ARG << std::endl, false;
	return (true);
}

int fstream_setup(std::string infile, std::ifstream &ifs, std::ofstream &ofs) {
	char	array[infile.size() + 1];
	array[infile.size()] = '\0';
	for (unsigned long i = 0; i < infile.size(); i++)
		array[i] = infile.at(i);	
	ifs.open(array);
	if (ifs.is_open() == false) return std::cerr << INFILE_ERROR << infile << std::endl, false;

	infile.append(".replaced");
	array[infile.size()] = '\0';
	for (unsigned long i = 0; i < infile.size(); i++)
		array[i] = infile.at(i);	
	ofs.open(array);
	if (ifs.is_open() == false) return std::cerr << OUTFILE_ERROR << infile << std::endl, false;
	return true;
}

void replace_strings(std::string to_replace, std::string replacement, std::ifstream &ifs,
					 std::ofstream &ofs) {
	while (ifs.eof() == false) {
		replace(to_replace, replacement, ifs, ofs);
		if (ifs.peek() != EOF) ofs << std::endl;
	}
	ofs << std::endl;
}

// searcvg for the word and replace it from it's position with the new word
void replace(std::string to_replace, std::string replacement, std::ifstream &ifs,
			 std::ofstream &ofs) {
	std::string line;
	size_t word_position;

	std::getline(ifs, line);
	while (true) {
		word_position = line.find(to_replace);
		if (word_position >= line.length()) {
			ofs << line;
			break;
		} else {
			ofs << line.substr(0, word_position);
			line = line.substr(word_position + to_replace.length());
			ofs << replacement;
		}
	}
}