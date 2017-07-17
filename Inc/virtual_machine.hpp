#pragma once

#include "factory.hpp"
#include <deque>

class virtual_machine
{
    private:

        factory Tfactory;
        std::deque< IOperand const * > stack;

    public:

        void create_test(std::string temp)
        {
            std::cout << temp << std::endl;
            this->stack.push_front(this->Tfactory.createOperand(eOperandType::INT8, "54"));
            std::cout << this->stack[0]->getType() << std::endl;

            this->stack.push_front(this->Tfactory.createOperand(eOperandType::FLOAT, "108"));
            std::cout << this->stack[0]->getType() << std::endl;

            std::cout << this->stack.size() << std::endl;

            this->stack.push_front((*this->stack[0] + *this->stack[1]));

            std::cout << this->stack[0]->getType() << " " << this->stack[0]->toString() << std::endl;


        }


};
