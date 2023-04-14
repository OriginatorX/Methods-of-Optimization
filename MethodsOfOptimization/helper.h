#pragma once

#include <set>
#include <functional>

struct Interval {
	Interval(const double left = 0.0, const double right = 0.0);

	double left;
	double right;
	double len;
	double middle;
};

struct Point {
	Point(const double point = 0.0, const double value = 0.0);

	double point;
	double value;
};

struct Computation {
	Computation(const Point& point = Point{}, const size_t counter = 0);

	Point point;
	size_t iterQuantity;
	std::vector<Point> mediatePoints;
};

using pair = std::pair<double, double>;
using function = std::function<double(double)>;
using optimFunTy = std::function<void(const Interval&, Computation&, const double, function)>;

struct FuncParams {

	FuncParams(
		const Interval& interval, 
		const double precision, 
		function desiredFun
	);

	Interval interval;
	double precision;
	function desiredFun;
};

void optimize(const std::vector<optimFunTy>& functions, const FuncParams& params);
Point min(const Point& first, const Point& second);
void printPoint(const Computation& result, const double executionTime, const int32_t precision = 16);
double length(const pair& interval);
double midOfInterval(const pair& interval);
double fibItem(size_t N);
size_t iterQuantity(const Interval& interval, const double limit);
double boundItemOfSeq(const Interval& interval, const double precision);
std::vector<int64_t>& fibSequence(const std::pair<int64_t, int64_t>& twoSeqItems, const int64_t limit);