#ifndef BUREAUCRAFTDEFINES_HPP
#define BUREAUCRAFTDEFINES_HPP

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

#define DEFBURO "Default Bureaucrat"
#define ASSIGNMENT " assignment operator called."
#define BUREAUCRAT "\033[1;33mBureaucrat \033[1;32m"
#define DESTRUCTOR " \033[1;31mdestructor called.\033[1;39m"
#define CONSTRUCTOR "\033[1;33m constructor called.\033[1;39m"
#define COPYCON " \033[1;33mcopy constructor called.\033[1;39m"
#define INCR " \033[1;34mgrade has been incremented.\033[1;39m"
#define DECR " \033[1;34mgrade has been decremented.\033[1;39m"
#define WI "\033[1;31m's grade would be too high, cannot increment.\n\033[1;39m"
#define WD "\033[1;31m's grade would be too low, cannot decrement.\n\033[1;39m"
#define GTL "\033[1;31m's grade is too low, cannot initialize.\n\033[1;39m"
#define GTH "\033[1;31m's grade is too high, cannot initialize.\n\033[1;39m"

#define BAD_INPUT "Wrong testcase ID. Available options are:\n\n"
#define TEST0 "      nothing -> options\n"
#define TEST1 "         1    -> test for making valid forms\n"
#define TEST2 "         2    -> test for trying to make non existent forms\n"

#endif