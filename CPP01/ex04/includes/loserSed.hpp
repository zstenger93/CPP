#ifndef LOSERSED_HPP
#define LOSERSED_HPP

#include <fstream>
#include <iostream>

#define INFILE_ERROR "Error! Cannot open the input stream on the following file: "
#define OUTFILE_ERROR "Error! Cannot open output stream on the following file: "
#define BAD_ARG_COUNT "Error! Invalid number of arguments."
#define EMPTY_ARG "Error! Arguments cannot be empty"

int is_input_good(int argc, char **argv);
int fstream_setup(std::string infile, std::ifstream &ifs, std::ofstream &ofs);
void replace(std::string to_replace, std::string replacement, std::ifstream &ifs,
             std::ofstream &ofs);
void replace_strings(std::string to_replace, std::string replacement, std::ifstream &ifs,
                     std::ofstream &ofs);
#endif