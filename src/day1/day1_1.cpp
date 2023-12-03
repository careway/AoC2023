#include <iostream>
#include <fstream>


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

        std::cout << line << std::endl;

        for(auto it = line.begin(), end = line.end(); it != end ; it++)
        {
            if(*it - '0' <= 9)
            {
                nums += (*it) - '0';
                break;
            }
        }

        nums *=10;

        for(auto it = line.rbegin(), end = line.rend(); it != end ; it++)
        {
            if(*it - '0' <= 9)
            {
                nums += (*it) - '0';
                break;
            }
        }

        res +=nums;

        /* code */
    }

    std::cout << res << std::endl;
        

}
