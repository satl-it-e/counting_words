#ifndef COUNTING_WORDS_CONFIG_H
#define COUNTING_WORDS_CONFIG_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <functional>
#include <unordered_set>
#include <vector>
#include <list>
#include <set>


#include "additionals.h"

    class MyConfig{

        public:
            std::string in_file;
            std::string to_alph_file;
            std::string to_numb_file;
            int num_of_threads;

        private:
            std::unordered_set<std::string> check_set = {"in_file", "to_alph_file", "to_numb_file", "num_of_threads"};

        public:
            bool set_in_file(const std::list<std::string> &s_values);
            bool set_to_alph_file(const std::list<std::string> &s_values);
            bool set_to_numb_file(const std::list<std::string> &s_values);
            bool set_num_of_threads(const std::list<std::string> &s_values);

            bool is_configured();
            int load_configs_from_file(const std::string &f_name);
    };


#endif //COUNTING_WORDS_CONFIG_H
