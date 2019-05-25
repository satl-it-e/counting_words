
#ifndef COUNTING_WORDS_ADDITIONALS_H
#define COUNTING_WORDS_ADDITIONALS_H

#include <string>


int is_file_ext(const std::string &file_name, const std::string &ext);

std::string get_file_ext(const std::string &file_name);

bool is_directory(const std::string& object);

#endif //COUNTING_WORDS_ADDITIONALS_H
