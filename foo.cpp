#include <boost/variant.hpp>
#include <string>
#include <iostream>

struct output : public boost::static_visitor<>
{
    void operator()(double d) const { std::cout << d << std::endl; }
    void operator()(char c) const { std::cout << c << std::endl; }
    void operator()(std::string s) const { std::cout << s << std::endl; }
};

int main()
{
    boost::variant<double, char, std::string> v;
    v = 3.14;
    boost::apply_visitor(output{}, v);
    v = 'A';
    boost::apply_visitor(output{}, v);
    v = "Boost";
    boost::apply_visitor(output{}, v);
}