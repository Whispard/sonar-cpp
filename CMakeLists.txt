cmake_minimum_required(VERSION 3.20)
project(sonar_cpp)

set(CMAKE_CXX_STANDARD 20)


add_executable(sonar_cpp src/main.cpp src/Board.cpp src/Config.cpp src/Cell.cpp src/RandomGenerator.cpp src/Chest.cpp src/Sonar.cpp src/Position.cpp)
#target_link_libraries(main Catch2::Catch2WithMain)