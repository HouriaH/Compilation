#ifndef NOEUD_H
#define NOEUD_H
#include "Token.h"
#include <vector>

enum typeNoeud{
    tNoeud_ident,
    tNoeud_const,
    tNoeud_moinsU,
    tNoeud_plusU,
    tNoeud_moinsB,
    tNoeud_plusB,
    tNoeud_multiplier,
    tNoeud_diviser,
    tNoeud_exponentielle,
    tNoeud_accoladeOuvrante,
    tNoeud_accoladeFermante,
    tNoeud_doubleEgal,
    tNoeud_uniqueEgal,
    tNoeud_chevronInf,
    tNoeud_chevronSup,
    tNoeud_chevronInfEgal,
    tNoeud_chevronSupEgal,
    tNoeud_endLine,
    tNoeud_And,
    tNoeud_Or,
    tNoeud_If,
    tNoeud_For,
    tNoeud_While
};

class Noeud
{
    public:
        static int idShare;
        int id;
        vector <Noeud *> Noeuds_Fils;
        typeNoeud type;
        int ligne;
        int colonne;
        Noeud();
        Noeud(Noeud *N1, Noeud *N2);
        void affiche(int l);
        typeNoeud convertTypeToken(typeToken t);
        Noeud(typeNoeud tN, Token refToken);
        void ajouterEnfant(Noeud *N);
        void printNoeud();
        string getTypeNoeud();
        virtual ~Noeud();
    protected:

    private:
};
#endif // NOEUD_H
