#ifndef TOKEN_H
#define TOKEN_H
#include "iostream"
using namespace std;
enum typeToken{
    tok_const,
    tok_ident,
    tok_,
    tok_moins,
    tok_plus,
    tok_multiplier,
    tok_diviser,
    tok_exponentielle,
    tok_accoladeOuvrante,
    tok_accoladeFermante,
    tok_doubleEgal,
    tok_uniqueEgal,
    tok_chevronInf,
    tok_chevronSup,
    tok_chevronInfEgal,
    tok_chevronSupEgal,
    tok_endLine,
    tok_And,
    tok_Or,
    tok_If,
    tok_For,
    tok_While
};

class Token
{
    public:
        Token();
        Token(typeToken type, int l, int c);
        Token(typeToken type, int l, int c, string val);
        void initToken(typeToken type, int l, int c);
        void initToken(typeToken type, int l, int c, string val);
        string getTypeToken(typeToken type);
        void print();
        typeToken type;
        int l;
        int c;
        string val;
        virtual ~Token();

    protected:

    private:
};

#endif // TOKEN_H
