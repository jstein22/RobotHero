# ECE590FinalProject
Robot Hero is a project that implements the event loop manager Elma. The robot has states that are managed by Elma and
interacted with based on user input. The robot is a hero because the user may choose to unleash an enemy on the robot but
the robot can not be defeated. It is smart enough and quick enough to put up its shield as soon as an enemy is detected, and
has impeccable accuracy with its weaponry. The robot can fire an arrow at the enemy and will not miss. This repository contains all of the code needed for the program.


Project Goals Include:

- Extend the Finite State Machine Class that was developed in homework 7. 
- Add more states and transitions for the robot.
- robot will be able to defend itself against an enemy
- Use ncurses as a GUI for the robot simulation


The source code for this project is available on github.


## Installation

git clone https://github.com/jstein22/ECE590FinalProject.git
cd elma_project
docker run -v $PWD:/source -it klavins/elma:latest bash
make
make docs
Execution

To run the robot hero simulation, type

bin/robot_hero
The simulation is controlled via the keyboard, via these keys:

o: Turn robot on
d: Turn robot off
w: Robot starts wandering
s: Robot stops moving
q: Stop the simulation
e: Release an enemy

## Testing

To test the functionality of the simulation, run the simulation and interact with it by typing bin/robot_heo

## Architecture

Robot Hero was designed based off of the architecture in the stopwatch example. The majority of the classes were thought of based on the Homework that was worked on in week 7. The idea to add an intruder is what makes the robot a hero, because he needed areason to be a hero. 

The choice to make an arrow appear as if it were fired towards the enemy rather than just make the enemy dissapear was to add some realism to an otherwise dry project. I recognize that my skill level in software development is not the best, however I wanted to take on a few challenges with this project that would make me think. Working with ncurses proved to be quite the challenge in itself, but I wanted to spice things up by having something appear to move. Integrating a timer into the project was the perfect combination of a few concepts that we covered throughout the quarter. I would have liked to apply my timer philosphy to the robot to have the robot move when he was "wandering" rather than solely have the borders change however I found myself running out of time. 

I decided to adopt the organization philosophy that was outlined in the stopwatch project example that was provided on professor klaving git. This organization made so much more sense in my head than the way things were organized back in homework 7. I felt like I could have kept adding more and more functionality to the project because as I was building the project my confidence in my development skills kept getting stronger. 


## Results

Throughout the development of the project I decided to build it incrementally. I first started with just having a working on and off state of the robot. I quickly realized that having a working and responsive UI would make development much easier so I focused on creating string events to add to a list which I could display to the screen to understand what what was going on while I was developing. The program initializes to show just a box, however when it the user turns on the robot the robot evolves into its full form. From there the robot can wander until the user becomes bored and wants to release an enemy (or the enemy can be released right away). If the user decides to release an enemy before turning on the robot, the robot will turn itself on (with its innovative enemy detection scheme). The robot will always automatically deploy its shield when an enemy is detected. The only thing the robot can and will do when the enemy is there is to fire an arrow at the enemy to destroy it. This will then allow the robot to do anything it pleases again.



## Acknowledgements

I worked on my own on this project but talked about my pain points I found with Vlad and Avellino.

## References

A list of articles that assited in my development are shown below. The ncurses was where most of the help was needed. The rest of the help came from referencing the example project that was provided by Professor Klavins.

http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/printw.html
https://stackoverflow.com/questions/12549701/how-to-build-complex-graphics-using-ncurses

http://hughm.cs.ukzn.ac.za/~murrellh/os/notes/ncurses.html#output

https://invisible-island.net/ncurses/man/curs_initscr.3x.html

https://stackoverflow.com/questions/12549701/how-to-build-complex-graphics-using-ncurses
