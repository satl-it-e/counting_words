#include <iostream>
#include <fstream>

#include <boost/locale.hpp>
#include <boost/locale/boundary/segment.hpp>
#include <boost/locale/boundary/index.hpp>

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
    boost::locale::generator gen;
    std::string text="To be or not to be, that is the question.";
    ssegment_index map(word,text.begin(),text.end(),gen("en_US.UTF-8"));

//    std::string const text= "To be or not to be, that is the question.";

//    sboundary_point_index map(word,text.begin(),text.end());
//
//    map.rule(word_any);

    std::cout << "OK" << std::endl;
    return 0;
}