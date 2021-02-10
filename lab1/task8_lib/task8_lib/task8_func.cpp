#include <iostream>
#include "task8_func.h"

double x, result;

void f(void) {
	result = (1 - 2 * (sin(x) * sin(x)) / 1 + sin(x) * sin(x));
}