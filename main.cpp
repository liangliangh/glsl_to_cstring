
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

int main(int argc, char* argv[])
{
	std::ifstream ifs;
	for(int i=1; i<argc; ++i)
	{
		std::cout << "-------- shader " << i << " -------------------\n";
		ifs.open(argv[i]);
		if(ifs.is_open())
		{
			std::cout << "\"\\\n";
			while(!ifs.eof())
			{
				std::string a; std::getline(ifs, a);
				int k = a.length();	while(--k>=0 && std::isspace(a[k])) ;
				a.erase(a.begin()+k+1, a.end());
				std::cout << a << "\\n\\\n";
			}
			std::cout << "\"\n";
		}
		else
		{
			std::cout << "\"" << argv[i] << "\"" << "open failed!\n";
		}
		std::cout << "-------- end ------------------------\n\n";
		ifs.close();
	}
	return 0;
}
