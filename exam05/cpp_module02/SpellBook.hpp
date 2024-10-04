#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

using std::string;

class ASpell;

class SpellBook
{
    protected:
        std::string type;
        std::map<std::string, ASpell*> book;
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell *spell);
        void forgetSpell(const std::string& spell);
        ASpell* createSpell(string const &);
};

#endif