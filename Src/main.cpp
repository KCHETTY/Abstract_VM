
#include "../Inc/virtual_machine.hpp"
#include "../Inc/Operand.hpp"

int main()
{
    virtual_machine test;
    //Operand <INT8, int8_t> template_test;

    //std::cout << template_test.getType() std::endl;

    test.create_test("First_test");
    return (0);
}
