cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME LogoMaker)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES states.cpp states.h snapshot.cpp snapshot.h
        snapshotInterface.cpp snapshotInterface.h mouseEvent.cpp mouseEvent.h
        history.cpp history.h eventHandler.cpp eventHandler.h main.cpp
        GUIComponent.cpp GUIComponent.h typingBox.cpp typingBox.h
        item.cpp item.h keyboardShortcut.cpp keyboardShortcut.h image.cpp image.h
        itemList.cpp itemList.h menu.cpp menu.h menuBar.cpp menuBar.h font.h font.cpp
        slider.cpp slider.h logoMaker.cpp logoMaker.h label.cpp label.h typing.cpp typing.h
        textInput.cpp textInput.h cursor.cpp cursor.h dropdownMenu.cpp dropdownMenu.h
        logoDisplay.cpp logoDisplay.h color.cpp color.h colorPicker.cpp colorPicker.h
        fileItem.cpp fileItem.h fileNode.cpp fileNode.h fileTree.cpp fileTree.h fileSelect.cpp fileSelect.h themeSelect.cpp themeSelect.h theme.cpp theme.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()