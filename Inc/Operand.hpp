#pragma once

#include "IOperand.hpp"

template <eOperandType type, class T> class Operand : public IOperand
{
    private:
        T num_value;
        std::string str_value;

        Operand();

    public:

        class Div0Exception : public std::exception
        {
            virtual const char * what() const throw()
            {
                return ("Div: Mod by zero is undefined.");
            }
        } Div0E;

        class OverflowException : public std::exception
        {
            virtual const char * what() const  throw()
            {
                return ("Overflow/Underflow reached on type");
            }
        } Oexep;

        void check_over_under_flow(eOperandType type_tmp, long double value) const;

        Operand( T tmp_val , std::string str_tmp_val );

        int getPrecision( void ) const; // Precision of the type of the instance
        eOperandType getType( void ) const; // Type of the instance

        IOperand const * create_obj(eOperandType type_tmp, long double value) const;

        IOperand const * operator+( IOperand const & obj ) const;
        IOperand const * operator-( IOperand const & obj ) const;
        IOperand const * operator*( IOperand const & obj ) const;
        IOperand const * operator/( IOperand const & obj ) const;
        IOperand const * operator%( IOperand const & obj ) const;


        std::string const & toString( void ) const; // String representation of the instance
        ~Operand( void ) {}
};

template<eOperandType type, class T> void Operand<type, T>::check_over_under_flow(eOperandType type_tmp, long double value) const
{
    if (type_tmp == eOperandType::INT8 && (value < INT8_MIN || value > INT8_MAX))
        throw Oexep;
    else if (type_tmp == eOperandType::INT16 && (value < INT16_MIN || value > INT16_MAX))
        throw Oexep;
    else if (type_tmp == eOperandType::INT32 && (value < INT32_MIN || value > INT32_MAX))
        throw Oexep;
    else if (type_tmp == eOperandType::FLOAT && (value < -1.175494e+37 || value > 3.40282e+38))
        throw Oexep;
    else if (type_tmp == eOperandType::DOUBLE && (value < -2.22507e+307 || value > 1.79769e+308))
        throw Oexep;
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::create_obj(eOperandType type_tmp, long double value) const
{
    check_over_under_flow(type_tmp, value);
    int tmp = static_cast<int> (value);

    switch (type_tmp)
    {
        case eOperandType::INT8:
            return ( new Operand<eOperandType::INT8, int8_t>::Operand( static_cast<int8_t> (value), std::to_string(tmp) ) );
        case eOperandType::INT16:
            return ( new Operand<eOperandType::INT16, int16_t>::Operand( static_cast<int16_t> (value), std::to_string(tmp) ) );
        case eOperandType::INT32:
            return ( new Operand<eOperandType::INT32, int32_t>::Operand( static_cast<int32_t> (value), std::to_string(tmp) ) );
        case eOperandType::FLOAT:
            return ( new Operand<eOperandType::FLOAT, float_t>::Operand( static_cast<float_t> (value) , std::to_string(value) ));
        case eOperandType::DOUBLE:
            return ( new Operand<eOperandType::DOUBLE, double_t>::Operand( static_cast<double_t> (value), std::to_string(value)));
    }

    return (NULL);
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator+( IOperand const & obj ) const
{
    long double tmp = std::stold(this->str_value) + std::stold(obj.toString());

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator-( IOperand const & obj ) const
{
    long double tmp = std::stold(this->str_value) - std::stold(obj.toString());

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator*( IOperand const & obj ) const
{
    long double tmp = std::stold(this->str_value) * std::stold(obj.toString());

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator/( IOperand const & obj ) const
{
    long double tmp = std::stold(this->str_value) / std::stold(obj.toString());

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> IOperand const * Operand<type, T>::operator%( IOperand const & obj ) const
{
    long double tmp = fmod(std::stold(this->str_value) , std::stold(obj.toString()));

    if (obj.getPrecision() < this->getPrecision())
        return ( create_obj(this->getType(), tmp) );
    return ( create_obj(obj.getType(), tmp) );
}

template<eOperandType type, class T> Operand<type, T>::Operand( T tmp_val ,std::string str_tmp_val )
{
    long double tmp = std::stold(str_tmp_val);
    check_over_under_flow(type, tmp);
    this->str_value = str_tmp_val;
    this->num_value = tmp_val;
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
