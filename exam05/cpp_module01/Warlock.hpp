#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class ASpell;
class ATarget;

class Warlock
{
    private:
        std::string name;
        std::string title;
        std::map<std::string, ASpell*> spellSlot;
    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
        const std::string& getName() const;
        const std::string& getTitle() const;
        void setTitle(const std::string& title);
        void introduce() const;
        void learnSpell(ASpell *spell);
        void forgetSpell(const std::string spell);
        void launchSpell(const std::string spell, const ATarget& target);
    
};

#endif