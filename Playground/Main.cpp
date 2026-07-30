#include <iostream>
#include <string>

int main()
{
    std::string name = "완재";

    std::cout << "sizeof(name) : " << sizeof(name) << '\n';
    for(int i = 0; i < 10; ++i)
        std::cout << "name.size() : " << name[i] << '\n';

}