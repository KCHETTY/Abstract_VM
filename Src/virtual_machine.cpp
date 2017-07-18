#include "../Inc/virtual_machine.hpp"

virtual_machine::virtual_machine()
{

}

virtual_machine::virtual_machine( int argc, char **argv)
{
    this->input.process_data(argc, argv);
}

void virtual_machine::execute_commands()
{
    //for (unsigned int count = 0; count < this->file_data.size(); count++ )
    //{
    //    std::cout << this->file_data[count] << std::endl;

        //if (this->file_data[count].compare("") == 0)
    //}
}
