#include <unistd.h>
#include <iostream>
#include <string>
#include "robot.h"


using namespace robot;

//bool drawn = false;

UserInterface::UserInterface(Robot& rob) : Process("user input"), _robot(rob) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};


void UserInterface::show_robot(){
    int robPosX = 11;
    int robPosY = 9;
    //create overarching robot window so it is easy to deploy shield.
    WINDOW *robotWin = newwin(10,11,robPosY,robPosX);
    if (_robot.shieldStatus()){
        box(robotWin,'|','-');
    }
    //create bottom part of robot
    WINDOW *robBot = derwin(robotWin,2,9,8,1);
    box(robBot,'|','-');

    if (_robot.isOn()){
        //create middle part of robot
        WINDOW *robMid = derwin(robotWin,3,5,6,3);
        box(robMid,'|','-');

        //create top part of robot
        WINDOW *robTop = derwin(robotWin,2,3,5,4);
        box(robTop,'|','-');
    }

    //refresh robot window and every subwindow inside of it.
    wsyncup(robotWin);
    wrefresh(robotWin);
}

void UserInterface::show_path(){
    int pathLength = 18;
    //create left and right path barrier windows
    WINDOW *leftPathWin = newwin(pathLength,1,1,1);
    WINDOW *rightPathWin = newwin(pathLength,1,1,30);
    
    if(!_robot.flagStatus()){
        for (int i = 1; i < pathLength*2; i++){
            //this path pattern indicates the robot is stopped
            waddch(leftPathWin,'|');
            waddch(leftPathWin,'-');
            waddch(rightPathWin,'|');
            waddch(rightPathWin,'-');
            i++;
        }
        
    }else{
        for (int i = 1;i < pathLength*2; i++){
            //this path pattern indicates the robot is moving
            waddch(leftPathWin,'|');
            waddch(rightPathWin,'|');
            i++;
        }
    }     
    //referesh left and right path windows
    wrefresh(leftPathWin);
    wrefresh(rightPathWin);
}

void UserInterface::show_enemy(){
    int enemyPosX = 12;
    int enemyPosY = 2;
    //create enemy window
    WINDOW *enemyWin = newwin(5,7,enemyPosY,enemyPosX);
    if (_robot.enemyStatus() && !_timerVal){
        //drawing stick figure
        wmove(enemyWin,1, 1);
        waddch(enemyWin,' ');
        waddch(enemyWin,' ');
        waddch(enemyWin,'0');
        waddch(enemyWin,' ');
        waddch(enemyWin,' ');
        wmove(enemyWin,2, 1);
        waddch(enemyWin,'<');
        waddch(enemyWin,'-');
        waddch(enemyWin,'|');
        waddch(enemyWin,'-');
        waddch(enemyWin,'>');
        wmove(enemyWin,3, 1);
        waddch(enemyWin,' ');
        waddch(enemyWin,'/');
        waddch(enemyWin,' ');
        waddch(enemyWin,'\\');
        waddch(enemyWin,' ');
        wrefresh(enemyWin);
        
    }
    else{
        //have to clear the window and refresh it when condition isnt met
        //so that when it dissapears the window reflects it
        wclear(enemyWin);
        wrefresh(enemyWin);
    }
}


bool UserInterface::arrowTimer(high_resolution_clock::duration d){
    // timer to show the arrow for a short bit of time before dissapearing inicating arrow is moving
    if (std::chrono::duration_cast<std::chrono::seconds>(d).count() > .5 && _robot.arrowStatus()){
        _timerVal = true;
        // this ensures that the enemy actually dissapears when arrow times out.
        if (std::chrono::duration_cast<std::chrono::seconds>(d).count() > 1){
            _timerVal = false;
            _robot.enemyDissapeared();
        }
    }
    return _timerVal;
}

void UserInterface::show_arrow(){
    //create arrow window
    WINDOW *arrowWin = newwin(2,1,7,15);
    if (_robot.arrowStatus() && !_timerVal){
        //draw arrow 
        waddch(arrowWin,'^');
        waddch(arrowWin,'|');
        wrefresh(arrowWin);
    }
    else {
        //refresh arrow window
        wclear(arrowWin);
        wrefresh(arrowWin);
    }

}

void UserInterface::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();

    switch ( c ) {            
        case 'o':
            emit(Event("on"));
            break;
        case 'd':
            emit(Event("off"));
            clear(); // Clear the screen of old stuff
            break;
        case 'w':
            emit(Event("wander"));
            break;
        case 's':
            emit(Event("stop"));
            break;
        case 'q':
            std::cout << "halting\n";
            halt();
            break;
        case 'e':
            emit(Event("enemy"));
            break;
        case 'f':
            emit(Event("fire"));
            break;
    }

    // OUTPUT
    show_robot();  
    show_path();
    show_enemy();
    show_arrow();
    arrowTimer(_robot.timeValue());
    mvprintw(20,1,"on(o), off(d), wander(w), stop moving(s), quit(q), Release enemy(e)");
        // we want the fire prompt to show up only after the enemy appears
    if(_robot.enemyStatus()){
        mvprintw(21,1,"Press (f) to fire an arrow at the enemy!");
    }
    for ( int i=0; i<_robot.addEvents().size(); i++ ) {
        mvprintw(23+i, 1, "Event: %s", _robot.addEvents()[i].c_str());
    }

    // NOTE: Since the program is running every 10 ms, we should sleep
    //       the ui to give processing time back to the OS. It is debatable
    //       whether this is the right place to put this. It could also become
    //       an Elma feature, or it could go in the StopWatch class, etc.
    //       The number 9999 should also be a parameter and not a constant.
    usleep(9999);
    //processor still sounds like its working really hard when I compile and especially 
    //when I run muy code, not sure if that is due to the elma docker image or not.
}