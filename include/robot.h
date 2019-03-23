#ifndef _ELMA_ROBOT_H
#define _ELMA_ROBOT_H

#include "elma/elma.h" // Note installation directory for elma

#include "on.h"
#include "off.h"
#include "wander.h"
#include "stop.h"
#include "shield.h"
#include "fire.h"
#include "user_interface.h"

namespace robot {

    using namespace std::chrono;
    using namespace elma;    

    //! A robot class, that inherits from StateMachine
    class Robot : public StateMachine {


        public:
        //! Make a new robot
        Robot();

        //! turn on the robot
        void turnOn();

        //! turn off the robot
        void turnOff();

        //! robot begins wandering
        void wandering();

        //! robot stops wandering
        void stopWandering();

        //! robot turns on shield
        void engageShield();

        //! robot fires an arrow at enemy
        void fireArrow();

        //! changes status of enemy and arrowfired
        void enemyDissapeared();

        //! add event to array list of events that have occured
        void addEvent(string str);


        //! getter method to retrieve whether path should be moving or not
        bool flagStatus();

        //! getter method to retrieve on status
        bool isOn();

        //! getter method to retrieve status of whether an enemy appeared
        void enemyAppeared();

        //! getter method to retrieve status of the enemy
        bool enemyStatus();

        //! getter method to retrieve shield status
        bool shieldStatus();

        //! getter method to retrieve status of arrow
        bool arrowStatus();

        //! getter method to retrieve status specific of 
        

        //! Get the time once the arrow has been fired
        high_resolution_clock::duration timeValue();

       //! Get the list of Events
       const vector<string>& addEvents() { return _currEvents; }

        
        private:

        // When overriding the StateMachine class, put state declarations here.
        OnState on;
        OffState off;
        WanderState wander;
        StopState stop;
        ShieldState shield;
        FireState fire;

        // Other private variables
        bool _running;
        high_resolution_clock::time_point _start_time;
        high_resolution_clock::duration _elapsed;
        vector<string> _currEvents;
        bool _pathFlag;
        bool _isOn = false;
        bool _enemy = false;
        bool _shieldOn = false;
        bool _arrowFired = false;
    };

}

#endif