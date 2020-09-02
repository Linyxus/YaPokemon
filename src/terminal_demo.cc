#include <iostream>
#include <pokemon/tools.h>
#include <pokemon/PokemonInstance.h>
#include <pokemon/pokemons/eevee.h>
#include <pokemon/pokemons/pikachu.h>
#include <battle/Battle.h>
#include <move/Move.h>

using namespace std;

int main() {
    srand(time(nullptr));
    cout << "Welcome to Pokemon" << endl;
    shared_ptr<Pokemon> eevee = make_shared<PokemonOf<Eevee>>();
    shared_ptr<Pokemon> pikachu = make_shared<PokemonOf<Pikachu>>();
    eevee->learn(750); pikachu->learn(750);
    auto sess = Battle(eevee, pikachu);
    cout << "左 " << eevee << endl;
    cout << "右 " << pikachu << endl;
    cout << endl << endl;

    auto state = Ongoing;
    while (state == Ongoing) {
        auto round = sess.proceed();

        if (round.miss) {
            if (round.turn == LeftTurn) {
                cout << "左边的 " << sess.left()->pokemon()->temp()->name() << " 想要攻击，但被躲避了" << endl;
                cout << "左 " << sess.left() << endl << "右 " << sess.right() << endl;
            } else {
                cout << "右边的 " << sess.right()->pokemon()->temp()->name() << " 想要攻击，但被躲避了" << endl;
                cout << "左 " << sess.left() << endl << "右 " << sess.right() << endl;
            }
            cout << endl << endl;
            continue;
        }

        if (round.turn == LeftTurn) {
            cout << "左边的 " << sess.left()->pokemon()->temp()->name() << " 使出了 "
                << round.move->name() << endl;
            cout << "左 " << sess.left() << endl << "右 " << sess.right() << endl;
        } else {
            cout << "右边的 " << sess.right()->pokemon()->temp()->name() << " 使出了 "
                 << round.move->name() << endl;
            cout << "左 " << sess.left() << endl << "右 " << sess.right() << endl;

        }
        cout << endl << endl;

        state = sess.check();
    }
    if (state == LeftWin) {
        cout << "左边的 " << sess.left()->pokemon()->temp()->name() << " 获胜了" << endl;
    } else {
        cout << "右边的 " << sess.right()->pokemon()->temp()->name() << " 获胜了" << endl;
    }

    return 0;
}
