//
// Created by Sofiia Tesliuk on 2019-04-23.
//

#include "additionals.h"
#include "time_measure.h"


int main(int argc, char *argv[]) {
    std::string config_filename;

    // Getting filename of config
    if (argc > 1){
        config_filename = argv[1];
    } else{
        config_filename = "config.dat";
    }

    // Getting configuration from config_file
    std::vector<std::string> configuration = parse_config_file(config_filename);
    if (configuration.size() == 5){
        // Everything is okay
        // TODO:
    } else{
        std::cout << "Something gone wrong with configuration file: " << config_filename << std::endl;
    }

    // Reading file or archive for words
    // TODO

    // Cutting words
    // TODO

    // Counting words from file
    // TODO

    // Sorting results
    // TODO

    // Write results to files
    // TODO


    return 0;
}