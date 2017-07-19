#include "../Inc/Exceptions.hpp"

void Exceptions::empty_file()
{
    throw EmptyFile;
}

void Exceptions::invalid_file()
{
    throw InvalidFile;
}

void Exceptions::print_fail()
{
    throw PrintFail;
}

void Exceptions::assert_fail()
{
    throw AssertFail;
}

void Exceptions::exit_missing()
{
    throw NoExit;
}

void Exceptions::invalid_stack_size()
{
    throw StackTooSmall;
}

void Exceptions::error()
{
    throw Errors;
}
