#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <string>
#include "Skill.h"

using namespace std;

class Job
{
private:
    int jobId;
    int hrId;

    string title;
    string location;
    string description;
    string employmentType;

    int requiredExperience;
    string requiredEducation;

    Skill* requiredSkills;
    int skillCount;

    bool isActive;

public:
    Job();

    Job(
        int jobId,
        int hrId,
        string title,
        string location,
        string description,
        string employmentType,
        int requiredExperience,
        string requiredEducation
    );

    Job(const Job& other);

    Job& operator=(const Job& other);

    ~Job();

    void setJobId(int id);
    void setHRId(int id);
    void setTitle(string title);
    void setLocation(string location);
    void setDescription(string description);
    void setEmploymentType(string type);
    void setRequiredExperience(int exp);
    void setRequiredEducation(string education);

    int getJobId() const;
    int getHRId() const;
    string getTitle() const;
    string getLocation() const;
    string getDescription() const;
    string getEmploymentType() const;
    int getRequiredExperience() const;
    string getRequiredEducation() const;
    int getSkillCount() const;
    bool getStatus() const;
    Skill getRequiredSkillAt(int index) const;
bool isValidEducation(string edu) const;
    void addRequiredSkill(string skillName, int skillLevel);

    void closeJob();

    void displayJob() const;
};

#endif