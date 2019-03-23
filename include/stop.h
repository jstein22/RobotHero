#ifndef _ELMA_ROBOT_STOP_H
#define _ELMA_ROBOT_STOP_H

#include "robot.h"

namespace robot {

    using namespace std::chrono;
    using namespace elma;

    class Robot;  // Declare containing class so it can be refered to here
                      // before it is defined in robot.h 

    //! The stop state of the robot
    class StopState : public State {        

        public:
        //! Build a new stop state
        StopState() : State("stop") {}
        void entry(const Event& e) {}
        void during() {}

        //! \param e The event that triggered the transition        
        void exit(const Event&);

        Robot& robot();        

    };

}

#endif