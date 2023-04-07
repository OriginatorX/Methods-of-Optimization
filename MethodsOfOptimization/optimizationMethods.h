#pragma once

#include <functional>
#include "helper.h"

void uniformSearch(const Interval& interval, Computation& result, const double precision, function desiredFun);
void dychotomicSearch(const Interval& interval, Computation& result, const double precision, function desiredFun);
void fibSearch(const Interval& interval, Computation& result, const double precision, function desiredFun);
void goldenRatio(const Interval& interval, Computation& result, const double precision, function desiredFun);