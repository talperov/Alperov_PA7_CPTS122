/*
Name: Anthony Alperov
Date: 10/27/25
Assingment: This is task PA7, goal of this assingment is to Attendace Tracker
with FOUR major requirments.
Requirment One: The application must import records pertaining to
each student registered for the course from a course list.
Requirment Two: The application must allow the user to mark each
student in the course as present or absent on any given day.
Requirment Three:The application must generate reports based on
criteria.
Requirment Four:The application must support a user interface to the
attendance tracker.
*/
#include "Menu.h"


int main()
{
    List<Data> masterList;
    Menu menu(masterList);  

    menu.App();
    return 0;
}