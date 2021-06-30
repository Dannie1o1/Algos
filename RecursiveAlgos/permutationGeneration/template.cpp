#include <iostream>
#include <vector>

using namespace std;

//SOLID Principles
//1) Single Responsible Principle
//2) Open-Closed Principle
//3) Liskov Principle
//4) Interface Segregation Principle
//5) Dependency Inversion Principle

class Set{
    private: 
    vector<int> set;

    Set()
    {
        int number;
        cout << "Please enter the numbers to put in the set" << endl;
        while (cin >> number)
        {
            set.push_back(number);
        }
        cout << "permutation object filled" << endl;
    }

    Set(vector<int> &set)
    {
       this->set = set;
    }
};

class Permutation{
    private:
    vector<int> permutation;
};

int main()
{
    Set s1();
}