#include <iostream>
#include <fstream>

#include <boost/locale.hpp>
//#include <boost/locale/boundary/segment.hpp>
//#include <boost/locale/boundary/index.hpp>

#include "additionals.h"
#include "config.h"


int main(int argc, char *argv[]){

    std::string conf_file_name, to_file_alph, to_file_occur;

    if(argc > 1){
        conf_file_name = argv[1];
    } else { conf_file_name = "config.dat"; }

    if (! is_file_ext(conf_file_name, ".txt") && ! is_file_ext(conf_file_name, ".dat") ) {
        std::cerr << "Wrong config file extention." << std::endl;
        return -1;
    }

    // config
    MyConfig mc;
    mc.load_configs_from_file(conf_file_name);
    if (mc.is_configured()) {
        std::cout << "YES! Configurations loaded successfuly.\n" << std::endl;
    } else { std::cerr << "Error. Not all configurations were loaded properly."; return -3;}


    // read
    std::ifstream in_f(mc.in_file);
    if (! in_f.is_open() || in_f.rdstate())
        { std::cerr << "Couldn't open input-file."; return -2; }

    std::string content; std::stringstream ss;
    ss << in_f.rdbuf();
    content = ss.str();


    using namespace boost::locale::boundary;

    std::locale loc = boost::locale::generator().generate("en_US.UTF-8");
    std::string text = "To e e e e  that be oR nOt to Be, that is! th?e question.";

    // fold case
    text = boost::locale::to_lower(text, loc);

    // words to map
    std::unordered_map<std::string, int> cut_words;
    ssegment_index map(word, text.begin(), text.end(), loc);
    map.rule(word_any);

    for (ssegment_index::iterator it = map.begin(), e = map.end(); it != e; ++it) {
        cut_words[*it]++;
    }


    using namespace std;

    // sort & write
    std::vector<std::pair<std::string, int> > vector_words;
    for (auto &word: cut_words){
        vector_words.emplace_back(word);
    }

    std::sort(vector_words.begin(), vector_words.end(), [](const auto t1, const auto t2){ return t1.second < t2.second;});
    ofstream num_out_f(mc.to_numb_file);
    for (auto &v : vector_words) {
        num_out_f << v.first << ": " << std::to_string(v.second) + "\t";
    }

    std::sort(vector_words.begin(), vector_words.end(), [](const auto t1, const auto t2){ return t1.first.compare(t2.first)<0;});
    ofstream alp_out_f(mc.to_alph_file);
    for (auto &v : vector_words) {
        alp_out_f << v.first << ": " << std::to_string(v.second) + "\t";
    }


    std::cout << "\nOK\n" << std::endl;
    return 0;

}