#pragma once

#include "factory.hpp"
#include "lexer_parser.hpp"

#include <deque>

class virtual_machine
{
    private:

        lexer_parser input;
        factory Tfactory;

        std::deque< IOperand const * > stack;


        virtual_machine();

    public:

        virtual_machine( int argc, char **argv);

        void execute_commands();

};
