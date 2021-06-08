#include<iostream>
#include<cmath>
#include<map>

float root(std::map<int, float> arg)
{
	if(arg.size() > 1)
		return 0;
	return std::sqrt(arg[0]);
}


