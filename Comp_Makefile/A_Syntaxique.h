#ifndef A_SYNTAXIQUE_H
#define A_SYNTAXIQUE_H
#include "A_Lexicale.h"
#include <map>
using namespace std;

struct opBin{
    typeToken t_Token;
    int priorite;
    typeNoeud t_Noeud;
    int associativite;
    opBin(typeToken t_Token, int priorite, typeNoeud t_Noeud, int associativite)
    {
        this->t_Token = t_Token;
        this->priorite = priorite;
        this->t_Noeud = t_Noeud;
        this->associativite = associativite;
    }

    opBin(){
    }
};

class A_Syntaxique
{
    public:
        A_Syntaxique();
        A_Lexicale AL;
        Token tokenCourant(A_Lexicale& AL);
        Noeud *Atom(A_Lexicale& AL);
        Noeud *Expr(A_Lexicale& AL, int MaxP);
        bool isBinOp(Token T);
        void avance(A_Lexicale& AL);
        map<typeToken, opBin> listOpBin;
        void initTabOpBin();
        virtual ~A_Syntaxique();
    protected:

    private:
};
#endif // A_SYNTAXIQUE_H
