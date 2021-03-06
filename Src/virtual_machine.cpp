#include "../Inc/virtual_machine.hpp"

virtual_machine::virtual_machine()
{
    this->arg_count = 0;
    this->arg = NULL;
}

virtual_machine::virtual_machine( int argc, char **argv) : virtual_machine()
{
    this->arg_count = argc;
    this->arg = argv;
}

void virtual_machine::push_operand( std::string op_type, std::string val )
{
    if (op_type.compare("int8") == 0)
        this->stack.push_front(this->Tfactory.createOperand(eOperandType::INT8, val));
    else if (op_type.compare("int16") == 0)
        this->stack.push_front(this->Tfactory.createOperand(eOperandType::INT16, val));
    else if (op_type.compare("int32") == 0)
        this->stack.push_front(this->Tfactory.createOperand(eOperandType::INT32, val));
    else if (op_type.compare("float") == 0)
        this->stack.push_front(this->Tfactory.createOperand(eOperandType::FLOAT, val));
    else if (op_type.compare("double") == 0)
        this->stack.push_front(this->Tfactory.createOperand(eOperandType::DOUBLE, val));
}

void virtual_machine::dump()
{
    for (unsigned int count = 0; count < this->stack.size(); count++)
    {
        std::cout << this->stack[count]->toString() << std::endl;
    }
}

void virtual_machine::print()
{
    if (this->stack.size() < 1)
        excp.invalid_stack_size();

    if ( 0 != this->stack[0]->getType() )
        excp.print_fail();
    std::cout << static_cast<char> (std::stoi(this->stack[0]->toString())) << std::endl;
}

void virtual_machine::check_stack()
{
    if (this->stack.size() < 2)
        excp.invalid_stack_size();
}

void virtual_machine::stack_assert( std::string type, std::string val )
{
    if (this->stack.size() < 1)
        excp.invalid_stack_size();

    int no_type = 0;

    if (type.compare("int8") == 0)
		no_type = eOperandType::INT8;
	else if (type.compare("int16") == 0)
		no_type = eOperandType::INT16;
	else if (type.compare("int32") == 0)
		no_type = eOperandType::INT32;
	else if (type.compare("float") == 0)
		no_type = eOperandType::FLOAT;
	else if (type.compare("double") == 0)
		no_type = eOperandType::DOUBLE;

    if (no_type != this->stack[0]->getType() || val.compare(this->stack[0]->toString()))
        excp.assert_fail();
}

void virtual_machine::pop_deque()
{
    for (int i = 0; i < 2; i++)
    {
        delete this->stack[i];
    }

    this->stack.pop_front();
    this->stack.pop_front();
}

void virtual_machine::clear_stack()
{
    for (unsigned int count = 0; count < this->stack.size(); count++)
    {
        delete this->stack[count];
    }
    this->stack.clear();
}

void virtual_machine::execute_commands()
{
    try
    {
        const IOperand * tmp = NULL;
        this->input.process_data(this->arg_count, this->arg, this->commands);

        for (unsigned int count = 0; count < this->commands.size(); count++ )
        {
            if (this->commands[count].compare("push") == 0)
                push_operand( this->commands[count + 1], this->commands[count + 2]);
            else if (this->commands[count].compare("dump") == 0)
                dump();
            else if (this->commands[count].compare("pop") == 0)
            {
                if (this->stack.size() < 1)
                    excp.invalid_stack_size();
                this->stack.pop_front();
            }
            else if (this->commands[count].compare("sub") == 0)
            {
                check_stack();
                tmp = *this->stack[0] - *this->stack[1];
                pop_deque();
                this->stack.push_front(tmp);

            }
            else if (this->commands[count].compare("div") == 0)
            {
                check_stack();
                tmp = *this->stack[0] / *this->stack[1];
                pop_deque();
                this->stack.push_front(tmp);
            }
            else if (this->commands[count].compare("mul") == 0)
            {
                check_stack();
                tmp = *this->stack[0] * *this->stack[1];
                pop_deque();
                this->stack.push_front(tmp);
            }
            else if (this->commands[count].compare("add") == 0)
            {
                check_stack();
                tmp = *this->stack[0] + *this->stack[1];
                pop_deque();
                this->stack.push_front(tmp);
            }
            else if (this->commands[count].compare("mod") == 0)
            {
                check_stack();
                tmp = *this->stack[0] % *this->stack[1];
                pop_deque();
                this->stack.push_front(tmp);
            }
            else if (this->commands[count].compare("assert") == 0)
                stack_assert( this->commands[count + 1], this->commands[count + 2] );
            else if (this->commands[count].compare("print") == 0)
                print();
            else if (this->commands[count].compare("exit") == 0)
            {
                clear_stack();
                break ;
            }
        }
    }
    catch (std::exception &e)
    {
        clear_stack();
        std::cout << e.what() << std:: endl;
    }

}
