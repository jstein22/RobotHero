#include <iostream>
#include <chrono>
#include <vector>

#include "robot.h"

using namespace std::chrono;
using namespace elma;
using namespace robot;

Robot&WanderState:: robot() { return (Robot&) state_machine(); }

void WanderState::exit(const Event& e) {
    if ( e.name() == "off" ) {
        // User told robot to wander
        robot().turnOff();
    } else if ( e.name() == "stop" ) {
        // User stops the robot from moving
        robot().stopWandering();
    } else if (e.name() == "enemy"){
        // enemy is detected
        string currE = "WARNING: ENEMY APPEARED";
        robot().addEvent(currE);
        robot().enemyAppeared();
        robot().stopWandering();
        robot().engageShield();
    }
}
