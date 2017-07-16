#include "../Inc/factory.hpp"

IOperand const * factory::createOperand( eOperandType type, std::string const & value ) const
{
    return ((this->*func_arr[type])(value));
}

IOperand const * factory::createInt8( std::string const & value ) const
{
    std::cout << "Test 1 " << value << std::endl;
    return ( new Operand<eOperandType::INT8, int8_t>::Operand(value) );
}

IOperand const * factory::createInt16( std::string const & value ) const
{
    std::cout << "Test 2 " << value << std::endl;
    return ( new Operand<eOperandType::INT16, int16_t>::Operand(value) );
}

IOperand const * factory::createInt32( std::string const & value ) const
{
    std::cout << "Test 3 " << value << std::endl;
    return ( new Operand<eOperandType::INT32, int32_t>::Operand(value) );
}

IOperand const * factory::createfloat( std::string const & value ) const
{
    std::cout << "Test 4 " << value << std::endl;
    return ( new Operand<eOperandType::FLOAT, float_t>::Operand(value) );
}

IOperand const * factory::createdouble( std::string const & value ) const
{
    std::cout << "Test 5 " << value << std::endl;
    return ( new Operand<eOperandType::DOUBLE, double_t>::Operand(value) );
}
