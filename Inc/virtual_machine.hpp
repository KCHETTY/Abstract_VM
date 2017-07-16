#pragma once

#include "type_factory.hpp"
#include <deque>

class virtual_machine
{
    private:

        type_factory factory;
        std::deque< IOperand * > stack;

    public:

        void create_test(std::string temp)
        {
            this->factory.createOperand(INT8, temp);
        }


};
