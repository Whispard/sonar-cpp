cmake_minimum_required(VERSION 3.20)
project(sonar_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
        fmtlib
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 8.0.1)
FetchContent_Declare(
        effolkronium_random
        GIT_REPOSITORY https://github.com/effolkronium/random.git
)
FetchContent_MakeAvailable(fmtlib effolkronium_random)

#add_library(randomizer )

add_executable(sonar_cpp src/main.cpp src/sonar.cpp src/board.cpp
        src/chest.cpp src/RandomGenerator.cpp
        src/cell.cpp include/Config.h include/Position.h
        include/Board.h include/Cell.h include/Chest.h include/RandomGenerator.h include/Sonar.h
        )
#
#add_library(utils src/cell.cpp include/Config.h include/Position.h)
#
#add_executable(sonar_cpp src/main.cpp src/sonar.cpp src/board.cpp
#        src/chest.cpp
#        include/Board.h include/Chest.h include/Sonar.h
#        )

target_link_libraries(sonar_cpp PRIVATE fmt::fmt effolkronium_random)


add_subdirectory(tests)
