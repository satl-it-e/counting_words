#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>

#include <archive.h>
#include <archive_entry.h>

#include <boost/locale.hpp>
#include <boost/locale/boundary/segment.hpp>
#include <boost/locale/boundary/index.hpp>

#include "additionals.h"
#include "config.h"
#include "archive_extract.h"
#include "time_measure.h"


int main(int argc, char *argv[]){

    std::string conf_file_name, to_file_alph, to_file_occur;

    if(argc > 1){
        conf_file_name = argv[1];
    } else { conf_file_name = "config.dat"; }

    if (! is_file_ext(conf_file_name, ".txt") && ! is_file_ext(conf_file_name, ".dat") ) {
        std::cerr << "Wrong config file extension." << std::endl;
        return -1;
    }

    // config
    MyConfig mc;
    mc.load_configs_from_file(conf_file_name);
    if (mc.is_configured()) {
        std::cout << "YES! Configurations loaded successfully.\n" << std::endl;
    } else { std::cerr << "Error. Not all configurations were loaded properly."; return -3;}


    std::string read_file;

    // opening archive
    if (is_file_ext(mc.in_file, ".zip")){
        read_file = extract(mc.in_file.c_str());
    } else{
        read_file = mc.in_file.c_str();
    }

    auto gen_st_time = get_current_time_fenced();         //~~~~~~~~~ read start
    std::ifstream in_f(read_file);
    if (! in_f.is_open() || in_f.rdstate())
        { std::cerr << "Couldn't open input-file."; return -2; }

    std::string content; std::stringstream ss;
    ss << in_f.rdbuf();
    content = ss.str();

    auto read_fn_time = get_current_time_fenced();        //~~~~~~~~~ read finish  | index start

    using namespace boost::locale::boundary;

    std::locale loc = boost::locale::generator().generate("en_US.UTF-8");

    // fold case
    content = boost::locale::to_lower(content, loc);

    // words to map
    std::unordered_map<std::string, int> cut_words;
    ssegment_index map(word, content.begin(), content.end(), loc);
    map.rule(word_any);

    for (ssegment_index::iterator it = map.begin(), e = map.end(); it != e; ++it) {
        cut_words[*it]++;
    }

    auto index_fn_time = get_current_time_fenced();       //~~~~~~~~~ index finish

    using namespace std;

    // sort & write
    std::vector<std::pair<std::string, int> > vector_words;
    for (auto &word: cut_words){
        vector_words.emplace_back(word);
    }

    std::sort(vector_words.begin(), vector_words.end(), [](const auto t1, const auto t2){ return t1.second < t2.second;});
    ofstream num_out_f(mc.to_numb_file);
    for (auto &v : vector_words) {
        num_out_f << std::left << std::setw(20) << v.first << ": ";
        num_out_f << std::right << std::setw(10) << std::to_string(v.second) << std::endl;
    }

    std::sort(vector_words.begin(), vector_words.end(), [](const auto t1, const auto t2){ return t1.first.compare(t2.first)<0;});
    ofstream alp_out_f(mc.to_alph_file);
    for (auto &v : vector_words) {
        alp_out_f << std::left << std::setw(20) << v.first <<  ": ";
        alp_out_f << std::right << std::setw(10) << std::to_string(v.second) << std::endl;
    }

    auto gen_fn_time = get_current_time_fenced();         //~~~~~~~~~ general finish


    std::cout << std::left  << std::setw(35) <<  "General time (read-index-write): ";
    std::cout << std::right  << std::setw(10) << to_us(gen_fn_time - gen_st_time) << std::endl;
    std::cout << std::left  << std::setw(35) << "Reading time (after unzip): ";
    std::cout << std::right << std::setw(10) << to_us(read_fn_time - gen_st_time)  << std::endl;
    std::cout << std::left << std::setw(35) << "Indexing time (boost included): " ;
    std::cout << std::right  << std::setw(10) << to_us(index_fn_time - read_fn_time)  << std::endl;

    std::cout << "\nFinished.\n" << std::endl;
    return 0;

}