#ifndef A_LEXICALE_H
#define A_LEXICALE_H
#include <ctype.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Token.h"
#include "Noeud.h"
using namespace std;

class A_Lexicale
{
  public:
    A_Lexicale(string nomFichier);
    A_Lexicale();
    int currentPos;
    vector<Token> tokenList;
    void printListToken();
    virtual ~A_Lexicale();

  protected:
  private:
};

#endif // A_LEXICALE_H
