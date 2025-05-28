cmake_minimum_required(VERSION 3.10)
project(MySFMLProject)

# Установите стандарт C++ (SFML требует C++11 или новее)
set(CMAKE_CXX_STANDARD 17)

# Поиск SFML
find_package(SFML 2.6 COMPONENTS graphics window audio system REQUIRED)

add_executable(Mario
    main.cpp
    Enemy.cpp
    Enemy.hpp
    Player.cpp
    Player.hpp
    StartGame.cpp
    StartGame.hpp
)

# Подключение SFML
target_link_libraries(Mario PRIVATE
    sfml-graphics
    sfml-window
    sfml-audio
    sfml-system
)
