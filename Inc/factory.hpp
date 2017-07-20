#pragma once

#include "Operand.hpp"
#include <iostream>

class factory
{
    private:

        //function pointer definition
        typedef IOperand const * (factory::*func_ptr)( std::string const & value ) const;
        func_ptr func_arr[5] = {&factory::createInt8, &factory::createInt16, &factory::createInt32, &factory::createfloat, &factory::createdouble};

        IOperand const *createInt8( std::string const & value ) const;
        IOperand const *createInt16( std::string const & value ) const;
        IOperand const *createInt32( std::string const & value ) const;
        IOperand const *createfloat( std::string const & value ) const;
        IOperand const *createdouble( std::string const & value ) const;

    public:

        factory();

        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
        virtual ~factory();
};
