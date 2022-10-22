#include "rect.h"

rect::rect(double l, double w) :len(l), wid(w) {}

double rect::area()
{
	return len * wid;
}
rect::~rect(void)
{
}
