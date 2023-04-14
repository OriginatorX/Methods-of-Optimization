#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <vector>

#include "helper.h"
#include "timer.h"

Interval::Interval(const double left, const double right)
    : left(left)
    , right(right)
    , len(length({ left, right }))
    , middle(midOfInterval({ left, right }))
{}

Point::Point(const double point, const double value)
    : point(point)
    , value(value)
{}

Computation::Computation(const Point& point, const size_t counter)
    : point(point)
    , iterQuantity(counter)
    , mediatePoints{}
{}

FuncParams::FuncParams(
    const Interval& interval, 
    const double precision, 
    function desiredFun
) 
    : interval(interval)
    , precision(precision)
    , desiredFun(desiredFun)
{}

void optimize(const std::vector<optimFunTy>& functions, const FuncParams& params) {
    for (auto& func : functions) {
        Computation result{};
        Timer timer{};
        func(params.interval, result, params.precision, params.desiredFun);
        double time = timer.elapsed();
        printPoint(result, time);
    }
}

Point min(const Point& first, const Point& second) {
    return first.value < second.value ? first : second;
}

void printPoint(const Computation& result, const double time, const int32_t precision) {
    std::cout.precision(16);
    int counter{1};
    for (auto& point : result.mediatePoints) {
        std::cout << counter << " Point: " << point.point <<  " : " << "Value: " << point.value << "\n";
        counter++;
    }
    std::cout << "Точка интервала: "            << result.point.point   << "\n"
        << "Значение функции в данной точке: "  << result.point.value   << "\n"
        << "Количество итераций: "              << result.iterQuantity  << "\n"
        << "Время выполнения: "                 << time                 << "\n"
        << "\n" << std::endl;
}

double length(const pair& interval) {
    return fabs(interval.first - interval.second);
}

double midOfInterval(const pair& interval) {
    const int32_t divider{ 2 }; //Divide interval on two same halves
    return interval.first + (length(interval) / divider);
}

double fibItem(size_t N) {
    const double tau{ .6180339887498949 };
    return (pow(1 / tau, N + 1) - pow(-tau, N + 1)) / sqrt(5);
}

size_t iterQuantity(const Interval& interval, const double precision) {
    size_t N = 0;
    double length{ interval.len / fibItem(N) };
    while (length >= precision) {
        length = interval.len / fibItem(N + 1);
        N++;
    }
    return N;
}

std::vector<int64_t> resSequence;

std::vector<int64_t>& fibSequence(
    const std::pair<int64_t, int64_t>& twoSeqItems,
    const int64_t limit)
{
    if (twoSeqItems.second >= limit) {
        return resSequence;
    }
   
    if (twoSeqItems.first == twoSeqItems.second) {
        resSequence.push_back(twoSeqItems.second);
    }
    resSequence.push_back(twoSeqItems.second);
    fibSequence(
        { twoSeqItems.second, twoSeqItems.first + twoSeqItems.second },
        limit
    );
}

double boundItemOfSeq(const Interval& interval, const double precision) {
    return static_cast<double>(interval.len / precision);
}
