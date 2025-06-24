#include <iostream>
#include <vector>
#include <limits>

int main()
{

    std::vector<int> v = {1,2,3,4,5};
    int thirdElement = v[2];

    v.push_back(1);
    v.push_back(8);

    

    if(v.size() == 0)
    {
        return -1;
    }

    int maxi = v.at(0);
    int mini = v.at(0);
    for(int i=0;i<v.size();i++)
    {
        if(mini>v[i])
        {
            mini = v[i];
        }
        if(v[i] > maxi)
        {
            maxi = v[i];
        }

    }

    std::cout<< maxi <<std::endl;
    std::cout<< mini <<std::endl;

    return 0;
}