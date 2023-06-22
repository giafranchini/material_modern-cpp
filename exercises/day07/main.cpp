#include <memory>
#include <iostream>
#include <concepts>
#include <ranges>

template <typename T>
T add (T a, T b) requires std::integral<T>{
    return a+b;
}

template<typename T>
concept Incrementable = requires(T a)
{
    a++;
    ++a;
    a--;
    --a;
};

template<Incrementable T>
auto f(T a, int op) 
{
    switch (op)
    {
    case 0: std::cout << "Calling prefix increment" << std::endl; a++;     return;
    case 1: std::cout << "Calling postfix increment" << std::endl; ++a;    return;
    case 2: std::cout << "Calling prefix decrement" << std::endl; a--;     return;
    case 3: std::cout << "Calling postfix decrement" << std::endl; --a;    return;
    default: std::cout << "Default case" << std::endl;                     return;
    };
};

class Point 
{
    private:
        int m_x;
        int m_y;
    
    public:
        Point(int x=0, int y=0) : m_x {x}, m_y {y} {};
        Point& operator++();
};

Point& Point::operator++()
{
    this->m_x++;
    this->m_y++;
    return *this; 
};


int main(int argc, char *argv[])
{
    {
        char a_char{10};
        char b_char(10);

        int  a_int{10};
        int  b_int{20};

        double a_double{10};
        double b_double{10};

        // Works, result empty
        // auto result = add(a_char, b_char);
        // std::cout<<"The result is "<< result << std::endl;

        // Works, result 30
        // auto result = add(a_int, b_int);
        // std::cout<<"The result is "<<result << std::endl;

        // Compile time error --> double is not an integral type
        // auto result = add(a_double, b_double);
        // std::cout<<"The result is "<<result << std::endl;
    }

    {
        // TODO write an "is_incrementable" concept
        // and use it
        for (int i {0}; i < 5; i++)
        {
            // Test with int
            // int a_int {0};
            // f(a_int, i);
            
            // Test with double
            // double a_double {0};
            // f(a_double, i);

            // Test with char
            // char a_char {0};
            // f(a_char, i);

            // Test with custom class --> does not compile, unless we overload the increment operators
            // Point p;
            // f(p, i);
        }
    }

    {
        // TODO generate a series of numbers from 0 to 20
        // and print it only the even. You must use views

        auto even = [](int n)
        {
            return n%2 == 0;
        };
        
        auto my_first_view = std::views::iota(0, 21) | std::views::filter(even);
        for (auto i : my_first_view)
        {
            std::cout << i << " ";
        };
        std::cout << std::endl;
    }

    return 0;

}