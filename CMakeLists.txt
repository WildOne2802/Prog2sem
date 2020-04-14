cmake_minimum_required(VERSION 3.14)
project(programming)

set(ENV{PKG_CONFIG_PATH} "/usr/local/opt/libffi/lib/pkgconfig:/usr/local/opt/libxml2/lib/pkgconfig")
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Wno-deprecated )

add_executable(programming "Lab4/PROGTASK4_6.cpp" "Lab4/task4_6.cpp" "Lab4/task4_6.h")
add_executable(Lab5 "Lab5/main.cpp" "Lab5/BaseCObject.hpp" "Lab5/CVector2D.hpp" "Lab5/IDialogInitable.hpp" "Lab5/IGeoFig.hpp" "Lab5/IPhysObject.hpp" "Lab5/IPrintable.hpp" "Lab5/Trapeze.cpp" "Lab5/Trapeze.hpp" "Lab5/Circle.hpp" "Lab5/Circle.cpp" "Lab5/System.cpp" "Lab5/System.hpp")
add_executable(Lab67 "Lab 6,7/main.cpp" "Lab 6,7/matrix.h")
add_executable(Lab8 "Lab 8/main.cpp")


add_executable(Lab9 "Lab 9/main.cpp")

find_package(PkgConfig REQUIRED)
pkg_search_module(LibXML++ REQUIREED libxml++-2.6)

include_directories(${LibXML++_INCLUDE_DIRS})

target_link_libraries(Lab8 ${LibXML++_LIBRARIES})



add_executable(lab10.1 "Lab 10.1/Lab10.cpp")