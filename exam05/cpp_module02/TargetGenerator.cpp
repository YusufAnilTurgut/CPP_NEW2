
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
    for (std::map<std::string, ATarget *>::iterator it = data.begin(); it != data.end(); it++)
    {
        delete it->second;
    }
    data.clear();
}


void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
        data[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string& type)
{
    std::map<std::string, ATarget *>::iterator it= data.begin();
    
    while (it != data.end())
    {
        delete it->second;
        data.erase(type);
        it++;
    }
}

ATarget* TargetGenerator::createTarget(string const &spellName)
{
    ATarget *tmp = NULL;
    if (data.find(spellName) != data.end())
        tmp = data[spellName];
    return tmp;
}
