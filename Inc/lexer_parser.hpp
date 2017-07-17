#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>

class lexer_parser
{
    private:
        std::vector< std::string > file_data;
        std::vector< std::string > tokens;

    public:

        void process_data(int count, char **file);
        std::string trim( std::string line );
};
