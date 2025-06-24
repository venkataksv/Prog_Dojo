#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>


int myatoi(const std::string str)
{

    int result=0;
    int sign = 1;
    if (str.empty()) {
        throw std::invalid_argument("Empty string");
    }

    int i=0;
    if(str[0]=='-')
    {
        sign = -1;
        i++;
    }
    for(;i<str.size();i++)
    {  

        if(str[i] > '0' && (str[i]) <= '9' )
        {
            if(result > (std::numeric_limits<int>::max() - (str[i]-'0')/10))
            {
                throw std::out_of_range("Value out of range");
            }
            result = result * 10 + (str[i]-'0');
 
        }
        else
        {
            break;
        }

    }

    return result*sign; 

}


int main()
{
    std::string as = "12345";

    std::cout<<myatoi(as)<<std::endl;

    std::string neg = "-12345";

    std::cout<<myatoi(neg)<<std::endl;

}