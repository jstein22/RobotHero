#include <iostream>
#include <chrono>
#include <vector>

#include "robot.h"

using namespace std::chrono;
using namespace elma;
using namespace robot;

Robot&StopState:: robot() { return (Robot&) state_machine(); }

void StopState::exit(const Event& e) {
    if ( e.name() == "wander" ) {
        // User told robot to wander
        robot().wandering();
    } else if ( e.name() == "off" ) {
        // user turns robot off
        robot().turnOff();
    } else if (e.name() == "enemy"){
        // enemy is detected
        string currE = "WARNING: ENEMY APPEARED";
        robot().addEvent(currE);
        robot().enemyAppeared();
        robot().engageShield();
    }
}
