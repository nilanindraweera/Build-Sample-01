#include <iostream>
#include "include/employee.h"

int main()
{
    std::cout << "sample 01" << std::endl;

    employee em{"shanilan"};
    std::cout << "employee name " << em.get_name() << std::endl;

    return 0;
}