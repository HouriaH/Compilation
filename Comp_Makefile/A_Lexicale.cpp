#include "A_Lexicale.h"

A_Lexicale::A_Lexicale()
{
}

A_Lexicale::A_Lexicale(string nomFichier)
{
    ifstream fichier(nomFichier.c_str());
    stringstream buffer;
    buffer << fichier.rdbuf();
    string chaine = buffer.str();
    cout << "chaine : " << endl
         << chaine << endl;
    string alphaNumString;
    string digitString;
    int ligne = 1;
    int colonne = 1;
    for (int i = 0; i < (int)chaine.length(); i++)
    {
        switch (chaine[i])
        {
        case '{':
            tokenList.push_back(Token(tok_accoladeOuvrante, ligne, colonne, "{"));
            break;
        case '}':
            tokenList.push_back(Token(tok_accoladeFermante, ligne, colonne, "}"));
            break;
        case '^':
            tokenList.push_back(Token(tok_exponentielle, ligne, colonne, "^"));
            break;
        case '<':
            if (i + 1 < chaine.length())
            {
                if (chaine[i + 1] == '=')
                {
                    tokenList.push_back(Token(tok_chevronInfEgal, ligne, colonne, "<="));
                    i = i + 1;
                    colonne++;
                    break;
                }
            }
            tokenList.push_back(Token(tok_chevronInf, ligne, colonne, "<"));
            break;
        case '>':
            if (i + 1 < chaine.length())
            {
                if (chaine[i + 1] == '=')
                {
                    tokenList.push_back(Token(tok_chevronSupEgal, ligne, colonne, ">="));
                    i = i + 1;
                    colonne++;
                    break;
                }
            }
            tokenList.push_back(Token(tok_chevronInf, ligne, colonne, "^"));
            break;
        case '+':
            tokenList.push_back(Token(tok_plus, ligne, colonne, "+"));
            break;
        case '-':
            tokenList.push_back(Token(tok_moins, ligne, colonne, "-"));
            break;
        default:
            if (isdigit(chaine[i]))
            {
                digitString = chaine[i];
                int cFirstDigit = colonne;
                bool isNumeric = true;
                while (i < (int)chaine.length() && isNumeric)
                {
                    i++;
                    colonne++;
                    isNumeric = isdigit(chaine[i]);
                    if (isNumeric)
                        digitString += chaine[i];
                }
                i--;
                colonne--;
                tokenList.push_back(Token(tok_const, ligne, cFirstDigit, digitString));
            }
            else if (isalpha(chaine[i]))
            {
                alphaNumString = chaine[i];
                int cFirstAlpha = colonne;
                bool isAlphaNum = true;
                while (i < (int)chaine.length() && isAlphaNum)
                {
                    i++;
                    colonne++;
                    isAlphaNum = isalnum(chaine[i]);
                    if (isAlphaNum)
                        alphaNumString += chaine[i];
                }
                i--;
                colonne--;
                tokenList.push_back(Token(tok_ident, ligne, cFirstAlpha, alphaNumString));
            }
            else if (isspace(chaine[i]))
            {
                if (chaine[i] == '\n')
                {
                    ligne++;
                    colonne = 0;
                }
            }
            else
            {
            }
        }
        colonne++;
    }
    currentPos = 0;
}

A_Lexicale::~A_Lexicale()
{
    //dtor
}

void A_Lexicale::printListToken()
{
    for (int i = 0; i < (int)tokenList.size(); i++)
        tokenList[i].print();
}
