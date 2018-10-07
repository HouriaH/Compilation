#include "Token.h"

Token::Token()
{

}

Token::Token(typeToken type, int l, int c)
{
    this->type = type;
    this->l = l;
    this->c = c;
    val = "";
}

Token::Token(typeToken type, int l, int c, string val)
{
    this->type = type;
    this->l = l;
    this->c = c;
    this->val = val;
}
void Token::print()
{
    cout << "Type: " << getTypeToken(type) << " val: " << val << " ligne: " << l << " colonne: " << c << endl;
}

Token::~Token()
{
    //dtor
}

string Token::getTypeToken(typeToken type)
{
    string val;
    switch(type)
    {
        case tok_const: val = "tok_const"; break;
        case tok_ident: val = "tok_ident"; break;
        case tok_moins: val = "tok_moins"; break;
        case tok_plus: val = "tok_plus"; break;
        case tok_multiplier: val = "tok_multiplier"; break;
        case tok_diviser: val = "tok_diviser"; break;
        case tok_exponentielle: val = "tok_exponentielle"; break;
        case tok_accoladeOuvrante: val = "tok_accoladeOuvrante"; break;
        case tok_accoladeFermante: val = "tok_accoladeFermante"; break;
        case tok_doubleEgal: val = "tok_doubleEgal"; break;
        case tok_uniqueEgal: val = "tok_uniqueEgal"; break;
        case tok_chevronInf: val = "tok_chevronInf"; break;
        case tok_chevronSup: val = "tok_chevronSup"; break;
        case tok_chevronInfEgal: val = "tok_chevronInfEgal"; break;
        case tok_chevronSupEgal: val = "tok_chevronSupEgal"; break;
        case tok_endLine: val = "tok_endLine"; break;
        case tok_And: val = "tok_And"; break;
        case tok_Or: val = "tok_Or"; break;
        case tok_If: val = "tok_If"; break;
        case tok_For: val = "tok_For"; break;
        case tok_While: val = "tok_While"; break;
        default: val = "error";
    }
    return val;
}
