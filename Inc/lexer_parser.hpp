#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <regex>

class lexer_parser
{
    private:
        std::vector< std::string > tokens;
        std::vector< std::string > file_data;
        std::vector< std::string > error_data;

    public:

        //void process_data(int count, char **file, std::vector < std::string > &file_data );
        void process_data(int count, char **file);
        void lexer();
        void parser();
        std::string trim( std::string line );
};
