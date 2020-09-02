cmake_minimum_required(VERSION 3.10)
project(YaPokemon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "$HOME/Qt/5.15.0/clang_64")

# setup qt
find_package(Qt5 COMPONENTS Widgets Qml Quick Network REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# setup conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS KEEP_RPATHS)

add_library(libpokemon_core src/core/pokemon/PokemonTemplate.cc include/pokemon/PokemonTemplate.h include/common.h include/pokemon/Pokemon.h include/pokemon/PokemonInstance.h include/pokemon/Hexagon.h src/core/pokemon/Pokemon.cc include/pokemon/pokemons/eevee.h src/core/pokemon/pokemons/eevee.cc include/action/Action.h include/action/AttackAction.h include/types/pokemon.h include/types/move.h src/core/action/AttackAction.cc src/core/action/SpAttackAction.cc include/action/SpAttackAction.h include/buff/Buff.h include/move/Move.h include/move/moves/Bite.h src/core/move/moves/Bite.cc include/move/AttackMove.h src/core/move/AttackMove.cc src/core/pokemon/PokemonInstance.cc include/pokemon/def.h include/pokemon/pokemons/type_map.h src/core/pokemon/pokemons/pikachu.cc include/pokemon/pokemons/pikachu.h src/core/move/SpAttackMove.cc include/move/SpAttackMove.h src/core/move/moves/Thunder.cc include/move/moves/Thunder.h include/battle/Battle.h src/core/battle/Battle.cc include/buff/buffs/HexBuff.h src/core/buff/buffs/HexBuff.cc include/action/BufAction.h src/core/action/BufAction.cc include/move/BufMove.h src/core/move/BufMove.cc src/core/move/moves/Charge.cc include/move/moves/Charge.h include/buff/buffs/TypeActionBuff.h src/core/buff/buffs/TypeActionBuff.cc src/core/move/moves/RisingVoltage.cc include/move/moves/RisingVoltage.h src/core/pokemon/tools.cc src/core/common.cc)
add_executable(client src/app/client/main.cc qml.qrc)
add_executable(run_tests src/run_tests.cc tests/test_pokemon.cc tests/test_pokemoninstance.cc tests/test_battle.cc)
add_executable(terminal_demo src/terminal_demo.cc include/pokemon/tools.h)
add_executable(server src/app/server/main.cc)

target_include_directories(
        libpokemon_core
        PUBLIC
        "include"
)
target_link_libraries(libpokemon_core Qt5::Network)

target_link_libraries(run_tests libpokemon_core)
target_link_libraries(run_tests CONAN_PKG::gtest)

target_link_libraries(terminal_demo libpokemon_core)

target_link_libraries(client libpokemon_core)
target_link_libraries(client Qt5::Widgets Qt5::Qml Qt5::Quick Qt5::Network)

target_link_libraries(server libpokemon_core)
target_link_libraries(server Qt5::Core Qt5::Network)

add_test(test_all run_tests)
