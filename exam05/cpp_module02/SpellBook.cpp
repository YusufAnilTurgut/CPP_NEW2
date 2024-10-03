#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}


SpellBook::~SpellBook()
{

    for (std::map<std::string, ASpell *>::iterator it = book.begin(); it != book.end(); it++)
    {
        delete it->second;
    }
    book.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
        book[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string& spell)
{
    std::map<std::string, ASpell *>::iterator it= book.begin();
    
    while (it != book.end())
    {
        delete it->second;
        book.erase(spell);
    }
}

ASpell* SpellBook::createSpell(string const &spellName)
{
    ASpell* tmp = NULL;
    if (book.find(spellName) != book.end())
        tmp = book[spellName];
    return tmp;
}