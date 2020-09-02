//
// Created by Yichen Xu on 2020/8/29.
//

#include <pokemon/Pokemon.h>
#include <pokemon/pokemons/eevee.h>
#include <gtest/gtest.h>
#include <memory>
using namespace std;

TEST(PokemonTest, NameWorks) {
    Pokemon *pokemon = new PokemonOf<Eevee>;

    ASSERT_STREQ("伊布", pokemon->name().c_str());
}

TEST(PokemonTest, LearnAndLevelWorks) {
    PokemonOf<Eevee> pokemon;
    ASSERT_EQ(pokemon.level(), 0);
    pokemon.learn(10);
    ASSERT_EQ(pokemon.level(), 0);
    pokemon.learn(40);
    ASSERT_EQ(pokemon.level(), 1);
    pokemon.learn(700);
    ASSERT_EQ(pokemon.level(), 15);
    pokemon.learn(700);
    ASSERT_EQ(pokemon.level(), 15);
}

TEST(PokemonTest, GrowthWorks) {
    PokemonOf<Eevee> pokemon;
    ASSERT_EQ(pokemon.max().hp, 10);
    pokemon.learn(50);
    ASSERT_EQ(pokemon.max().hp, 12);
    pokemon.learn(700);
    ASSERT_EQ(pokemon.max().hp, 40);
}

TEST(PokemonTest, PolyWorks) {
    shared_ptr<Pokemon> pokemon = make_shared<PokemonOf<Eevee>>();
    ASSERT_STREQ("伊布", pokemon->name().c_str());

    auto eevee = static_pointer_cast<PokemonOf<Eevee>, Pokemon>(pokemon);
    ASSERT_STREQ("伊布", eevee->name().c_str());
}

TEST(PokemonTest, MaxWorks) {
    shared_ptr<Pokemon> pokemon = make_shared<PokemonOf<Eevee>>();
    auto t = pokemon->temp();
    for (uint i = 0; i <= 15; i++) {
        ASSERT_EQ(pokemon->level(), i);
        ASSERT_EQ(pokemon->max().hp, t->base().hp + i * t->growth().hp);
        ASSERT_EQ(pokemon->max().attack, t->base().attack + i * t->growth().attack);
        ASSERT_EQ(pokemon->max().spAttack, t->base().spAttack + i * t->growth().spAttack);
        ASSERT_EQ(pokemon->max().defense, t->base().defense + i * t->growth().defense);
        ASSERT_EQ(pokemon->max().spDefense, t->base().spDefense + i * t->growth().spDefense);
        ASSERT_EQ(pokemon->max().speed, t->base().speed + i * t->growth().speed);

        pokemon->learn(50);
    }
}
