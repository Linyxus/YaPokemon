cmake_minimum_required(VERSION 3.17)
project(pokemon_core)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_library(libpokemon_core src/pokemon/PokemonTemplate.cc include/pokemon/PokemonTemplate.h include/common.h include/pokemon/Pokemon.h include/pokemon/PokemonInstance.h include/pokemon/Hexagon.h src/pokemon/Pokemon.cc include/pokemon/pokemons/eevee.h src/pokemon/pokemons/eevee.cc include/action/Action.h include/action/AttackAction.h include/types/pokemon.h include/types/move.h src/action/AttackAction.cc src/action/SpAttackAction.cc include/action/SpAttackAction.h include/buff/Buff.h include/move/Move.h include/move/moves/Bite.h src/move/moves/Bite.cc include/move/AttackMove.h src/move/AttackMove.cc src/pokemon/PokemonInstance.cc include/pokemon/def.h include/pokemon/pokemons/type_map.h src/pokemon/pokemons/pikachu.cc include/pokemon/pokemons/pikachu.h src/move/SpAttackMove.cc include/move/SpAttackMove.h src/move/moves/Thunder.cc include/move/moves/Thunder.h include/battle/Battle.h src/battle/Battle.cc include/buff/buffs/HexBuff.h src/buff/buffs/HexBuff.cc include/action/BufAction.h src/action/BufAction.cc include/move/BufMove.h src/move/BufMove.cc src/move/moves/Charge.cc include/move/moves/Charge.h include/buff/buffs/TypeActionBuff.h src/buff/buffs/TypeActionBuff.cc src/move/moves/RisingVoltage.cc include/move/moves/RisingVoltage.h src/pokemon/tools.cc src/common.cc )

target_include_directories(
        libpokemon_core
        PUBLIC
        "include"
)

add_executable(run_test src/main.cc tests/test_pokemon.cc tests/test_pokemoninstance.cc tests/test_battle.cc)

add_executable(demo src/demo.cc include/pokemon/tools.h)

target_link_libraries(run_test libpokemon_core)

target_link_libraries(run_test CONAN_PKG::gtest)

add_test(test_all run_test)

target_link_libraries(demo libpokemon_core)
