
#include "../Inc/virtual_machine.hpp"
#include "../Inc/lexer_parser.hpp"

int main(int argc, char **argv)
{
    virtual_machine test(argc, argv);

    test.execute_commands();
    
    return (0);
}
