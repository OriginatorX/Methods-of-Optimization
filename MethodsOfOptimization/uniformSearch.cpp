#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

#include "optimizationMethods.h"

void uniformSearch(
	const Interval& interval, 
	Computation& result,
	const double precision, 
	function desiredFun) 
{	
	const int segmentsQuantity{ 100 };
	const double segmentLength{ interval.len / segmentsQuantity };
	Point desiredPoint{ interval.middle, desiredFun(interval.middle) };

	if (interval.len <= precision) {
		result.point = desiredPoint;
		return;
	}
	
	for (double i = interval.left; i <= interval.right; i += segmentLength) {
		Point minPoint{};
		minPoint = { i, desiredFun(i) };
		desiredPoint = min(desiredPoint, minPoint);
		result.mediatePoints.push_back(minPoint);
	}

	Interval nextInterval{};
	if (desiredPoint.point == interval.left) {
		nextInterval = { desiredPoint.point, desiredPoint.point + segmentLength };
	}
	else if (desiredPoint.point == interval.right) {
		nextInterval = { desiredPoint.point - segmentLength, desiredPoint.point };
	}
	else {
		nextInterval = { desiredPoint.point - segmentLength, desiredPoint.point + segmentLength };
	}

	result.iterQuantity++;
	uniformSearch(nextInterval, result, precision, desiredFun);
}
