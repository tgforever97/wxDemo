cmake_minimum_required(VERSION 3.16)
project(wxTestDemo)

set(CMAKE_CXX_STANDARD 17)

#-------------------------------------
#  wxwidgets settings
#-------------------------------------
#-------------------------------------
#  wxwidgets settings
#-------------------------------------
if (UNIX)
    find_package(wxWidgets REQUIRED COMPONENTS net core base)
    include(${wxWidgets_USE_FILE})
else ()
    find_path(WXWIDGET_INCLUDE_DIR msvc/wx/setup.h)
    #set(WXWIDGET_INCLUDE_DIR "E:/soft/wsWidgets/wxWidgets-3.1.3/include")
    #wxWidget官网下载的dev里的lib文件位置
    #其实是32位的位置，后期进行修改
    find_path(WXWIDGET_LIBRARY_DIR vc_x64_lib)
    #set(WXWIDGET_LIBRARY_DIR "E:/soft/wsWidgets/wxWidgets-3.1.3/lib/vc_x64_lib")

    set(WXWIDGET_INCLUDE_MSVC_DIR ${WXWIDGET_INCLUDE_DIR}/msvc)
    #directshow的头文件位置
    find_path(DIRCTSHOW_INCLUDE_DIR amfilter.h)
    find_library(DIRECTSHOW_LIBRARY strmiids)
endif ()

add_executable(wxTestDemo src/BlueSideApp.cpp src/BlueSide.cpp src/BlueSideCallerPage.cpp
        src/BlueSideMeetingPage.cpp src/test.cpp)

if(UNIX)
    target_include_directories(${PROJECT_NAME}
            PRIVATE
            ${PROJECT_SOURCE_DIR}/include
            )

    target_link_libraries(${PROJECT_NAME}
            PRIVATE
            ${wxWidgets_LIBRARIES}
            ${WXWIDGET_LIBRARY_DIR}
            )
else()
    target_include_directories(${PROJECT_NAME}
            PRIVATE
            ${PROJECT_SOURCE_DIR}/include
            ${WXWIDGET_INCLUDE_DIR}
            ${WXWIDGET_INCLUDE_DIR}/msvc
            )

    target_link_libraries(${PROJECT_NAME}
            PRIVATE
            wxbase31ud_net.lib
            wxbase31ud_xml.lib
            wxexpatd.lib
            wxjpegd.lib
            wxmsw31ud_adv.lib
            wxmsw31ud_aui.lib
            wxmsw31ud_core.lib
            wxmsw31ud_gl.lib
            wxmsw31ud_html.lib
            wxmsw31ud_media.lib
            wxmsw31ud_propgrid.lib
            wxmsw31ud_qa.lib
            wxmsw31ud_ribbon.lib
            wxmsw31ud_richtext.lib
            wxmsw31ud_stc.lib
            wxmsw31ud_webview.lib
            wxmsw31ud_xrc.lib
            wxpngd.lib
            wxregexud.lib
            wxscintillad.lib
            wxtiffd.lib
            wxzlibd.lib
            )
endif()