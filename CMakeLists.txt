cmake_minimum_required(VERSION 3.5)

project(hw-003 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)

if(ANDROID)
  add_library(hw-003 SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.hpp
    mainwindow.ui
    header.hpp
  )
else()
  add_executable(hw-003
    main.cpp
    mainwindow.cpp
    mainwindow.hpp
    mainwindow.ui
    header.hpp
    rc.qrc
    sportmenmodel.hpp sportmenmodel.cpp
    databasemanager.hpp databasemanager.cpp
    sportmenmodel.hpp sportmenmodel.cpp

  )
endif()

target_link_libraries(hw-003 PRIVATE Qt5::Widgets Qt5::Sql)
target_link_libraries(hw-003 PRIVATE Qt5::Core)
target_link_libraries(hw-003 PRIVATE Qt5::Core)
target_link_libraries(hw-003 PRIVATE Qt5::Core)
target_link_libraries(hw-003 PRIVATE Qt5::Core)
