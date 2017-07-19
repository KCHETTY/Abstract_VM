#pragma once

#include "factory.hpp"
#include "Exceptions.hpp"
#include "lexer_parser.hpp"

#include <deque>

class virtual_machine
{
    private:

        lexer_parser input;
        factory Tfactory;
        Exceptions excp;

        std::deque < IOperand const * > stack;
        std::vector < std::string > commands;

        int arg_count;
        char **arg;

        virtual_machine();

    public:

        virtual_machine( int argc, char **argv);

        void execute_commands();
        void push_operand( std::string op_type, std::string val );
        void dump();
        void pop_deque();
        void stack_assert( std::string type, std::string val );
        void print();
        void check_stack();

};
