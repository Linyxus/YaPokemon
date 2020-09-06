//
// Created by Yichen Xu on 2020/9/1.
//

#include <pokemon/PokemonInstance.h>
#include <pokemon/pokemons/eevee.h>
#include <move/Move.h>
#include <gtest/gtest.h>
#include <memory>
using namespace std;

TEST(PokemonInstanceTest, AttackWorks) {
    shared_ptr<Pokemon> pokemon = make_shared<PokemonOf<Eevee>>();
    auto instance = instance_of(pokemon);

    ASSERT_EQ(instance->current().hp, pokemon->max().hp);
    auto move = instance->pokemon()->temp()->moves()[0];
    auto act = move->move(instance, instance);
    ASSERT_EQ(act[0]->type(), ActAttack);
    auto att = dynamic_pointer_cast<AttackAction>(act[0]);
    ASSERT_EQ(att->value, 4);
    ASSERT_EQ(att->attack_type, MCNormal);

    instance->accept_actions(act);
    ASSERT_EQ(instance->current().hp, 10 - 3);
}
