#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> m = {{1, "ss"}, {2, "sz"}};
    using KeyType = std::map<int, std::string>::key_type;

    std::cout << "Type to subscript: " << typeid(KeyType).name() << std::endl;
    std::cout << "returned from subscript operator: " << typeid(decltype(m[1])).name() << std::endl;
}
