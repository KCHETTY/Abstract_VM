#include "../Inc/factory.hpp"

IOperand const * factory::createOperand( eOperandType type, std::string const & value ) const
{
    return ((this->*func_arr[type])(value));
}

IOperand const * factory::createInt8( std::string const & value ) const
{
    return ( new Operand<eOperandType::INT8, int8_t>::Operand( static_cast<int8_t> (std::stoi(value, NULL)), value ) );
}

IOperand const * factory::createInt16( std::string const & value ) const
{
    return ( new Operand<eOperandType::INT16, int16_t>::Operand( static_cast<int16_t> (std::stoi(value, NULL)), value ) );
}

IOperand const * factory::createInt32( std::string const & value ) const
{
    return ( new Operand<eOperandType::INT32, int32_t>::Operand( static_cast<int32_t> (std::stoi(value, NULL)) , value ));
}

IOperand const * factory::createfloat( std::string const & value ) const
{
    return ( new Operand<eOperandType::FLOAT, float_t>::Operand( std::stod(value, NULL) , value ));
}

IOperand const * factory::createdouble( std::string const & value ) const
{
    return ( new Operand<eOperandType::DOUBLE, double_t>::Operand( std::stof(value, NULL), value));
}
