#include <vector>
#include <algorithm>
#include <iostream>

int main(int argc, char *argv[])
{
    {
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);

        for (int i = 0; i< numbers.size(); i++) {

            numbers[i] = numbers[i] * 2;
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        // TODO: Rewrite the above code using modern c++ using algorithm and lambda
        std::vector<int> numbers {1, 2, 3, 4, 5};
        std::transform(numbers.begin(), numbers.end(), numbers.begin(), [] (const int &i) {return i*2;});
        for (auto &i : numbers)
        {
            std::cout << i << " ";
        };
        std::cout << std::endl;
    }

}