cmake_minimum_required(VERSION 3.30)
project(chex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
include_directories(include)

find_package(Qt5 COMPONENTS
        Core
        Widgets
        REQUIRED
)

qt5_add_resources(QT_RESOURCES resources/resources.qrc)

add_executable(chex
        src/main.cpp
        include/chexwindow.h
        src/chexwindow.cpp
        ${QT_RESOURCES}
)

target_link_libraries(chex
        Qt5::Core
        Qt5::Widgets
)

install(TARGETS chex
        RUNTIME DESTINATION bin
)

configure_file("chex.desktop.in" "${CMAKE_BINARY_DIR}/chex.desktop" @ONLY)
install(FILES "${CMAKE_BINARY_DIR}/chex.desktop" DESTINATION /usr/share/applications)

configure_file("ciphers.directory" "${CMAKE_BINARY_DIR}/ciphers.directory" @ONLY)
install(FILES "${CMAKE_BINARY_DIR}/ciphers.directory" DESTINATION /usr/share/desktop-directories)

install(FILES resources/chex-icon.svg DESTINATION /usr/share/icons/hicolor/scalable/apps)
install(FILES resources/ciphers-systems-icon.png DESTINATION /usr/share/icons/hicolor/scalable/apps)

install(FILES ciphers-systems.menu DESTINATION /etc/xdg/menus)

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY
)

add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_uninstall.cmake
)
