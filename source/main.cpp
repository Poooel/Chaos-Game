#include <ChaosGame.h>
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    ChaosGame chaosGame;
    chaosGame.nextIteration();

    std::vector<Point> points = chaosGame.getPoints();

    for (Point point : points) {
        std::cout << "Point x: " << point.x << " - y: " << point.y << std::endl;
    }

    return 0;
}
