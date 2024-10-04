#include "Warlock.hpp"


Warlock::Warlock(const std::string& name, const std::string& title)
{
    this->name = name;
    this->title = title;
     std::cout << this->getName() <<  ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->getName() <<  ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell *>::iterator it = spellSlot.begin(); it != spellSlot.end(); it++)
    {
        delete it->second;
    }
    spellSlot.clear();
}
const std::string& Warlock::getName() const
{
    return this->name;
}

const std::string& Warlock::getTitle() const
{
    return this->title;
}

void Warlock::setTitle(const std::string& title)
{
    this->title = title;
}

void Warlock::introduce() const
{
         std::cout << this->getName() << ": I am "<< this->getName()<< ", " << this->getTitle()<< "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spellSlot.find(spell->getName()) == spellSlot.end())
        spellSlot[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string spell)
{
    if (spellSlot.find(spell) != spellSlot.end())
        spellSlot.erase(spellSlot.find(spell));
}

  void Warlock::launchSpell(const std::string spell, const ATarget& target)
  {
    if (spellSlot.find(spell) != spellSlot.end())
    {
        target.getHitBySpell(*spellSlot[spell]);
    }
  }