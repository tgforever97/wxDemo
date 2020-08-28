cmake_minimum_required(VERSION 3.16)
project(wxTestDemo)

set(CMAKE_CXX_STANDARD 17)

#-------------------------------------
#  wxwidgets settings
#-------------------------------------
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(wxTestDemo src/BlueSideApp.cpp src/BlueSide.cpp src/BlueSideCallerPage.cpp
        src/BlueSideMeetingPage.cpp src/test.cpp)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${wxWidgets_LIBRARIES}
        ${WXWIDGET_LIBRARY_DIR}
        )
