#include "../Inc/lexer_parser.hpp"

std::string lexer_parser::trim( std::string line )
{
    std::string tmp;
    int is_front = 1;

    for (unsigned int count = 0; count < line.length(); count++)
    {
        if (line[count] != ' ')
            is_front = 0;
        else if (is_front)
            continue ;

        if (line[count] == ' ' && line[count + 1] == ' ' && is_front == 0)
            continue ;
        else
            tmp = tmp + line[count];
    }

    if (tmp[tmp.size() - 1] == ' ')
        tmp.pop_back();

    return (tmp);
}

bool lexer_parser::process_data(int count, char **file, std::vector< std::string > &tokenz)
{
    if (count > 1)
    {
        std::ifstream ReadFile(file[1]);
        std::string data;

        if (ReadFile.is_open())
        {
            while (!ReadFile.eof())
            {
                //ReadFile >> data;
                std::getline(ReadFile, data);
                data = trim( data );
                this->file_data.push_back(data);
            }
        }
        else
            std::cout << "Invalid File" << std::endl;

        ReadFile.close();
    }
    else
    {
        for ( std::string line; std::getline(std::cin, line); )
        {
            line = trim( line );
            std::cout << line << std::endl;
            if ( line.compare(";;") == 0)
                break ;
            this->file_data.push_back(line);

        }
    }

    std::cout << "Them TESTS" << std::endl;
    for (unsigned int count = 0; count < this->file_data.size(); count++)
    {
        std::cout << this->file_data[count] << std::endl;
    }

    lexer( tokenz );

    if (this->error_data.size() == 0)
        parser();

    if (this->error_data.size() > 0)
    {
        for (unsigned int counter = 0; counter < this->error_data.size(); counter++)
        {
            std::cout << this->error_data[counter] << std::endl;
        }
        std::cout << "Total Errors: " << this->error_data.size() << std::endl;

        return (true);
    }

    return (false);
}

void lexer_parser::lexer( std::vector< std::string > &tokens )
{
    std::string line;
    std::string tokenz;

    for (unsigned int count = 0; count < this->file_data.size(); count++)
    {
        line = this->file_data[count];
        for (unsigned int length = 0; length < line.length(); length++)
        {
            tokenz = line.substr(0, line.find(" "));
            line = line.substr(tokenz.length(), line.length());
            line = trim(line);

            std::regex rgx_ints("^int(8|16|32)\\(-?[0-9]+\\)( *)");
            std::regex rgx_decimals("^(float|double)\\(-?[0-9]+(.[0-9]+)?\\)( *)");
            std::regex rgx_modifications("^(assert|push|pop|dump|add|mul|sub|div|mod|print|exit)( *)");
            if (std::regex_match(tokenz, rgx_ints) || std::regex_match(tokenz, rgx_decimals) || std::regex_match(tokenz, rgx_modifications))
            {
                if (std::regex_match(tokenz, rgx_ints) || std::regex_match(tokenz, rgx_decimals))
                {
                    std::string temp;
                    temp = tokenz.substr(0, tokenz.find("("));
                    tokenz = tokenz.substr(temp.length() + 1, tokenz.find(")"));
                    tokenz.pop_back();
                    //temp += ")";

                    tokens.push_back(temp);
                }

                tokens.push_back(tokenz);
            }
            else
                this->error_data.push_back( "line " + std::to_string(count + 1) + ": invalid operation \"" + tokenz + "\"");
        }
        tokens.push_back(" ");
    }

    /*std::cout << "THE TOKENZ" << std::endl;
    for (unsigned int count = 0; count < this->tokens.size(); count++)
    {
        std::cout << this->tokens[count] << std::endl;
    }*/
}

void lexer_parser::parser()
{
    std::string line;
    bool is_exit = false;

    for (unsigned int count = 0; count < this->file_data.size(); count++)
    {
        line = this->file_data[count];

        std::regex rgx_ints("^push( +)int(8|16|32)\\(-?[0-9]+\\)( *)"); //Checks for Push int 8 / 16 / 32
        std::regex rgx_decimals("^push( +)(float|double)\\(-?[0-9]+(.[0-9]+)?\\)( *)");
        std::regex rgx_modifications("^(dump|exit)( *)");
        std::regex rgx_assert("^assert( +)(int(8|16|32)|float|double)\\(-?[0-9]+(.[0-9]+)?\\)( *)");
        if (std::regex_match(line, rgx_ints) || std::regex_match(line, rgx_decimals) || std::regex_match(line, rgx_assert) )
            continue ;
        else
            this->error_data.push_back( "line " + std::to_string(count + 1) + ": Syntax Error \"" + line + "\"");

        if ( std::regex_match(line, rgx_modifications) && !is_exit)
                is_exit = true;
        else
            this->error_data.push_back( "line " + std::to_string(count + 1) + ": Syntax Error -> Duplicate command \"exit\"");
    }

    if (!is_exit)
        this->error_data.push_back( "Syntax Error -> Missing \"exit\"");
}
