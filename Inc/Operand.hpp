#pragma once

#include "IOperand.hpp"

template <eOperandType type, class T> class Operand : public IOperand
{
    private:
        //T value;
        std::string value;

        Operand();

    public:

        Operand( std::string tmp_val );

        //int getPrecision( void ) const; // Precision of the type of the instance
        eOperandType getType( void ) const; // Type of the instance

        /*IOperand const * operator+( IOperand const & obj ); // Sum
        IOperand const * operator-( IOperand const & obj ); // Difference
        IOperand const * operator*( IOperand const & obj ); // Product
        IOperand const * operator/( IOperand const & obj ); // Quotient
        IOperand const * operator%( IOperand const & obj ); // Modulo

        std::string const & toString( void ) const; // String representation of the instance*/
        ~Operand( void ) {}
};

template<eOperandType type, class T> Operand<type, T>::Operand( std::string tmp_val )
{
    this->value = tmp_val;
    std::cout << this->value << std::endl;
}

template<eOperandType type, class T> eOperandType Operand<type, T>::getType() const
{
    return (type);
}
