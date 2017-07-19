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

void lexer_parser::process_data(int count, char **file, std::vector< std::string > &tokenz)
{
    if (count > 1)
    {
        std::ifstream ReadFile(file[1]);
        std::string data;

        if (ReadFile.is_open())
        {
            while (!ReadFile.eof())
            {
                std::getline(ReadFile, data);
                data = trim( data );
                if ( ((data[0] == ';') && (data.length() == 1 || data.length() > 1)) || (data.compare("") == 0) )
                    continue ;
                this->file_data.push_back(data);
            }
        }
        else
            excp.invalid_file();

        ReadFile.close();
    }
    else
    {
        for ( std::string line; std::getline(std::cin, line); )
        {
            line = trim( line );

            if ( line.compare(";;") == 0)
                break ;

            if ( ((line[0] == ';') && (line.length() == 1 || line.length() > 1)) || (line.compare("") == 0))
                continue ;

            this->file_data.push_back(line);
        }
        std::cout << std::endl;
    }

    if (this->file_data.size() == 0)
        excp.empty_file();

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
        excp.error();
    }
}

void lexer_parser::lexer( std::vector< std::string > &tokens )
{
    std::string line;
    std::string tokenz;

    for (unsigned int count = 0; count < this->file_data.size(); count++)
    {
        line = this->file_data[count];
        if (line.compare("") == 0)
            continue ;
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

                    tokens.push_back(temp);
                }

                tokens.push_back(tokenz);
            }
            else
                this->error_data.push_back( "line " + std::to_string(count + 1) + ": invalid operation \"" + tokenz + "\"");
        }
        tokens.push_back(" ");
    }
}

void lexer_parser::parser()
{
    std::string line;
    int is_exit = 0;

    for (unsigned int count = 0; count < this->file_data.size(); count++)
    {
        line = this->file_data[count];

        std::regex rgx_ints("^push( +)int(8|16|32)\\(-?[0-9]+\\)( *)"); //Checks for Push int 8 / 16 / 32
        std::regex rgx_decimals("^push( +)(float|double)\\(-?[0-9]+(.[0-9]+)?\\)( *)");
        std::regex rgx_modifications("^(pop|dump|add|mul|sub|div|mod|print|exit)( *)");
        std::regex rgx_assert("^assert( +)(int(8|16|32)|float|double)\\(-?[0-9]+(.[0-9]+)?\\)( *)");

        if (line.find("exit") != std::string::npos)
            is_exit++;

        if (is_exit > 1)
        {
            this->error_data.push_back( "line " + std::to_string(count + 1) + ": Syntax Error -> Duplicate command \"exit\"");
            is_exit = 1;
        }

        if (std::regex_match(line, rgx_ints) || std::regex_match(line, rgx_decimals) || std::regex_match(line, rgx_assert) || std::regex_match(line, rgx_modifications) || line.compare("") == 0 )
            continue ;
        else
            this->error_data.push_back( "line " + std::to_string(count + 1) + ": Syntax Error \"" + line + "\"");
    }

    if (is_exit == 0)
        excp.exit_missing();
}
