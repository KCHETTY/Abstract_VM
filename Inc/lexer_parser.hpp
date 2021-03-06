#pragma once

#include "Exceptions.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <regex>

class lexer_parser
{
    private:
        std::vector< std::string > file_data;
        std::vector< std::string > error_data;
        Exceptions excp;

    public:

        lexer_parser();
        lexer_parser( std::vector< std::string > file_data );

        void process_data(int count, char **file, std::vector< std::string > &tokenz);
        void lexer( std::vector< std::string > &tokenz );
        void parser();
        void handle_comment( std::string &line );
        std::string trim( std::string line );

        virtual ~lexer_parser();
};

std::ostream &operator<<(std::ostream &os, const lexer_parser &obj);
