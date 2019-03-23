#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "robot.h"

namespace robot {

    using namespace std::chrono;

    using namespace elma;

    using namespace robot;

    //! A user interface for the a StopWatch object
    class UserInterface : public Process {

        public:

        //! Create a new robot user interface using curses
        //! \param rob A reference to a robot object
        UserInterface(Robot& rob);

        void init() {}
        void start() {}

        //! Display the robot figure at the given x,y position on the screen
        void show_robot();

        void show_path();

        void show_enemy();

        void show_arrow();

        bool arrowTimer(high_resolution_clock::duration d);

        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        void stop() {}

        private:
        Robot& _robot;
        bool _timerVal = false;

    };

}