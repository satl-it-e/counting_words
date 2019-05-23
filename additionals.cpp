
#include "additionals.h"


// Return string - extention of the filename.
std::string get_file_ext(const std::string &file_name){
    std::size_t dot_ind = file_name.find_last_of('.');
    return file_name.substr(dot_ind);
}

// Check if string can be converted to float.
int is_file_ext(const std::string &file_name, const std::string &ext){
    return !file_name.compare(file_name.length()-ext.length(), ext.length(), ext);
}