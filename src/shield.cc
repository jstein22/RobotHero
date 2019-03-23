#include <iostream>
#include <chrono>
#include <vector>

#include "robot.h"

using namespace std::chrono;
using namespace elma;
using namespace robot;

Robot&ShieldState:: robot() { return (Robot&) state_machine(); }

void ShieldState::exit(const Event& e) {
    if ( e.name() == "fire" ) {
        // User told robot to wander
        robot().fireArrow();
    }
}
