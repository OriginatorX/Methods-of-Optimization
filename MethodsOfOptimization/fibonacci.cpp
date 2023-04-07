#include "helper.h"
#include "optimizationMethods.h"
#include <iostream>

void fibSearch(
    const Interval& interval,
    Computation& result,
    const double precision,
    function desiredFun)
{   
    size_t r{ result.iterQuantity + 1 }; // math notation for iterations counter
    static size_t N{ 1 }; // math notation for iterations number
    if (result.iterQuantity == 0) {
        N = iterQuantity(interval, precision);
    }
    
    const double firstPoint{
        interval.left + (interval.len * (fibItem(N - 1 - r) / fibItem(N + 1 - r)))
    };
    const double secondPoint{
        interval.left + (interval.len * (fibItem(N - r) / fibItem(N + 1 - r)))
    };
    const std::pair<Point, Point> pretendPoints{
        { firstPoint, desiredFun(firstPoint)   },
        { secondPoint, desiredFun(secondPoint) }
    };

    //Second step and completion
    Interval nextInterval{};
    if (result.iterQuantity == N - 1) {
        const double beta{ interval.len };
        double valueOfPretendPoint = desiredFun(pretendPoints.first.point + beta);

        nextInterval = (pretendPoints.second.value < valueOfPretendPoint
            ? Interval{ interval.left, pretendPoints.second.point }
            : Interval{ pretendPoints.second.point, interval.right }
        );
        result.point = Point{ nextInterval.middle, desiredFun(nextInterval.middle) };
        return;
    }

    nextInterval = (pretendPoints.first.value < pretendPoints.second.value
        ? Interval{ interval.left, pretendPoints.second.point }
        : Interval{ pretendPoints.first.point, interval.right }
    );
    
    result.iterQuantity++;
    result.mediatePoints.push_back(
        { interval.middle, desiredFun(interval.middle) }
    );
    fibSearch(nextInterval, result, precision, desiredFun);
}