#pragma once

#include <exception>

class Exceptions
{
    public:

        class StackTooSmall : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Critical Error: Stack size too small.");
            }

        } StackTooSmall;

        class NoExit : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Syntax Error: Missing command \"exit\"");
            }

        } NoExit;

        class AssertFail : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Critical Error: Assert command failed.");
            }

        } AssertFail;

        class Errors : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("");
            }

        } Errors;

        class PrintFail : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Critical Error: Print command failed.");
            }

        } PrintFail;

        class InvalidFile : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Critical Error: Invalid file.");
            }

        } InvalidFile;

        class EmptyFile : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Critical Error: Empty file.");
            }

        } EmptyFile;


        void empty_file();
        void invalid_file();
        void print_fail();
        void assert_fail();
        void exit_missing();
        void invalid_stack_size();
        void error();
};
