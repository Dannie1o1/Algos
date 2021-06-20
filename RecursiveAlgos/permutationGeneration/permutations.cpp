#include <iostream>
#include <vector>

using namespace std;

class MySet{
    private:
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

    vector<int> GetSet()
    {
        return set;
    }
};

class Permutation{
    private:
    vector<bool> chosen;
    vector<int> permutation;
    vector<int> currentSet;

    public:
    Permutation()
    {
    };

    Permutation(MySet &set)
    {
        vector<bool> chosen(set.GetSize()+1, false);
        this->chosen = chosen;
        currentSet = set.GetSet();
        //cout << "chosen's size: " << chosen.size() << endl;
        //cout << "Set's size: " << currentSet.size() << endl;
    }
    
    void Search()
    {
        if(permutation.size() == currentSet.size())
        {
            PrintPerms();
        }
        else
        {
            for (int i = 1; i <= currentSet.size(); i++)
            {
                if (chosen[i] == true) continue;
                chosen[i] = true;
                permutation.push_back(i);
                Search();
                chosen[i] = false;
                permutation.pop_back();
            } 
        }
    }

    protected:
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
    vector<int> set = {1,2,3};

    MySet s(set);
    Permutation p(s);
    p.Search();


    return 0;
}