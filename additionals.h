//
// Created by Sofiia Tesliuk on 2019-04-23.
//

#ifndef COUNTING_WORDS_ADDITIONALS_H
#define COUNTING_WORDS_ADDITIONALS_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>


auto read_entire_file(std::string& in_filename);


std::vector<std::string> parse_config_file(std::string config_filename);


std::string get_txt_file(const std::string* unknown);


std::string read_file(const std::string* unknown_data_filename);


std::vector<std::string> cut_words(const std::string* file);


std::map<std::string, int> count_same_words(const std::vector<std::string> words);


bool by_alphabet(const std::string* w1, const std::string* w2);


bool by_number(const std::string* w1, const std::string* w2);


void write_results(const std::string* out_filename, const std::map<std::string, int>* results);

#endif //COUNTING_WORDS_ADDITIONALS_H
