#include <iostream>

int main(int argc, char *argv[])
{
    int sys = 0;
    int stu = 0;
    
    std::cin >> sys;
    std::cin >> stu;
    
    if ((sys == 1 && stu == 1) || (sys != 1 && stu != 1))
    {
    	std::cout << "YES";
	}
	
	else
	{
		std::cout << "NO";
	}
	
	return 0;
}