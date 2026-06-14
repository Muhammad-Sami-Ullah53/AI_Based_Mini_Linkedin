#include "Skill.h"

Skill::Skill()
{
    skillName = "";
    skillLevel = 0;
}

Skill::Skill(string name, int level)
{
    if(name.empty())
    {
        skillName = "Unknown";
    }
    else
    {
        skillName = name;
    }

    if(level >= 1 && level <= 10)
    {
        skillLevel = level;
    }
    else
    {
        skillLevel = 1;
    }
}

void Skill::setSkillName(string name)
{
    if(!name.empty())
    {
        skillName = name;
    }
}

void Skill::setSkillLevel(int level)
{
    if(level >= 1 && level <= 10)
    {
        skillLevel = level;
    }
}

string Skill::getSkillName() const
{
    return skillName;
}

int Skill::getSkillLevel() const
{
    return skillLevel;
}

void Skill::displaySkill() const
{
    cout << skillName << " (Level " << skillLevel << ")" << endl;
}