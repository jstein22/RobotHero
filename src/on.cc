#include <iostream>
#include <chrono>
#include <vector>

#include "robot.h"

using namespace std::chrono;
using namespace elma;
using namespace robot;

Robot&OnState:: robot() { return (Robot&) state_machine(); }

void OnState::exit(const Event& e) {
    if ( e.name() == "off" ) {
        // User turned off the robot
        robot().turnOff();
    } else if ( e.name() == "wander" ) {
       // robot starts wandering
        robot().wandering();
    } else if (e.name() == "enemy"){
        // enemy is detected
        string currE = "WARNING: ENEMY APPEARED";
        robot().addEvent(currE);
        robot().enemyAppeared();
        robot().engageShield();
    }
}
