#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <string>

using namespace std;

class Skill
{
private:
    string skillName;
    int skillLevel;

public:
    Skill();

    Skill(string name, int level);

    void setSkillName(string name);
    void setSkillLevel(int level);

    string getSkillName() const;
    int getSkillLevel() const;

    void displaySkill() const;
};

#endif