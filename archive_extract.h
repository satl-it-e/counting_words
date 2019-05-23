#ifndef COUNTING_WORDS_ARCHIVE_EXTRACT_H
#define COUNTING_WORDS_ARCHIVE_EXTRACT_H

#include <iostream>

#include <sys/types.h>

#include <sys/stat.h>

#include <archive.h>
#include <archive_entry.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int
copy_data(struct archive *ar, struct archive *aw);


std::string
extract(const char *filename);



#endif //COUNTING_WORDS_ARCHIVE_EXTRACT_H
