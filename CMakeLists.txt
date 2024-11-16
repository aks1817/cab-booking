cmake_minimum_required(VERSION 3.10)
project(CabBookingSystem)  # Project name

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/controllers
    ${CMAKE_SOURCE_DIR}/database
    ${CMAKE_SOURCE_DIR}/model
    ${CMAKE_SOURCE_DIR}/strategies
)

# Only the main.cpp file needs to be listed here since everything else is in headers
set(SOURCES
    main.cpp
)

# Create executable from the main.cpp file
add_executable(cab_booking_system ${SOURCES})

# Link libraries if required
# target_link_libraries(cab_booking_system <library_name>)
