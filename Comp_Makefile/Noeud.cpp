#include "Noeud.h"

Noeud::Noeud()
{
}

void Noeud::affiche(int l)
{
    /*
        print(" ") l fois,
        print(N.type ......)
        Pour chaque enfant E de N
        Affichee(E,L+1)
    */
    for(int i = 0; i < l; i++)
    {
        cout << "_";
    }
    printNoeud();
    for(int i = 0; i < Noeuds_Fils.size(); i++)
    {
        (*Noeuds_Fils[i]).affiche(l+1);
    }
}

Noeud::Noeud(typeNoeud tN, Token refToken)
{
    ligne = refToken.l;
    colonne = refToken.c;
    type = tN;
    id = idShare;
    idShare++;
}


void Noeud::ajouterEnfant(Noeud *N)
{
    Noeuds_Fils.push_back(N);
}

Noeud::Noeud(Noeud *N1, Noeud *N2)
{
    Noeuds_Fils.push_back(N1);
    Noeuds_Fils.push_back(N2);
    id = idShare;
    idShare++;
}

typeNoeud Noeud::convertTypeToken(typeToken t) ///Quand bool unaire sera à false nos plus et moins seront binaire
{
    typeNoeud tN;
    switch(t)
    {
        case tok_ident: tN = tNoeud_ident; break;
        case tok_const: tN = tNoeud_const; break;
        case tok_moins: tN = tNoeud_moinsU; break;
        case tok_plus: tN = tNoeud_plusU; break;
        case tok_multiplier: tN = tNoeud_multiplier; break;
        case tok_diviser: tN = tNoeud_diviser; break;
        case tok_exponentielle: tN = tNoeud_exponentielle; break;
        case tok_accoladeOuvrante: tN = tNoeud_accoladeOuvrante; break;
        case tok_accoladeFermante: tN = tNoeud_accoladeFermante; break;
        case tok_doubleEgal: tN = tNoeud_doubleEgal; break;
        case tok_uniqueEgal: tN = tNoeud_uniqueEgal; break;
        case tok_chevronInf: tN = tNoeud_chevronInf; break;
        case tok_chevronSup: tN =  tNoeud_chevronSup; break;
        case tok_chevronInfEgal: tN = tNoeud_chevronInfEgal; break;
        case tok_chevronSupEgal: tN = tNoeud_chevronSupEgal; break;
        case tok_endLine: tN = tNoeud_endLine; break;
        case tok_And: tN = tNoeud_And; break;
        case tok_Or: tN = tNoeud_Or; break;
        case tok_If: tN = tNoeud_If; break;
        case tok_For: tN = tNoeud_For; break;
        case tok_While: tN = tNoeud_While; break;
        default:
            break;
    }
    return tN;
}

string Noeud::getTypeNoeud()
{
    string typeNoeud="";
    switch(type)
    {
        case tNoeud_ident: typeNoeud = "tNoeud_ident"; break;
        case tNoeud_const: typeNoeud = "tNoeud_const"; break;
        case tNoeud_moinsU: typeNoeud = "tNoeud_moinsU"; break;
        case tNoeud_plusU: typeNoeud = "tNoeud_plusU"; break;
        case tNoeud_moinsB: typeNoeud = "tNoeud_moinsU"; break;
        case tNoeud_plusB: typeNoeud = "tNoeud_plusU"; break;
        case tNoeud_multiplier: typeNoeud = "tNoeud_multiplier"; break;
        case tNoeud_diviser: typeNoeud = "tNoeud_diviser"; break;
        case tNoeud_exponentielle: typeNoeud = "tNoeud_exponentielle"; break;
        case tNoeud_accoladeOuvrante: typeNoeud = "tNoeud_accoladeOuvrante"; break;
        case tNoeud_accoladeFermante: typeNoeud = "tNoeud_accoladeFermante"; break;
        case tNoeud_doubleEgal: typeNoeud = "tNoeud_doubleEgal"; break;
        case tNoeud_uniqueEgal: typeNoeud = "tNoeud_uniqueEgal"; break;
        case tNoeud_chevronInf: typeNoeud = "tNoeud_chevronInf"; break;
        case tNoeud_chevronSup: typeNoeud = "tNoeud_chevronSup"; break;
        case tNoeud_chevronInfEgal: typeNoeud = "tNoeud_chevronInfEgal"; break;
        case tNoeud_chevronSupEgal: typeNoeud = "tNoeud_chevronSupEgal"; break;
        case tNoeud_endLine: typeNoeud = "tNoeud_endLine"; break;
        case tNoeud_And: typeNoeud = "tNoeud_And"; break;
        case tNoeud_Or: typeNoeud = "tNoeud_Or"; break;
        case tNoeud_If: typeNoeud = "tNoeud_If"; break;
        case tNoeud_For: typeNoeud = "tNoeud_For"; break;
        case tNoeud_While: typeNoeud = "tNoeud_While"; break;
    }
    return typeNoeud;
}

void Noeud::printNoeud()
{
    cout << "id : " << id << " type " << getTypeNoeud() <<  " ligne " << ligne << " colonne " << colonne << endl;
}
Noeud::~Noeud()
{
    //dtor
}
