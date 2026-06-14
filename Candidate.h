#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <string>
#include "User.h"
#include "Skill.h"

using namespace std;

class Candidate : public User
{
private:
    int experienceYears;
    string education;
    Skill *skills;
    int skillCount;

public:
    Candidate();
    Candidate(int id, string n, string e, int exp, string edu);
    Candidate(const Candidate &other);

    Candidate &operator=(const Candidate &other);
    ~Candidate();

    void setExperienceYears(int exp);
    void setEducation(string edu);

    int getExperienceYears() const;
    string getEducation() const;
    int getSkillCount() const;
Skill getSkillAt(int index) const;
bool isValidEducation(string edu) const;
    void addSkill(string skillName, int skillLevel);
    void displayCandidateProfile() const;
};

#endif