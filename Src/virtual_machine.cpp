#include "../Inc/virtual_machine.hpp"

virtual_machine::virtual_machine()
{
    this->is_error = false;
}

virtual_machine::virtual_machine( int argc, char **argv) : virtual_machine()
{
    this->is_error = this->input.process_data(argc, argv, this->commands);
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
    if ( 0 != this->stack[0]->getType() )
        std::cout << "False Buddy" << std::endl;
    std::cout << static_cast<char> (std::stoi(this->stack[0]->toString())) << std::endl;
}

void virtual_machine::stack_assert( std::string type, std::string val )
{
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
        std::cout << "False Buddy" << std::endl;
}

void virtual_machine::pop_deque()
{
    this->stack.pop_front();
    this->stack.pop_front();
}

void virtual_machine::execute_commands()
{
    const IOperand * tmp = NULL;

    for (unsigned int count = 0; count < this->commands.size(); count++ )
    {
        if (this->commands[count].compare("push") == 0)
            push_operand( this->commands[count + 1], this->commands[count + 2]);
        else if (this->commands[count].compare("dump") == 0)
            dump();
        else if (this->commands[count].compare("pop") == 0)
        {
            this->stack.pop_front();
        }
        else if (this->commands[count].compare("sub") == 0)
        {
            tmp = *this->stack[0] - *this->stack[1];
            pop_deque();
            this->stack.push_front(tmp);

        }
        else if (this->commands[count].compare("div") == 0)
        {
            tmp = *this->stack[0] / *this->stack[1];
            pop_deque();
            this->stack.push_front(tmp);
        }
        else if (this->commands[count].compare("mul") == 0)
        {
            tmp = *this->stack[0] * *this->stack[1];
            pop_deque();
            this->stack.push_front(tmp);
        }
        else if (this->commands[count].compare("add") == 0)
        {
            tmp = *this->stack[0] + *this->stack[1];
            pop_deque();
            this->stack.push_front(tmp);
        }
        else if (this->commands[count].compare("mod") == 0)
        {
            tmp = *this->stack[0] % *this->stack[1];
            pop_deque();
            this->stack.push_front(tmp);
        }
        else if (this->commands[count].compare("assert") == 0)
            stack_assert( this->commands[count + 1], this->commands[count + 2] );
        else if (this->commands[count].compare("print") == 0)
            print();
        else if (this->commands[count].compare("exit") == 0)
            break ;
    }
}
