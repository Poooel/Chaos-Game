#include "ChaosGame.h"

ChaosGame::ChaosGame(int width, int height)
    : _randomNumberGenerator(_randomDevice()),
      _uniformDistribution(_lowerBound, _upperBound) {
    //   b
    //  / \
    // a---c
    int tenthWidth  = width / 10;
    int tenthHeight = height / 10;

    Point a = { tenthWidth, 9 * tenthHeight };
    Point b = { 5 * tenthWidth, tenthHeight };
    Point c = { 9 * tenthWidth, 9 * tenthHeight };

    _startingPoints.push_back(a);
    _startingPoints.push_back(b);
    _startingPoints.push_back(c);

    _points.push_back(a);
    _points.push_back(b);
    _points.push_back(c);

    _diceToPoints[1] = a;
    _diceToPoints[2] = a;
    _diceToPoints[3] = b;
    _diceToPoints[4] = b;
    _diceToPoints[5] = c;
    _diceToPoints[6] = c;

    Point startingPoint = getMidPoint(a, b);
    _points.push_back(startingPoint);
}

void ChaosGame::nextIteration() {
    Point currentPoint = _points.back();
    int   rolledDice   = getRandomNumber();
    Point towardsTo    = _diceToPoints[rolledDice];
    Point midPoint     = getMidPoint(currentPoint, towardsTo);
    _points.push_back(midPoint);
}

const std::vector<Point>& ChaosGame::getPoints() {
    return _points;
}

int ChaosGame::getRandomNumber() {
    return static_cast<int>(_uniformDistribution(_randomNumberGenerator));
}

Point ChaosGame::getMidPoint(const Point& a, const Point& b) {
    const int midPointX = (a.x + b.x) / 2;
    const int midPointY = (a.y + b.y) / 2;
    return { midPointX, midPointY };
}
