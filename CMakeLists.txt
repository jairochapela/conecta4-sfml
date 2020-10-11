cmake_minimum_required(VERSION 3.0.0)
project(conecta4 VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML 2.5 REQUIRED network audio graphics window system)

add_executable(conecta4 main.cpp Tablero.cpp Jugador.cpp)
target_link_libraries(${PROJECT_NAME} sfml-window sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
