//
// Created by Yichen Xu on 2020/9/1.
//

#include <gtest/gtest.h>
#include <battle/Battle.h>
#include <pokemon/pokemons/eevee.h>
#include <pokemon/pokemons/pikachu.h>

TEST(TestBattle, BattleTestCase1) {
    shared_ptr<Pokemon> p1 = make_shared<PokemonOf<Eevee>>();
    shared_ptr<Pokemon> p2 = make_shared<PokemonOf<Pikachu>>();
    p1->learn(750);
    p2->learn(750);
    ASSERT_EQ(p1->max().hp, 10 + 15 * 2);
    ASSERT_EQ(p2->max().hp, 8 + 15 * 1);
    ASSERT_EQ(p2->max().spAttack, 20 + 15 * 5);

    auto battle = Battle(p1, p2);
    ASSERT_EQ(battle.check(), Ongoing);

    auto state = battle.check();
    while (state == Ongoing) {
        auto m = battle.proceed();
        state = battle.check();
    }
}

