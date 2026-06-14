#include "Candidate.h"

Candidate::Candidate() : User()
{
    experienceYears = 0;
    education = "";
    skills = NULL;
    skillCount = 0;
}

Candidate::Candidate(int id, string n, string e, int exp, string edu)
    : User(id, n, e)
{
    experienceYears = exp;
    education = edu;
    skills = NULL;
    skillCount = 0;
}

Candidate::Candidate(const Candidate& other)
    : User(other.userId,
           other.name,
           other.email)
{
    experienceYears = other.experienceYears;
    education = other.education;
    skillCount = other.skillCount;

    if(skillCount > 0)
    {
        skills = new Skill[skillCount];

        for(int i = 0; i < skillCount; i++)
        {
            skills[i] = other.skills[i];
        }
    }
    else
    {
        skills = NULL;
    }
}

Candidate& Candidate::operator=(const Candidate& other)
{
    if(this != &other)
    {
        delete[] skills;

        userId = other.userId;
        name = other.name;
        email = other.email;

        experienceYears = other.experienceYears;
        education = other.education;
        skillCount = other.skillCount;

        if(skillCount > 0)
        {
            skills = new Skill[skillCount];

            for(int i = 0; i < skillCount; i++)
            {
                skills[i] = other.skills[i];
            }
        }
        else
        {
            skills = NULL;
        }
    }

    return *this;
}

Candidate::~Candidate()
{
    delete[] skills;
}

void Candidate::setExperienceYears(int exp)
{
    if(exp >= 0)
    {
        experienceYears = exp;
    }
}

void Candidate::setEducation(string edu)
{
    if(isValidEducation(edu))
    {
        education = edu;
    }
}

bool Candidate::isValidEducation(string edu) const
{
    string upperEdu = "";

    for(int i = 0; i < edu.length(); i++)
    {
        upperEdu += toupper(edu[i]);
    }

    if(
        upperEdu == "MATRIC"
        ||
        upperEdu == "FSC"
        ||
        upperEdu == "BS"
        ||
        upperEdu == "MS"
        ||
        upperEdu == "PHD"
    )
    {
        return true;
    }

    return false;
}

int Candidate::getExperienceYears() const
{
    return experienceYears;
}

string Candidate::getEducation() const
{
    return education;
}

int Candidate::getSkillCount() const
{
    return skillCount;
}

Skill Candidate::getSkillAt(int index) const
{
    if(index >= 0 && index < skillCount)
    {
        return skills[index];
    }

    return Skill();
}

void Candidate::addSkill(string skillName,
                         int skillLevel)
{
    for(int i = 0; i < skillCount; i++)
    {
        if(skills[i].getSkillName() == skillName)
        {
            cout << "Skill already exists."
                 << endl;
            return;
        }
    }

    Skill* newSkills =
        new Skill[skillCount + 1];

    for(int i = 0; i < skillCount; i++)
    {
        newSkills[i] = skills[i];
    }

    newSkills[skillCount] =
        Skill(skillName, skillLevel);

    delete[] skills;

    skills = newSkills;

    skillCount++;
}

void Candidate::displayCandidateProfile() const
{
    cout << "Candidate Profile" << endl;
    cout << "------------------" << endl;
    cout << "ID: " << userId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Experience: " << experienceYears << " years" << endl;
    cout << "Education: " << education << endl;

    cout << "Skills:" << endl;
    if (skillCount == 0)
    {
        cout << "No skills added." << endl;
    }
    else
    {
        for (int i = 0; i < skillCount; i++)
        {
            skills[i].displaySkill();
        }
    }
}