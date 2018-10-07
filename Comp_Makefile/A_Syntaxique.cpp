#include "A_Syntaxique.h"

A_Syntaxique::A_Syntaxique()
{
    initTabOpBin();
}

A_Syntaxique::~A_Syntaxique()
{
    //dtor
}

Token A_Syntaxique::tokenCourant(A_Lexicale& AL)
{
    return AL.tokenList[AL.currentPos];
}

void A_Syntaxique::avance(A_Lexicale& AL)
{
    if(AL.currentPos < AL.tokenList.size()-1)
    {
        AL.currentPos++;
        cout << endl << "incr de i : " << AL.currentPos << endl;
    }
    else
    {
    }

}

Noeud *A_Syntaxique::Expr(A_Lexicale& AL, int MaxP)
{
    Noeud *A = Atom(AL);
    Token T = tokenCourant(AL);
    while(isBinOp(T) && listOpBin[T.type].priorite < MaxP)
    {
        avance(AL);
        Noeud *N = new Noeud(listOpBin[T.type].t_Noeud, T);
        (*N).ajouterEnfant(A);
        (*N).ajouterEnfant(Expr(AL,listOpBin[T.type].priorite+listOpBin[T.type].associativite));
        A = N;
        T = tokenCourant(AL);
    }
    return A;
}

void A_Syntaxique::initTabOpBin()
{
    listOpBin[tok_exponentielle] = opBin(tok_exponentielle, 1, tNoeud_exponentielle, 1);
    listOpBin[tok_multiplier] = opBin(tok_multiplier, 2, tNoeud_multiplier, 0);
    listOpBin[tok_diviser] = opBin(tok_diviser, 2, tNoeud_diviser, 0);
    listOpBin[tok_plus] = opBin(tok_plus, 3, tNoeud_plusB, 0);
    listOpBin[tok_moins] = opBin(tok_moins, 3, tNoeud_moinsB, 0);
}

bool A_Syntaxique::isBinOp(Token T)
{
    bool found = false;
    int i = 0;
    found = listOpBin.count(T.type) > 0;
    return found;
}

Noeud *A_Syntaxique::Atom(A_Lexicale& AL)
{
    Token t = tokenCourant(AL);
    if(t.type == tok_const)
    {
        Noeud *N = new Noeud(tNoeud_const, t);
        avance(AL);
        return N;
    }
    else if(t.type == tok_plus || t.type == tok_moins)
    {
        Noeud *N;
        if(t.type == tok_plus)
        {
            N = new Noeud(tNoeud_plusU,t);
        }
        else
        {
            N = new Noeud(tNoeud_moinsU,t);
        }
        avance(AL);
        Noeud *E = Atom(AL);
        (*E).id = (*E).idShare;
        (*E).idShare++;
        (*N).ajouterEnfant(E);
        return N;
    }
    else
    {
        cout << "entree erreur ";
    }
}
