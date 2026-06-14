#ifndef JOBPORTALSYSTEM_H
#define JOBPORTALSYSTEM_H

#include "Candidate.h"
#include "HR.h"
#include "Job.h"
#include "Application.h"
#include "FileManager.h"

class JobPortalSystem
{
private:

    Candidate* candidates;
    int candidateCount;

    HR* hrList;
    int hrCount;

    Job* jobs;
    int jobCount;

    Application* applications;
    int applicationCount;

public:

    JobPortalSystem();

    ~JobPortalSystem();

    // Add Methods
    void addCandidate(const Candidate& candidate);
    void addHR(const HR& hr);
    void addJob(const Job& job);
    void addApplication(const Application& application);
    void registerCandidate();
void registerHR();
void createJob();
void applyForJob();
void candidateMenu();
void viewAllApplications() const;
void viewApplicationsByJob();
void approveApplication();
void rejectApplication();
void loadAllData();

void saveAllData();
void hrMenu();

void mainMenu();
    // Display Methods
    void displayAllCandidates() const;
    void displayAllHRs() const;
    void displayAllJobs() const;
    void displayAllApplications() const;

    // Search Methods
    Candidate* findCandidateById(int id);
    HR* findHRById(int id);
    Job* findJobById(int id);
    Job* getJobs() const;

   int getJobCount() const;
int generateCandidateId() const;

int generateHRId() const;

int generateJobId() const;

int generateApplicationId() const;

   //Helper Functions
   int getValidChoice(int min, int max);

string getValidGmail();

string getValidName();

string getValidEducation();

int getValidExperience();

int getValidID();

int getValidSkillLevel();

    // Validation Methods
    bool candidateIdExists(int id) const;

bool hrIdExists(int id) const;

bool applicationIdExists(int id) const;
    bool emailExists(string email) const;
    bool jobExists(int id) const;
    bool applicationExists(
    int candidateId,
    int jobId
) const;
};

#endif