#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <string>

using namespace std;

class Application
{
private:
    int applicationId;

    int candidateId;

    int jobId;

    string applicationDate;

    string status;

    double matchScore;

public:

    Application();

    Application(
        int appId,
        int candidateId,
        int jobId,
        string date
    );
void setMatchScore(double score);

double getMatchScore() const;
    void setApplicationId(int id);
    void setCandidateId(int id);
    void setJobId(int id);
    void setApplicationDate(string date);
    void setStatus(string status);

    int getApplicationId() const;
    int getCandidateId() const;
    int getJobId() const;
    string getApplicationDate() const;
    string getStatus() const;

    void displayApplication() const;
};

#endif