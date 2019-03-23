#include <chrono>
#include <vector>

#include "robot.h"

using namespace std::chrono;
using namespace elma;
using namespace robot;

Robot::Robot() : StateMachine("robot") {

    // Define state machine initial states and transitions here
    set_initial(off);
    set_propagate(false);
    add_transition("on", off, on);          
    add_transition("off", wander, off);
    add_transition("off", on, off);
    add_transition("off",stop,off);
    add_transition("wander",on,wander);
    add_transition("wander",stop,wander);
    add_transition("stop",wander,stop);
    add_transition("enemy",wander,shield);
    add_transition("enemy",on,shield);
    add_transition("enemy",off,shield);
    add_transition("enemy",stop,shield);
    add_transition("fire",shield,fire);
    add_transition("wander",fire,wander);
    add_transition("off",fire,off);
    add_transition("enemy",fire,shield);
}


void Robot::turnOn() {
   _isOn = true;
   string currE = "Robot turned on";
   addEvent(currE);
}

void Robot::turnOff() {
   _isOn = false;
   _pathFlag = false;
   _shieldOn = false;
   string currE = "Robot turned off";
   addEvent(currE);
}

void Robot::wandering(){
    _pathFlag = true;
    _shieldOn = false;
    string currE = "Robot started wandering";
    addEvent(currE);
}

void Robot::stopWandering(){
    _pathFlag = false;
    string currE = "Robot stopped moving";
    addEvent(currE);
}

void Robot::engageShield(){
    _shieldOn = true;
    string currE = "Robot engaged shield";
    addEvent(currE);
}

void Robot::fireArrow(){
    _start_time = high_resolution_clock::now();
    _arrowFired = true;
    _shieldOn = false;
    string currE = "Robot fired arrow at enemy!";
    addEvent(currE);
}

void Robot::addEvent(string str) {
    //add string event to vector
    _currEvents.push_back(str);
}

high_resolution_clock::duration Robot::timeValue() {
    return high_resolution_clock::now() - _start_time;
}

void Robot::enemyAppeared(){
     _enemy = true;
     _arrowFired = false;
}

void Robot::enemyDissapeared(){
    _enemy = false;
    _arrowFired = false;
}


// Getters for UI
bool Robot::flagStatus(){
    return _pathFlag;
}

bool Robot::isOn(){
    return _isOn;
}

bool Robot::enemyStatus(){
    return _enemy;
}

bool Robot::shieldStatus(){
    return _shieldOn;
}

bool Robot::arrowStatus(){
    return _arrowFired;
}

