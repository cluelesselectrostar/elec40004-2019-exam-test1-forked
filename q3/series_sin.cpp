#include "series_operations.hpp"

class SeriesSin
	:public Series
{
public:
	SeriesSin() {}

	virtual double a(int n) override
	{
		if(n%2==0){
			return 0;
		}else{
			return pow(-1, n)/factorial(2*n+1);
		}
	}
};

Series *series_sin(Series *s)
{
    assert(s->is_variable());
    return new SeriesSin;
}
