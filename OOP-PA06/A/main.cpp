#include <iostream>

int main(){
    std::string a = "abcdefg";
    for (int i = 0; i < a.size(); ++i)
    {
        a.at(i) = char(i + 'A');
    }
    std::cout << a << std::endl;
}

