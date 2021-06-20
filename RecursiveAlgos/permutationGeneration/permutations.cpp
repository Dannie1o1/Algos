#include <iostream>
#include <vector>

using namespace std;

class MySet{
    protected:
    vector<int> set;

    public:
    MySet()
    { }

    MySet(vector<int> &set)
    {
        this->set = set;
    }

    int GetSize()
    {
        return set.size();
    }

    int GetElement(int i)
    {
        return set[i];
    }

    vector<int>& GetSet()
    {
        return set;
    }
};

class Permutation : public MySet {
    private:
    vector<bool> chosen;
    vector<int> permutation;

    public:
    Permutation(vector<int> &set):MySet(set)
    {
        chosen.resize(set.size()+1,false);
    }
    
    void Search()
    {
        if(permutation.size() == set.size())
        {
            PrintPerms();
        }
        else
        {
            for (int i = 1; i <= set.size(); i++)
            {
                if (chosen[i] == true) continue;
                chosen[i] = true;
                permutation.push_back(set[i-1]);
                Search();
                chosen[i] = false;
                permutation.pop_back();
            } 
        }
    }

    private:
    void PrintPerms()
    {
        for (auto perm: permutation)
        {
            cout << perm << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> set = {4,5,6};
    Permutation s(set);
    s.Search();

    return 0;
}