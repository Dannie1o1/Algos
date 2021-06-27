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
                permutation.push_back(i);
                //permutation.push_back(set[i-1]);
                Search();
                chosen[i] = false;
                permutation.pop_back();
            } 
        }
    }

    //Inputs: Set(1,2,3), chosen(0,0,0), p()
    //search()
    // p.size() = 0
    // for: i=1
    //      chosen is false
    //      chosen[1] = true;
    //      p = 1
        
        //search()
        //p.size() = 1
        //for : i=1 
        //      chosen is true
        //for : i=2
        //      chosen is false
        //      chosen[2] = true
        //      p = 1,2
            //search()
            // p.size() = 2
            // for: i=1
            //      chosen is true
            // for: i=2
            //      chosen is true
            // for: i=3
            //      chosen is false
            //      chosen[3] = true;
            //      p = 1,2,3
                //search()
                // p.size() = 3
                // print(p = 1,2,3)
                // exit this call
            //      chosen[3] = false;
            //      p = 1,2
            //      exit for loop
            //exit this call
        //     chosen[2] = false
        //     p = 1
        //for : i=3
        //      chosen is false
        //      chosen[3] = true
        //      p = 1,3
            //search()
            //  p.size() = 2
            //  for : i=1
            //      chosen[1] = true
            //  for : i=2
            //      chosen[2] = false
            //      p = 1,3,2
                //search()
                // p.size() = 3
                // print(p = 1,3,2)
                // end this call
            // for : i=3
            //      chosen[3] = true
            // end of for loop
            // end of this call
        //   chosen[3] = false
        //   p = 1,3
        // end of for loop
        // end of this call
    
    // for: i=2



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
    vector<int> set = {1,2,3};
    Permutation s(set);
    s.Search();

    return 0;
}