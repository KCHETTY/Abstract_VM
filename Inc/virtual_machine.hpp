#pragma once

#include "factory.hpp"
#include <deque>

class virtual_machine
{
    private:

        factory Tfactory;
        std::deque< const IOperand * > stack;

    public:

        void create_test(std::string temp)
        {
            this->stack.push_front(this->Tfactory.createOperand(eOperandType::INT8, temp));
            std::cout << this->stack[0]->getType() << std::endl;

            this->stack.push_front(this->Tfactory.createOperand(eOperandType::INT16, temp));
            std::cout << this->stack[0]->getType() << std::endl;


            /*this->Tfactory.createOperand(INT16, temp);
            this->Tfactory.createOperand(INT32, temp);
            this->Tfactory.createOperand(DOUBLE, temp);
            this->Tfactory.createOperand(FLOAT, temp);*/
        }


};
