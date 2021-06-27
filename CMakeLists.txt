cmake_minimum_required(VERSION 3.17)
project(good_work)

set(CMAKE_CXX_STANDARD 14)
include_directories(lists)
add_executable(good_work main.cpp
        lists/CustomList.tpp lists/CustomList.h
        class_attendance_log/ClassAttendanceLogFacade.cpp class_attendance_log/ClassAttendanceLogFacade.h
        list/LinkedList.tpp list/LinkedList.h
        list/abstractions/Binary.h
        list/node/Node.tpp list/node/Node.h
        util/Date.cpp util/Date.h
        class_attendance_log/listener/Listener.cpp class_attendance_log/listener/Listener.h
        menu/Menu.h
        menu/MainMenu.cpp menu/MainMenu.h
        menu/IntTestMenu.cpp menu/IntTestMenu.h
        menu/DoubleTestMenu.cpp menu/DoubleTestMenu.h
        menu/LogTestMenu.cpp menu/LogTestMenu.h)