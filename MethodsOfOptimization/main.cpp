#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>
#include <math.h>

#include "helper.h"
#include "optimizationMethods.h"

int main(int, char** const) {
	
	setlocale(LC_ALL, "RUS");

	FuncParams params{ { -10 , 3}, pow(10, -12),
		[] (double x) {
			return pow(x, 2) - (4 * x) + 2;
		}
	};

	optimize(std::vector<optimFunTy>{
		uniformSearch,
		dychotomicSearch,
		fibSearch,
		goldenRatio
	}, params);

	return EXIT_SUCCESS;
}

