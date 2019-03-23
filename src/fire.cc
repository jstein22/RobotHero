#include <iostream>
#include <chrono>
#include <vector>

#include "robot.h"

using namespace std::chrono;
using namespace elma;
using namespace robot;

Robot&FireState:: robot() { return (Robot&) state_machine(); }

void FireState::exit(const Event& e) {
    if ( e.name() == "wander" ) {
        // User turned off the robot
        robot().wandering();
    } else if ( e.name() == "off" ) {
        // robot turned off
        robot().turnOff();
    } else if (e.name() == "enemy"){
        // enemy is detected
        string currE = "WARNING: ENEMY APPEARED";
        robot().addEvent(currE);
        robot().enemyAppeared();
        robot().engageShield();
    }
}
