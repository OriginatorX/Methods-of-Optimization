#include <iostream>

#include "optimizationMethods.h"

Point mediateResult{};

void goldenRatio(
	const Interval& interval, 
	Computation& result,
	const double precision, 
	function desiredFun
) {
	const double tau{ .6180339887498949 };

	if (interval.len <= precision) {
		result.point = mediateResult;
		return;
	}

	const double firstPoint{ 
		interval.right - (interval.right - interval.left) * tau 
	};
	const double secondPoint{ 
		interval.left + (interval.right - interval.left) * tau 
	};

	const std::pair<Point, Point> pretendPoints{
		{ firstPoint, desiredFun(firstPoint)   },
		{ secondPoint, desiredFun(secondPoint) }
	};

	Interval nextInterval{};
	if (pretendPoints.first.value < pretendPoints.second.value) {
		mediateResult = pretendPoints.second;
		nextInterval = { interval.left, pretendPoints.second.point };
	}
	else {
		mediateResult = pretendPoints.first;
		nextInterval = { pretendPoints.first.point, interval.right };
	}

	result.iterQuantity++;
	result.mediatePoints.push_back(mediateResult);
	goldenRatio(nextInterval, result, precision, desiredFun);
}
