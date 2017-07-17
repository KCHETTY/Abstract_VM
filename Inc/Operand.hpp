#pragma once

#include "IOperand.hpp"

template <eOperandType type, class T> class Operand : public IOperand
{
    private:
        std::string str_value;

        Operand();

    public:

        T num_value;

        Operand( T tmp_val , std::string str_tmp_val );

        int getPrecision( void ) const; // Precision of the type of the instance
        eOperandType getType( void ) const; // Type of the instance

        IOperand const * create_obj(eOperandType type_tmp, long double value);

        IOperand const * operator+( IOperand const & obj ); // Sum
        IOperand const * operator-( IOperand const & obj ); // Difference
        IOperand const * operator*( IOperand const & obj ); // Product
        IOperand const * operator/( IOperand const & obj ); // Quotient
        IOperand const * operator%( IOperand const & obj ); // Modulo

        std::string const & toString( void ) const; // String representation of the instance
        ~Operand( void ) {}
};

template<eOperandType type, class T> IOperand const * Operand<type, T>::create_obj(eOperandType type_tmp, long double value)
{
    switch (type_tmp)
    {
        case eOperandType::INT8:
            return ( new Operand<eOperandType::INT8, int8_t>::Operand( static_cast<int8_t> (value), std::to_string(value) ) );
        case eOperandType::INT16:
            return ( new Operand<eOperandType::INT16, int16_t>::Operand( static_cast<int16_t> (value), std::to_string(value) ) );
        case eOperandType::INT32:
            return ( new Operand<eOperandType::INT32, int32_t>::Operand( static_cast<int32_t> (value), std::to_string(value) ) );
        case eOperandType::FLOAT:
            return ( new Operand<eOperandType::FLOAT, float_t>::Operand( static_cast<float_t> (value) , std::to_string(value) ));
        case eOperandType::DOUBLE:
            return ( new Operand<eOperandType::DOUBLE, double_t>::Operand( static_cast<double_t> (value), std::to_string(value)));
    }

    return (NULL);
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator+( IOperand const & obj )
{
    long double tmp = std::stold(this->str_value) + std::stold(obj.toString());

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator-( IOperand const & obj )
{
    long double tmp = std::stold(this->str_value) - std::stold(obj.toString());

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator*( IOperand const & obj )
{
    long double tmp = std::stold(this->str_value) * std::stold(obj.toString());

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator/( IOperand const & obj )
{
    long double tmp = std::stold(this->str_value) / std::stold(obj.toString());

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator%( IOperand const & obj )
{
    long double tmp = fmod(std::stold(this->str_value) , std::stold(obj.toString()));

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> Operand<type, T>::Operand( T tmp_val ,std::string str_tmp_val )
{
    this->str_value = str_tmp_val;
    this->num_value = tmp_val;
    std::cout << this->str_value << std::endl;
    std::cout << static_cast<int> (this->num_value) << " " << sizeof(this->num_value) << std::endl;
}

template<eOperandType type, class T> std::string const & Operand<type, T>::toString() const
{
    return (this->str_value);
}

template<eOperandType type, class T> int Operand<type, T>::getPrecision() const
{
    return (type);
}

template<eOperandType type, class T> eOperandType Operand<type, T>::getType() const
{
    return (type);
}
