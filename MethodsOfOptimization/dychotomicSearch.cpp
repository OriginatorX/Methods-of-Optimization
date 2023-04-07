#include <vector>
#include <iostream>

#include "optimizationMethods.h"

void dychotomicSearch(
	const Interval& interval, 
	Computation& result,
	const double precision, 
	function desiredFun) 
{	
	Point desiredPoint{ interval.middle, desiredFun(interval.middle) };
	
	if (interval.len <= precision) {
		result.point = desiredPoint;
		return;
	}

	Interval leftInterval{ interval.left, interval.middle };
	Interval rightInterval{ interval.middle, interval.right };

	std::pair<Point, Point> points{
		Point{leftInterval.middle, desiredFun(leftInterval.middle)},
		Point{rightInterval.middle, desiredFun(rightInterval.middle)}
	};

	Interval nextInterval{};
	if (points.first.value < points.second.value) {
		nextInterval = { interval.left, interval.middle };
	}
	else {
		nextInterval = { interval.middle, interval.right };
	}
	
	result.iterQuantity++;
	result.mediatePoints.push_back(desiredPoint);
	dychotomicSearch(nextInterval, result, precision, desiredFun);
}
