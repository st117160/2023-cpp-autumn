#include <iostream>

int main(int argc, char *argv[])
{
    int sys = 0;
    int stu = 0;
    
    std::cin >> sys;
    std::cin >> stu;
    
    if (stu == 1)
    {
    	if ((sys % 10) == ((sys - sys % 1000)/1000))
		{
			if (((sys%100 - sys % 10)/10) == ((sys % 1000 - sys % 100)/100)) 
			{
				std::cout << "YES";
			}
			
			else
			{
				std::cout << "NO";
			}
		}
		
		else
		{
			std::cout << "NO";
		}
	}
	else
	{
		if ((sys % 10 != ((sys - sys % 1000)/1000))) 
		{
			std::cout << "YES";
		}
		
		else if ((((sys%100 - sys % 10)/10) != ((sys % 1000 - sys % 100)/100)))
		{
			std::cout << "YES";
		}
		
		else
		{
			std::cout << "NO";
		}
	}
}