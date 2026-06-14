#include "Job.h"

Job::Job()
{
    jobId = 0;
    hrId = 0;

    title = "";
    location = "";
    description = "";
    employmentType = "";

    requiredExperience = 0;
    requiredEducation = "";

    requiredSkills = NULL;
    skillCount = 0;

    isActive = true;
}

Job::Job(
    int jobId,
    int hrId,
    string title,
    string location,
    string description,
    string employmentType,
    int requiredExperience,
    string requiredEducation
)
{
    requiredSkills = NULL;
    skillCount = 0;
    isActive = true;

    setJobId(jobId);
    setHRId(hrId);
    setTitle(title);
    setLocation(location);
    setDescription(description);
    setEmploymentType(employmentType);
    setRequiredExperience(requiredExperience);
    setRequiredEducation(requiredEducation);
}

Job::Job(const Job& other)
{
    jobId = other.jobId;
    hrId = other.hrId;

    title = other.title;
    location = other.location;
    description = other.description;
    employmentType = other.employmentType;

    requiredExperience = other.requiredExperience;
    requiredEducation = other.requiredEducation;

    isActive = other.isActive;

    skillCount = other.skillCount;

    if(skillCount > 0)
    {
        requiredSkills = new Skill[skillCount];

        for(int i = 0; i < skillCount; i++)
        {
            requiredSkills[i] = other.requiredSkills[i];
        }
    }
    else
    {
        requiredSkills = NULL;
    }
}

Job& Job::operator=(const Job& other)
{
    if(this != &other)
    {
        delete[] requiredSkills;

        jobId = other.jobId;
        hrId = other.hrId;

        title = other.title;
        location = other.location;
        description = other.description;
        employmentType = other.employmentType;

        requiredExperience = other.requiredExperience;
        requiredEducation = other.requiredEducation;

        isActive = other.isActive;

        skillCount = other.skillCount;

        if(skillCount > 0)
        {
            requiredSkills = new Skill[skillCount];

            for(int i = 0; i < skillCount; i++)
            {
                requiredSkills[i] = other.requiredSkills[i];
            }
        }
        else
        {
            requiredSkills = NULL;
        }
    }

    return *this;
}

Job::~Job()
{
    delete[] requiredSkills;
}

void Job::setJobId(int id)
{
    if(id > 0)
        jobId = id;
}

void Job::setHRId(int id)
{
    if(id > 0)
        hrId = id;
}

void Job::setTitle(string t)
{
    if(!t.empty())
        title = t;
}

void Job::setLocation(string loc)
{
    if(!loc.empty())
        location = loc;
}

void Job::setDescription(string desc)
{
    if(!desc.empty())
        description = desc;
}

void Job::setEmploymentType(string type)
{
    if(!type.empty())
        employmentType = type;
}

void Job::setRequiredExperience(int exp)
{
    if(exp >= 0)
        requiredExperience = exp;
}

string Job::getRequiredEducation() const
{
    return requiredEducation;
}

bool Job::isValidEducation(string edu) const
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

int Job::getJobId() const
{
    return jobId;
}

int Job::getHRId() const
{
    return hrId;
}

string Job::getTitle() const
{
    return title;
}

string Job::getLocation() const
{
    return location;
}

string Job::getDescription() const
{
    return description;
}

string Job::getEmploymentType() const
{
    return employmentType;
}

int Job::getRequiredExperience() const
{
    return requiredExperience;
}

void Job::setRequiredEducation(string edu)
{
    if(isValidEducation(edu))
    {
        requiredEducation = edu;
    }
}

int Job::getSkillCount() const
{
    return skillCount;
}

Skill Job::getRequiredSkillAt(int index) const
{
    if(index >= 0 && index < skillCount)
    {
        return requiredSkills[index];
    }

    return Skill();
}

bool Job::getStatus() const
{
    return isActive;
}

void Job::addRequiredSkill(string skillName, int skillLevel)
{
    for(int i = 0; i < skillCount; i++)
    {
        if(requiredSkills[i].getSkillName() == skillName)
        {
            cout << "Skill already exists." << endl;
            return;
        }
    }

    Skill* newSkills = new Skill[skillCount + 1];

    for(int i = 0; i < skillCount; i++)
    {
        newSkills[i] = requiredSkills[i];
    }

    newSkills[skillCount] = Skill(skillName, skillLevel);

    delete[] requiredSkills;

    requiredSkills = newSkills;

    skillCount++;
}

void Job::closeJob()
{
    isActive = false;
}

void Job::displayJob() const
{
    cout << "\n========== JOB ==========\n";

    cout << "Job ID: " << jobId << endl;
    cout << "HR ID: " << hrId << endl;
    cout << "Title: " << title << endl;
    cout << "Location: " << location << endl;
    cout << "Type: " << employmentType << endl;
    cout << "Experience Required: "
         << requiredExperience
         << " years" << endl;

    cout << "Education Required: "
         << requiredEducation
         << endl;

    cout << "Description: "
         << description
         << endl;

    cout << "Status: "
         << (isActive ? "Active" : "Closed")
         << endl;

    cout << "\nRequired Skills:\n";

    if(skillCount == 0)
    {
        cout << "No skills added.\n";
    }
    else
    {
        for(int i = 0; i < skillCount; i++)
        {
            requiredSkills[i].displaySkill();
        }
    }

    cout << "=========================\n";
}