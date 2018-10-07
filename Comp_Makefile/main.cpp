#include <iostream>
#include "A_Syntaxique.h"
using namespace std;

int Noeud::idShare = 0;

int main()
{
    A_Lexicale AL("fichier.txt");
    A_Syntaxique AS;
    ///AL.printListToken();
    cout << endl << "current pos :" << AL.currentPos << " size tab : " << AL.tokenList.size() << endl;
    Noeud *N = AS.Expr(AL, 5);
    (*N).affiche(0);
    return 0;
}
