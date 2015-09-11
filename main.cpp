
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	std::ifstream ifs;
	for(int i=1; i<argc; ++i)
	{
		if(argc>2) std::cout << "-------- shader " << i << " -------------------\n";
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
		if(argc>2) std::cout << "-------- end ------------------------\n\n";
		ifs.close();
	}

	if(argc<2){
		const int N = 40;
		const float R = 1.0f;
		const float H = 0.5f;

		printf("%d  %d\n", N*2+2, N*2);

		for(int i=0; i<=N; ++i){
			float theta = i * 2.0f*M_PI/N + M_PI/2;
			if(theta>=M_PI*2) theta -= M_PI*2;
			float x = R*cos(theta);
			float y = R*sin(theta);
			float tex = float(i) / N;
			printf("%f %f %f %f %f\n", x, y, 0.0f, tex, 0.0f);
			printf("%f %f %f %f %f\n", x, y, H, tex, 1.0f);
		}

		for(int i=0; i<=N-1; ++i){
			printf("%d %d %d\n", i*2, i*2+2, i*2+1);
			printf("%d %d %d\n", i*2+1, i*2+2, i*2+3);
		}

	}

	return 0;
}
