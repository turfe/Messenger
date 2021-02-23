cmake_minimum_required(VERSION 3.17)
project(messenger)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(SFML_ROOT_DIR "~/lib/sfml")
set(SFML_DIR "${SFML_ROOT_DIR}/lib/cmake/SFML")

find_package(SFML REQUIRED system window graphics network audio)

set(SFML_LIBRARIES sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

message(STATUS "SFML libraries: ${SFML_LIBRARIES}")

include_directories(inception)

add_executable(messenger
        #        encoder_decoder/decoder.cpp
        #        encoder_decoder/encoder.cpp
        #        encoder_decoder/user.hpp
        inception/global_variables.hpp
        inception/paint.cpp
        inception/paint.hpp
        inception/personal_settings.hpp)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
