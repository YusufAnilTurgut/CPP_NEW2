#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

using std::string;

class ATarget;

class TargetGenerator
{
    protected:
        std::map<std::string, ATarget*> data;
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget *target);
        void forgetTargetType(const std::string& type);
        ATarget* createTarget(const std::string &);
};

#endif