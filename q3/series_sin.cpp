#include "series_operations.hpp"

float factorial(int n){
    if (n==0)
        return 1;
    else
        return 2*n*factorial(n-1);
}

class SeriesSin
	:public Series
{
public:
	SeriesSin()
	{
	}

	virtual double a(int n) override
	{
		if(n%2==0){
			return 0;
		}else{
			return pow(-1, n)/factorial(2*n+1);
	}
}

Series *series_sin(Series *s)
{
    assert(s->is_variable());
    assert(0);
    return new SeriesSin(s);
}
