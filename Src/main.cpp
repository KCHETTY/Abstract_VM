
#include "../Inc/virtual_machine.hpp"
#include "../Inc/lexer_parser.hpp"

int main(int argc, char **argv)
{
    virtual_machine vm(argc, argv);

    vm.execute_commands();

    return (0);
}
