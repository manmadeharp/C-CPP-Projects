#include <iostream>

struct Vector {
		int sz;
		double* elem;
};

void vector_init(Vector& v, int s);
double read_and_sum(int s);
void f(Vector v, Vector& rv, Vector* pv);

int main()
{
	int s = 5;
	double sum = read_and_sum(s); 
	std::cout << sum << '\n';
}



void vector_init(Vector& v, int s)
{
		v.elem = new double[s];
		v.sz = s;
}

double read_and_sum(int s)
{
		Vector v, rv;	
		vector_init(v,s);
		Vector* pv; 
		f(v, rv, pv);
		for (int i=0; i!=s; ++i)
				std::cin>>v.elem[i];

		double sum = 0;
		for (int i=0; i!=s; ++i)
				sum+=v.elem[i];
		return sum;
}

void f(Vector v, Vector& rv, Vector* pv)
{
		int i1 = v.sz;     // access through name
		int i2 = rv.sz;    // access through reference
		int i4 = pv->sz;   // access through pointer
}
