cmake_minimum_required(VERSION 3.20)
project(sonar_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
#

#add_executable(sonar_cpp src/main.cpp src/Board.cpp src/Config.cpp src/Cell.cpp src/RandomGenerator.cpp src/Chest.cpp src/Sonar.cpp src/Position.cpp include/Board.h include/Cell.h include/Chest.h include/Sonar.h include/RandomGenerator.h)
#add_executable(sonar_cpp src/main.cpp)
add_executable(sonar_cpp src/main.cpp src/sonar.cpp src/board.cpp
        src/chest.cpp
        src/cell.cpp include/Config.h include/Position.h
        include/Board.h include/Cell.h include/Chest.h include/RandomGenerator.h include/Sonar.h

        )

#add_executable(sonar_cpp
#        src/cell.cpp src/config.cpp src/position.cpp
#         src/chest.cpp  src/board.cpp src/sonar.cpp src/main.cpp)


#target_link_libraries(main Catch2::Catch2WithMain)