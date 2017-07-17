
#include "../Inc/virtual_machine.hpp"
#include "../Inc/lexer_parser.hpp"

int main(int argc, char **argv)
{
    lexer_parser input;
    virtual_machine test;

    input.process_data(argc, argv);

    //Operand <INT8, int8_t> template_test;

    //std::cout << template_test.getType() std::endl;

    test.create_test("4");
    return (0);
}
