cmake_minimum_required(VERSION 3.20)
project(ConsoleTurnBasedCombat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleTurnBasedCombat)
target_include_directories(ConsoleTurnBasedCombat PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(ConsoleTurnBasedCombat PRIVATE
    src/main.cpp
    src/combat.cpp
    src/enemy.cpp
    src/firstCombat.cpp
    src/secondCombat.cpp
    src/thirdCombat.cpp
    src/typeText.cpp
    src/showIntro.cpp
    src/getName.cpp
    src/player.cpp
    src/consoleUtils.cpp
)
