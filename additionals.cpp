//
// Created by Sofiia Tesliuk on 2019-04-23.
//

#include "additionals.h"


std::vector<std::string> parse_config_file(std::string config_filename){
    std::vector<std::string> config;
    //TODO
    return config;
}


std::string get_txt_file(const std::string* unknown){
    std::string valid_txt;
    //TODO
    return valid_txt;
}


std::string read_file(const std::string* unknown_data_filename){
    std::string words;

    std::string data_filename = get_txt_file(unknown_data_filename);
    //TODO

    return words;
}


std::vector<std::string> cut_words(const std::string* file){
    std::vector<std::string> words;
    //TODO
    return words;
}


std::map<std::string, int> count_same_words(const std::vector<std::string> words){
    std::map<std::string, int> counted_words;
    //TODO
    return counted_words;
}


bool by_alphabet(const std::string* w1, const std::string* w2){
    //TODO
    return true;
}


bool by_number(const std::string* w1, const std::string* w2){
    //TODO
    return true;
}


void write_results(const std::string* out_filename, const std::map<std::string, int>* results){
    //TODO
}