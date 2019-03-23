#ifndef _ELMA_ROBOT_SHIELD_H
#define _ELMA_ROBOT_SHIELD_H

#include "robot.h"

namespace robot {

    using namespace std::chrono;
    using namespace elma;

    class Robot;  // Declare containing class so it can be refered to here
                      // before it is defined in robot.h 

    //! The shield state of the robot
    class ShieldState : public State {        

        public:
        //! Build a new shield state
        ShieldState() : State("shield") {}
        void entry(const Event& e) {}
        void during() {}

        //! \param e The event that triggered the transition        
        void exit(const Event&);

        Robot& robot();        

    };

}

#endif