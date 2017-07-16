#pragma once

#include "factory.hpp"
#include <deque>

class virtual_machine
{
    private:

        factory Tfactory;
        std::deque< IOperand * > stack;

    public:

        void create_test(std::string temp)
        {
            this->Tfactory.createOperand(INT8, temp);
            this->Tfactory.createOperand(INT16, temp);
            this->Tfactory.createOperand(INT32, temp);
            this->Tfactory.createOperand(DOUBLE, temp);
            this->Tfactory.createOperand(FLOAT, temp);
        }


};
