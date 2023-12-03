#include <iostream>
#include <fstream>
#include <iomanip>



int checkNumber(std::string::iterator& it, std::string::iterator end, bool replace = true)
{
    auto copy = it;
    int ret = -1;
    if(*copy == 'z')
    {
        if(++copy != end && *copy == 'e')
        if(++copy != end && *copy == 'r') 
        {
            if(++copy != end && *copy == 'o'){
                ret = 0;
            }
        }else{
            copy--;
        }
    }
    else if(*copy == 'o')
    {
        if(++copy != end && *copy == 'n')
        if(++copy != end && *copy == 'e'){
            ret = 1;
        }
    }
    else if (*copy == 't')
    {
        if(++copy != end && *copy == 'w')
        {
            if(++copy != end && *copy == 'o'){
                ret = 2;
            }
        }
        else if ( *copy == 'h')
        {
            if(++copy != end && *copy == 'r')
            if(++copy != end && *copy == 'e')
            if(++copy != end && *copy == 'e')
            {
                ret = 3;
            }
        }
        
    }
    else if (*copy == 'f')
    {
        if(++copy != end && *copy == 'o')
        {
            if(++copy != end && *copy == 'u')
            {
                if(++copy != end && *copy == 'r')
                {
                    ret = 4;
                }
            }else{
                copy--;
            }
        }
        else if ( *copy == 'i')
        {
            if(++copy != end && *copy == 'v')
            if(++copy != end && *copy == 'e')
            {
                ret = 5;
            }
        }
    }
    else if (*copy == 's')
    {
        if(++copy != end && *copy == 'i')
        {
            if(++copy != end && *copy == 'x')
            {
                ret = 6;
            }
        }
        else if ( *copy == 'e')
        {
            if(++copy != end && *copy == 'v')
            {
                if(++copy != end && *copy == 'e')
                if(++copy != end && *copy == 'n')
                {
                    ++copy;
                    ret = 7;
                }
            }else
            {
                copy--;
            }

        }
    }
    else if (*copy == 'e')
    {
        if(++copy != end && *copy == 'i')
        if(++copy != end && *copy == 'g')
        if(++copy != end && *copy == 'h')
        if(++copy != end && *copy == 't')
        {
            ret = 8;
        }
    }
    else if (*copy == 'n')
    {
        if(++copy != end && *copy == 'i')
        if(++copy != end && *copy == 'n')
        if(++copy != end && *copy == 'e')
        {
            ret = 9;
        }
        
    }
    if(replace)
        it = (ret ==-1 && copy != it)?copy-1:copy;
    return ret;
}

int main(int argc, char** argv){
    std::ifstream data;
    data.open(argv[1]);
    if(!data.is_open())
    {
        std::cout << " Not open " << std::endl;
        return -1;
    }

    int  res = 0;

    while (!data.eof())
    {
        std::string line;
        std::getline(data,line);
        int nums = 0;

        for(auto it = line.begin(), end = line.end(); it != end ; it++)
        {
            int n = *it - '0';
            if(n <= 9 && n >= 0)
            {
                nums += n;
                break;
            }
            else
            {
                int n = checkNumber(it, end);
                if(n != -1)
                {
                    nums = n;
                    break;
                }
            }
        }

        nums *=10;

        for(auto it = line.end()-1, end = line.begin()-1, rend = line.end(); it != end ; it--)
        {
            int n = *it - '0';
            if(n <= 9 && n >= 0)
            {
                nums += (*it) - '0';
                break;
            }
            else{
                int n = checkNumber(it, rend, false);
                if(n != -1)
                {
                    nums += n;
                    break;
                }
            }
        }

        res +=nums;

        
        std::cout << std::setw(2) << nums << " <- " << line << std::endl; 

        /* code */
    }

    std::cout << res << std::endl;
        

}
