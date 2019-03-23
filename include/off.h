#ifndef _ELMA_ROBOT_OFF_H
#define _ELMA_ROBOT_OFF_H

#include "robot.h"

namespace robot {

    using namespace std::chrono;
    using namespace elma;

    class Robot; // Declare containing class so it can be refered to here
                     // before it is defined in robot.h

    //! The off state of the robot
    class OffState : public State {

        public:
        //! Construct a new off state
        OffState() : State("off") {}
        void entry(const Event& e) {}
        void during() {}

        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        Robot& robot();

    };

}

#endif