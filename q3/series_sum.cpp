#include "series_operations.hpp"


Series *series_sum(Series *a, Series *b)
{
    return a->a() + b->a();
}
