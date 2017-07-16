#include "../Inc/factory.hpp"

IOperand const *createInt8( std::string const & value ) const;
IOperand const *createInt16( std::string const & value ) const;
IOperand const *createInt32( std::string const & value ) const;
IOperand const *createfloat( std::string const & value ) const;
IOperand const *createdouble( std::string const & value ) const;

IOperand const * createOperand( eOperandType type, std::string const & value ) const;