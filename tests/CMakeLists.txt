FetchContent_Declare(
        catch
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.6
)

FetchContent_MakeAvailable(catch)

add_executable(testlib testlib.cpp
         ../src/sonar.cpp ../src/board.cpp
        ../src/chest.cpp
        ../src/cell.cpp ../include/Config.h ../include/Position.h
        ../include/Board.h ../include/Cell.h ../include/Chest.h ../include/RandomGenerator.h ../include/Sonar.h)

target_link_libraries(testlib PRIVATE Catch2::Catch2)

add_test(NAME testlibtest COMMAND testlib)