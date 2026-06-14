#include "Application.h"

Application::Application()
{
    applicationId = 0;
    candidateId = 0;
    jobId = 0;

    applicationDate = "";

    status = "Pending";

    matchScore = 0;
}

Application::Application(
    int appId,
    int cId,
    int jId,
    string date
)
{
    applicationId = 0;
    candidateId = 0;
    jobId = 0;

    applicationDate = "";

    status = "Pending";
    matchScore = 0;

    setApplicationId(appId);
    setCandidateId(cId);
    setJobId(jId);
    setApplicationDate(date);
}

void Application::setApplicationId(int id)
{
    if(id > 0)
    {
        applicationId = id;
    }
}

void Application::setCandidateId(int id)
{
    if(id > 0)
    {
        candidateId = id;
    }
}

void Application::setJobId(int id)
{
    if(id > 0)
    {
        jobId = id;
    }
}

void Application::setApplicationDate(string date)
{
    if(!date.empty())
    {
        applicationDate = date;
    }
}

void Application::setStatus(string s)
{
    if(!s.empty())
    {
        status = s;
    }
}

int Application::getApplicationId() const
{
    return applicationId;
}

int Application::getCandidateId() const
{
    return candidateId;
}

int Application::getJobId() const
{
    return jobId;
}

string Application::getApplicationDate() const
{
    return applicationDate;
}

string Application::getStatus() const
{
    return status;
}

void Application::displayApplication() const
{
    cout << "\n===== APPLICATION =====\n";

    cout << "Application ID: "
         << applicationId
         << endl;

    cout << "Candidate ID: "
         << candidateId
         << endl;

    cout << "Job ID: "
         << jobId
         << endl;

    cout << "Date: "
         << applicationDate
         << endl;

    cout << "Status: "
         << status
         << endl;

         cout << "Match Score: "
     << matchScore
     << "%"
     << endl;
}

void Application::setMatchScore(
    double score)
{
    if(score >= 0 && score <= 100)
    {
        matchScore = score;
    }
}

double Application::getMatchScore() const
{
    return matchScore;
}