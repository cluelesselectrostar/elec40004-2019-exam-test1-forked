#include "series_operations.hpp"

float factorial(int n){
    if (n==0)
        return 1;
    else
        return 2*n*factorial(n-1);
}

class SeriesCos
	:public Series
{
public:
	SeriesCos()
	{
	}

	virtual double a(int n) override
	{
		if(n%2==1){
			return 0;
		}else{
			return pow(-1, n)/factorial(2*n);
		}
	}
}


Series *series_cos(Series *s)
{
    assert(s->is_variable());
    assert(0);
    return new SeriesCos(s);
}
