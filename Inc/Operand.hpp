#pragma once

#include "IOperand.hpp"

template <eOperandType type, class T> class Operand : public IOperand
{
    private:
        T num_value;
        std::string str_value;

        Operand();

    public:

        Operand( T tmp_val , std::string str_tmp_val );

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

template<eOperandType type, class T> Operand<type, T>::Operand( T tmp_val ,std::string str_tmp_val )
{
    this->str_value = str_tmp_val;
    this->num_value = tmp_val;
    std::cout << this->str_value << std::endl;
    std::cout << static_cast<int> (this->num_value) << " " << sizeof(this->num_value) << std::endl;
}

template<eOperandType type, class T> eOperandType Operand<type, T>::getType() const
{
    return (type);
}
