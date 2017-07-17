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

void lexer_parser::process_data(int count, char **file)
{
    if (count > 1)
    {
        std::ifstream ReadFile(file[1]);
        std::string data;

        if (ReadFile.is_open())
        {
            while (!ReadFile.eof())
            {
                ReadFile >> data;
                data = trim( data );
                this->file_data.push_back(data);
                std::cout << data << std::endl;
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
}
