#include <ChaosGame.h>
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    ChaosGame chaosGame;
    chaosGame.nextIteration();

    for (auto [x, y] : chaosGame.getPoints()) {
        std::cout << "Point x: " << x << " - y: " << y << std::endl;
    }

    return 0;
}
