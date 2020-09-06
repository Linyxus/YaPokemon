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

add_library(libpokemon_core src/core/pokemon/PokemonTemplate.cc include/core/pokemon/PokemonTemplate.h include/core/common.h include/core/pokemon/Pokemon.h include/core/pokemon/PokemonInstance.h include/core/pokemon/Hexagon.h include/core/pokemon/pokemons/eevee.h src/core/pokemon/pokemons/eevee.cc include/core/action/Action.h include/core/action/AttackAction.h include/core/types/pokemon.h include/core/types/move.h src/core/action/AttackAction.cc src/core/action/SpAttackAction.cc include/core/action/SpAttackAction.h include/core/buff/Buff.h include/core/move/Move.h include/core/move/moves/Bite.h src/core/move/moves/Bite.cc include/core/move/AttackMove.h src/core/move/AttackMove.cc src/core/pokemon/PokemonInstance.cc include/core/pokemon/def.h include/core/pokemon/pokemons/type_map.h src/core/pokemon/pokemons/pikachu.cc include/core/pokemon/pokemons/pikachu.h src/core/move/SpAttackMove.cc include/core/move/SpAttackMove.h src/core/move/moves/Thunder.cc include/core/move/moves/Thunder.h include/core/battle/Battle.h src/core/battle/Battle.cc include/core/buff/buffs/HexBuff.h src/core/buff/buffs/HexBuff.cc include/core/action/BufAction.h src/core/action/BufAction.cc include/core/move/BufMove.h src/core/move/BufMove.cc src/core/move/moves/Charge.cc include/core/move/moves/Charge.h include/core/buff/buffs/TypeActionBuff.h src/core/buff/buffs/TypeActionBuff.cc src/core/move/moves/RisingVoltage.cc include/core/move/moves/RisingVoltage.h src/core/pokemon/tools.cc src/core/common.cc src/core/move/moves/SwordsDance.cc include/core/move/moves/SwordsDance.h src/core/move/moves/GigaImpact.cc include/core/move/moves/GigaImpact.h src/core/pokemon/pokemons/zacian.cc include/core/pokemon/pokemons/zacian.h src/core/move/moves/QuickGuard.cc include/core/move/moves/QuickGuard.h src/core/move/moves/SacredBlade.cc include/core/move/moves/SacredBlade.h src/core/move/moves/DragonDance.cc include/core/move/moves/DragonDance.h src/core/move/moves/DragonDart.cc include/core/move/moves/DragonDart.h src/core/move/moves/LastResort.cc include/core/move/moves/LastResort.h src/core/pokemon/pokemons/dragapult.cc include/core/pokemon/pokemons/dragapult.h src/core/move/moves/IronDefense.cc include/core/move/moves/IronDefense.h src/core/pokemon/pokemons/zamazenta.cc include/core/pokemon/pokemons/zamazenta.h src/core/move/moves/FlameWheel.cc include/core/move/moves/FlameWheel.h src/core/move/moves/FireThrower.cc include/core/move/moves/FireThrower.h src/core/pokemon/pokemons/arcanine.cc include/core/pokemon/pokemons/arcanine.h src/core/move/moves/BellyDrum.cc include/core/move/moves/BellyDrum.h src/core/action/HealAction.cc include/core/action/HealAction.h src/core/move/moves/BodySlam.cc include/core/move/moves/BodySlam.h src/core/pokemon/pokemons/snorlax.cc include/core/pokemon/pokemons/snorlax.h src/core/move/moves/Sleep.cc include/core/move/moves/Sleep.h src/core/move/moves/IceBeam.cc include/core/move/moves/IceBeam.h src/core/pokemon/pokemons/duraludon.cc include/core/pokemon/pokemons/duraludon.h src/core/move/moves/Outrage.cc include/core/move/moves/Outrage.h src/core/move/moves/DragonClaw.cc include/core/move/moves/DragonClaw.h src/core/pokemon/pokemons/haxorus.cc include/core/pokemon/pokemons/haxorus.h src/core/move/moves/Pluck.cc include/core/move/moves/Pluck.h src/core/move/moves/DrillPeck.cc include/core/move/moves/DrillPeck.h src/core/pokemon/pokemons/corviknight.cc include/core/pokemon/pokemons/corviknight.h src/core/move/moves/Inferno.cc include/core/move/moves/Inferno.h src/core/pokemon/pokemons/charizard.cc include/core/pokemon/pokemons/charizard.h src/core/move/moves/GigaDrain.cc include/core/move/moves/GigaDrain.h src/core/move/moves/SweetScent.cc include/core/move/moves/SweetScent.h src/core/pokemon/pokemons/vileplume.cc include/core/pokemon/pokemons/vileplume.h src/core/move/moves/Brine.cc include/core/move/moves/Brine.h src/core/move/moves/RainDance.cc include/core/move/moves/RainDance.h src/core/move/moves/PerishSong.cc include/core/move/moves/PerishSong.h src/core/buff/buffs/DeathBuff.cc include/core/buff/buffs/DeathBuff.h src/core/pokemon/pokemons/lapras.cc include/core/pokemon/pokemons/lapras.h src/core/move/moves/SheerCold.cc include/core/move/moves/SheerCold.h src/core/move/moves/Mimic.cc include/core/move/moves/Mimic.h src/core/pokemon/pokemons/ditto.cc include/core/pokemon/pokemons/ditto.h)
add_library(libyadb include/yadb/Yadb.h src/yadb/Yadb.cc include/yadb/Subset.h src/yadb/Subset.cc)
add_executable(client src/app/client/main.cc qml.qrc include/server/Jwt.h include/client/PokemonClient.h src/client/PokemonClient.cc include/client/ClientModel.h src/client/ClientModel.cc)
add_executable(run_tests src/run_tests.cc tests/test_pokemon.cc tests/test_pokemoninstance.cc tests/test_battle.cc tests/test_yadb.cc)
add_executable(terminal_demo src/terminal_demo.cc include/core/pokemon/tools.h)
add_executable(server src/app/server/main.cc include/server/PokemonServer.h src/server/PokemonServer.cc src/server/Jwt.cc include/server/BattleHistory.h src/server/BattleHistory.cc)

target_include_directories(
        libpokemon_core
        PUBLIC
        "include/core"
)
target_link_libraries(libpokemon_core Qt5::Network)

target_include_directories(
        libyadb
        PUBLIC
        "include/yadb"
)
target_link_libraries(libyadb Qt5::Core CONAN_PKG::nlohmann_json)

target_link_libraries(run_tests libpokemon_core)
target_link_libraries(run_tests libyadb)
target_link_libraries(run_tests CONAN_PKG::gtest)

target_link_libraries(terminal_demo libpokemon_core)

target_link_libraries(client libpokemon_core)
target_link_libraries(client CONAN_PKG::nlohmann_json)
target_link_libraries(client Qt5::Core Qt5::Widgets Qt5::Qml Qt5::Quick Qt5::Network)

target_link_libraries(server libpokemon_core)
target_link_libraries(server CONAN_PKG::nlohmann_json)
target_link_libraries(server Qt5::Core Qt5::Network)
target_link_libraries(server libyadb)

add_test(test_all run_tests)
