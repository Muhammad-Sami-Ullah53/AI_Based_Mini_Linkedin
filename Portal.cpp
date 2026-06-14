#include "Portal.h"
#include "FileManager.h"
#include "MatchingEngine.h"
#include "GapAnalyzer.h"
#include "JobRecommender.h"
#include<iomanip>
#include <cstdlib>

void clearScreen();
void pauseScreen();

JobPortalSystem::JobPortalSystem()
{
    candidates = NULL;
    candidateCount = 0;

    hrList = NULL;
    hrCount = 0;

    jobs = NULL;
    jobCount = 0;

    applications = NULL;
    applicationCount = 0;
}

JobPortalSystem::~JobPortalSystem()
{
    delete[] candidates;
    delete[] hrList;
    delete[] jobs;
    delete[] applications;
}

bool JobPortalSystem::candidateIdExists(
    int id
) const
{
    for(int i = 0;
        i < candidateCount;
        i++)
    {
        if(
            candidates[i]
                .getUserId()
            ==
            id
        )
        {
            return true;
        }
    }

    return false;
}

bool JobPortalSystem::hrIdExists(
    int id
) const
{
    for(int i = 0;
        i < hrCount;
        i++)
    {
        if(
            hrList[i]
                .getUserId()
            ==
            id
        )
        {
            return true;
        }
    }

    return false;
}

bool JobPortalSystem::applicationIdExists(
    int id
) const
{
    for(int i = 0;
        i < applicationCount;
        i++)
    {
        if(
            applications[i]
                .getApplicationId()
            ==
            id
        )
        {
            return true;
        }
    }

    return false;
}

bool JobPortalSystem::emailExists(string email) const
{
    for(int i = 0; i < candidateCount; i++)
    {
        if(candidates[i].getEmail() == email)
        {
            return true;
        }
    }

    for(int i = 0; i < hrCount; i++)
    {
        if(hrList[i].getEmail() == email)
        {
            return true;
        }
    }

    return false;
}



bool JobPortalSystem::jobExists(int id) const
{
    for(int i = 0; i < jobCount; i++)
    {
        if(jobs[i].getJobId() == id)
        {
            return true;
        }
    }

    return false;
}

void JobPortalSystem::addCandidate(
    const Candidate& candidate)
{
    if(emailExists(candidate.getEmail()))
    {
        cout << "Email already exists." << endl;
        return;
    }

    Candidate* newArray =
        new Candidate[candidateCount + 1];

    for(int i = 0; i < candidateCount; i++)
    {
        newArray[i] = candidates[i];
    }

    newArray[candidateCount] = candidate;

    delete[] candidates;

    candidates = newArray;

    candidateCount++;
}

void JobPortalSystem::addHR(
    const HR& hr)
{
    if(emailExists(hr.getEmail()))
    {
        cout << "Email already exists." << endl;
        return;
    }

    HR* newArray =
        new HR[hrCount + 1];

    for(int i = 0; i < hrCount; i++)
    {
        newArray[i] = hrList[i];
    }

    newArray[hrCount] = hr;

    delete[] hrList;

    hrList = newArray;

    hrCount++;
}

void JobPortalSystem::addJob(
    const Job& job)
{
    if(jobExists(job.getJobId()))
    {
        cout << "Job ID already exists." << endl;
        return;
    }

    Job* newArray =
        new Job[jobCount + 1];

    for(int i = 0; i < jobCount; i++)
    {
        newArray[i] = jobs[i];
    }

    newArray[jobCount] = job;

    delete[] jobs;

    jobs = newArray;

    jobCount++;
}

void JobPortalSystem::registerHR()
{
    cout << "\n===== HR Registration =====\n";

    // Automatically generate HR ID
    int id = generateHRId();

    cout << "Generated HR ID: "
         << id
         << endl;

    cout << "Enter Name: ";

    string name = getValidName();

    cout << "Enter Email: ";

    string email = getValidGmail();

    string company;

    cout << "Enter Company Name: ";

    getline(cin, company);

    string designation;

    cout << "Enter Designation: ";

    getline(cin, designation);

    HR hr(
        id,
        name,
        email,
        company,
        designation
    );

    addHR(hr);

    cout << "\nHR Registered Successfully.\n";

    cout << "Your HR ID is: "
         << id
         << endl;
         pauseScreen();
}

void JobPortalSystem::addApplication(
    const Application& application)
{
    Application* newArray =
        new Application[applicationCount + 1];

    for(int i = 0; i < applicationCount; i++)
    {
        newArray[i] = applications[i];
    }

    newArray[applicationCount] = application;

    delete[] applications;

    applications = newArray;

    applicationCount++;
}

Candidate* JobPortalSystem::findCandidateById(int id)
{
    for(int i = 0; i < candidateCount; i++)
    {
        if(candidates[i].getUserId() == id)
        {
            return &candidates[i];
        }
    }

    return NULL;
}

HR* JobPortalSystem::findHRById(int id)
{
    for(int i = 0; i < hrCount; i++)
    {
        if(hrList[i].getUserId() == id)
        {
            return &hrList[i];
        }
    }

    return NULL;
}

Job* JobPortalSystem::findJobById(int id)
{
    for(int i = 0; i < jobCount; i++)
    {
        if(jobs[i].getJobId() == id)
        {
            return &jobs[i];
        }
    }

    return NULL;
}

Job* JobPortalSystem::getJobs() const
{
    return jobs;
}

int JobPortalSystem::getJobCount() const
{
    return jobCount;
}


void JobPortalSystem::displayAllCandidates() const
{
   

    cout << "\n";
    cout << "  =================================================\n";
    cout << "  |                ALL CANDIDATES                 |\n";
    cout << "  =================================================\n";
    cout << "\n";

    if(candidateCount == 0)
    {
        cout << "  No candidates found.\n";
        pauseScreen();
        return;
    }

   
    cout << "    ID       Name             Email            Exp    Edu   \n";
    

    for(int i = 0; i < candidateCount; i++)
    {
        cout << "    " 
             << setw(5) << left << candidates[i].getUserId() 
             << "   "
             << setw(14) << left << candidates[i].getName() 
             << "   ";

        string email = candidates[i].getEmail();
        if(email.length() > 14)
        {
            cout << email.substr(0, 14) << "   ";
        }
        else
        {
            cout << setw(14) << left << email << "   ";
        }

        cout << setw(4) << left << candidates[i].getExperienceYears() 
             << "   "
             << setw(4) << left << candidates[i].getEducation()
             << "  \n";
    }

    cout << " \n";
    cout << "\n  Total Candidates: " << candidateCount << "\n";

  
}

void JobPortalSystem::displayAllHRs() const
{
    if(hrCount == 0)
    {
        cout << "No HR records found." << endl;
        return;
    }

    for(int i = 0; i < hrCount; i++)
    {
        cout << endl;
        hrList[i].displayHRProfile();
    }
}

void JobPortalSystem::displayAllJobs() const
{
    if(jobCount == 0)
    {
        cout << "No jobs found." << endl;
        return;
    }

    for(int i = 0; i < jobCount; i++)
    {
        jobs[i].displayJob();
    }
}

void JobPortalSystem::displayAllApplications() const
{
    if(applicationCount == 0)
    {
        cout << "No applications found." << endl;
        return;
    }

    for(int i = 0; i < applicationCount; i++)
    {
        applications[i].displayApplication();
    }
    
}

//Interactive
void JobPortalSystem::registerCandidate()
{
    cout << "\n===== Candidate Registration =====\n";

    // 1. Automatically generate and display the ID
    int id = generateCandidateId();
    cout << "Generated Candidate ID: " << id << endl;

    // 2. Collect other details
    cout << "Enter Name: ";
    string name = getValidName();

    cout << "Enter Email: ";
    string email = getValidGmail();

    cout << "Enter Experience (Years): ";
    int experience = getValidExperience();

    cout << "Enter Education: ";
    string education = getValidEducation();

    // 3. Create the object
    Candidate candidate(
        id,
        name,
        email,
        experience,
        education
    );

    // 4. Input Skills
    int totalSkills;
    cout << "How many skills? ";
    totalSkills = getValidChoice(1, 20);

    for(int i = 0; i < totalSkills; i++)
    {
        string skillName;
        cout << "\nSkill " << i + 1 << " Name: ";
        getline(cin, skillName);

        cout << "Level (1-10): ";
        int level = getValidSkillLevel();

        candidate.addSkill(skillName, level);
    }

    // 5. Save the object
   addCandidate(candidate);

cout << "\nCandidate Registered Successfully.\n";


}




void JobPortalSystem::createJob()
{
    cout << "\n===== Create Job =====\n";

    // Automatically generate Job ID
    int jobId = generateJobId();

    cout << "Generated Job ID: "
         << jobId
         << endl;

    cout << "Enter HR ID: ";

    int hrId = getValidID();

    if(findHRById(hrId) == NULL)
    {
        cout << "HR not found.\n";
        return;
    }

    string title;

    cout << "Enter Job Title: ";

    getline(cin, title);

    string location;

    cout << "Enter Location: ";

    getline(cin, location);

    string description;

    cout << "Enter Description: ";

    getline(cin, description);

    string type;

    cout << "Enter Employment Type: ";

    getline(cin, type);

    cout << "Required Experience: ";

    int experience = getValidExperience();

    cout << "Required Education: ";

    string education = getValidEducation();

    Job job(
        jobId,
        hrId,
        title,
        location,
        description,
        type,
        experience,
        education
    );

    int skillCount;

    cout << "How Many Required Skills? ";

    skillCount = getValidChoice(1, 20);

    for(int i = 0; i < skillCount; i++)
    {
        string skillName;

        cout << "\nSkill "
             << i + 1
             << " Name: ";

        getline(cin, skillName);

        cout << "Required Level (1-10): ";

        int level = getValidSkillLevel();

        job.addRequiredSkill(
            skillName,
            level
        );
    }

    addJob(job);

    cout << "\nJob Posted Successfully.\n";

    cout << "Job ID: "
         << jobId
         << endl;
         
}

bool JobPortalSystem::applicationExists(
    int candidateId,
    int jobId
) const
{
    for(int i = 0; i < applicationCount; i++)
    {
        if(
            applications[i].getCandidateId() == candidateId
            &&
            applications[i].getJobId() == jobId
        )
        {
            return true;
        }
    }

    return false;
}


void JobPortalSystem::applyForJob()
{
    cout << "\n===== Apply For Job =====\n";

    cout << "Enter Candidate ID: ";

    int candidateId = getValidID();

    Candidate* candidate =
        findCandidateById(candidateId);

    if(candidate == NULL)
    {
        cout << "Candidate not found.\n";
        return;
    }

    displayAllJobs();

    cout << "\nEnter Job ID: ";

    int jobId = getValidID();

    Job* job =
        findJobById(jobId);

    if(job == NULL)
    {
        cout << "Job not found.\n";
        return;
    }

    if(
        applicationExists(
            candidateId,
            jobId
        )
    )
    {
        cout << "Already applied.\n";
        return;
    }

    MatchingEngine engine;

    double score =
        engine.calculateOverallScore(
            *candidate,
            *job
        );

    // Automatically generate Application ID
    int applicationId =
        generateApplicationId();

    string date;

    cout << "Date (YYYY-MM-DD): ";

    getline(cin, date);

    Application application(
        applicationId,
        candidateId,
        jobId,
        date
    );

    application.setMatchScore(score);

    if(score >= 90)
    {
        application.setStatus(
            "Approved"
        );
    }
    else if(score >= 75)
    {
        application.setStatus(
            "Under Review"
        );
    }
    else if(score >= 60)
    {
        application.setStatus(
            "Recommended"
        );
    }
    else
    {
        application.setStatus(
            "Rejected"
        );
    }

    addApplication(application);

    cout << "\n===== APPLICATION RESULT =====\n";

    cout << "Application ID: "
         << applicationId
         << endl;

    cout << "Match Score: "
         << score
         << "%"
         << endl;

    cout << "Status: "
         << application.getStatus()
         << endl;

    if(score < 75)
    {
        GapAnalyzer analyzer;

        analyzer.findMissingSkills(
            *candidate,
            *job
        );

        analyzer.analyzeExperienceGap(
            *candidate,
            *job
        );

        JobRecommender recommender;

        recommender.recommendJobs(
            *candidate,
            jobs,
            jobCount,
            jobId
        );
    }

    cout << "\nApplication Submitted Successfully.\n";
}

void JobPortalSystem::candidateMenu()
{
   
    int choice;

    do
    {
       clearScreen();

        cout << "\n=================================\n";
        cout << "        CANDIDATE PORTAL\n";
        cout << "=================================\n";

        cout << "1. Register Candidate\n";
        cout << "2. View Candidates\n";
        cout << "3. Apply For Job\n";
        cout << "4. View Jobs\n";
        cout << "5. Back\n";

        cout << "\nEnter Choice: ";
        choice = getValidChoice(1, 5);

        switch(choice)
        {
            case 1:
                clearScreen();
                registerCandidate();
                pauseScreen();
                break;

            case 2:
                clearScreen();
                displayAllCandidates();
                pauseScreen();
                break;

            case 3:
                clearScreen();
                applyForJob();
                pauseScreen();
                break;

            case 4:
                clearScreen();
                displayAllJobs();
                pauseScreen();
                break;

            case 5:
                break;

            default:
                cout << "Invalid Choice\n";
                pauseScreen();
        }

    } while(choice != 5);
}

void JobPortalSystem::hrMenu()
{
   
    int choice;

    do
    {
        clearScreen();

        cout << "\n=================================\n";
        cout << "            HR PORTAL\n";
        cout << "=================================\n";

        cout << "1. Register HR\n";
        cout << "2. Post Job\n";
        cout << "3. View My Jobs\n";
        cout << "4. View All Applications\n";
        cout << "5. View Applications by Job\n";
        cout << "6. Approve Application\n";
        cout << "7. Reject Application\n";
        cout << "8. Back\n";

        cout << "\nEnter Choice: ";
        choice = getValidChoice(1, 8);

        switch(choice)
        {
            case 1:
                clearScreen();
                registerHR();
                pauseScreen();
                break;

            case 2:
                clearScreen();
                createJob();
                pauseScreen();
                break;

            case 3:
                clearScreen();
                displayAllJobs();
                pauseScreen();
                break;

            case 4:
                clearScreen();
                viewAllApplications();
                pauseScreen();
                break;

            case 5:
                clearScreen();
                viewApplicationsByJob();
                pauseScreen();
                break;

            case 6:
                clearScreen();
                approveApplication();
                pauseScreen();
                break;

            case 7:
                clearScreen();
                rejectApplication();
                pauseScreen();
                break;

            case 8:
                break;

            default:
                cout << "Invalid Choice\n";
                pauseScreen();
        }

    } while(choice != 8);
}

void JobPortalSystem::mainMenu()
{
    int choice;

    do
    {
        clearScreen();
       


        cout << "\n=================================\n";
        cout << "      Mini Linkedin\n";
        cout << "=================================\n";

        cout << "Candidates     : " << candidateCount << endl;
        cout << "HRs            : " << hrCount << endl;
        cout << "Jobs           : " << jobCount << endl;
        cout << "Applications   : " << applicationCount << endl;

        cout << "---------------------------------\n";

        cout << "1. Candidate Portal\n";
        cout << "2. HR Portal\n";
        cout << "3. View Jobs\n";
        cout << "4. View Applications\n";
        cout << "0. Save & Exit\n";

        cout << "\nEnter Choice: ";
        choice = getValidChoice(0, 4);

        switch(choice)
        {
            case 1:
                candidateMenu();
                break;

            case 2:
                hrMenu();
                break;

            case 3:
                clearScreen();
                displayAllJobs();
                pauseScreen();
                break;

            case 4:
                clearScreen();
                displayAllApplications();
                pauseScreen();
                break;

            case 0:
                clearScreen();

                saveAllData();

                cout << "\nData Saved Successfully." << endl;
                cout << "Good Bye!" << endl;

                break;

            default:
                cout << "Invalid Choice\n";
                pauseScreen();
        }

    } while(choice != 0);
}

int JobPortalSystem::getValidChoice(
    int min,
    int max
)
{
    int choice;

    cin >> choice;

    while(cin.fail() || choice < min || choice > max)
    {
        cin.clear();

        cin.ignore(
            10000,
            '\n'
        );

        cout << "Invalid. Enter "
             << min
             << " - "
             << max
             << ": ";

        cin >> choice;
    }

    cin.ignore(10000, '\n');

    return choice;
}

string JobPortalSystem::getValidGmail()
{
    string email;

    while(true)
    {
        getline(cin, email);

        if(email.length() >= 10)
        {
            string last10 = email.substr(
                email.length() - 10
            );

            if(last10 == "@gmail.com")
            {
                if(!emailExists(email))
                {
                    return email;
                }
                else
                {
                    cout << "Email already exists."
                         << endl;
                    cout << "Enter again: ";
                }
            }
            else
            {
                cout << "Must be @gmail.com"
                     << endl;
                cout << "Enter again: ";
            }
        }
        else
        {
            cout << "Invalid email."
                 << endl;
            cout << "Enter again: ";
        }
    }
}

string JobPortalSystem::getValidName()
{
    string name;

    while(true)
    {
        getline(cin, name);

        if(name.empty())
        {
            cout << "Name cannot be empty."
                 << endl;
            cout << "Enter again: ";
            continue;
        }

        bool valid = true;

        for(int i = 0; i < name.length(); i++)
        {
            if(
                !isalpha(name[i])
                &&
                name[i] != ' '
            )
            {
                valid = false;
                break;
            }
        }

        if(valid)
        {
            return name;
        }
        else
        {
            cout << "Only letters allowed."
                 << endl;
            cout << "Enter again: ";
        }
    }
}

string JobPortalSystem::getValidEducation()
{
    string edu;

    while(true)
    {
        getline(cin, edu);

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
            return upperEdu;
        }
        else
        {
            cout << "Enter: MATRIC, FSC, BS, MS, PHD"
                 << endl;
            cout << "Enter again: ";
        }
    }
}

int JobPortalSystem::getValidExperience()
{
    int exp;

    while(true)
    {
        cin >> exp;

        if(cin.fail() || exp < 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Invalid. Enter again: ";
        }
        else
        {
            cin.ignore(10000, '\n');
            return exp;
        }
    }
}

int JobPortalSystem::getValidID()
{
    int id;

    while(true)
    {
        cin >> id;

        if(cin.fail() || id <= 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Invalid. Enter again: ";
        }
        else
        {
            cin.ignore(10000, '\n');
            return id;
        }
    }
}

int JobPortalSystem::getValidSkillLevel()
{
    int level;

    while(true)
    {
        cin >> level;

        if(
            cin.fail()
            ||
            level < 1
            ||
            level > 10
        )
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Enter 1-10: ";
        }
        else
        {
            cin.ignore(10000, '\n');
            return level;
        }
    }
}

int JobPortalSystem::generateCandidateId() const
{
    return 1000 + candidateCount + 1;
}

int JobPortalSystem::generateHRId() const
{
    return 2000 + hrCount + 1;
}

int JobPortalSystem::generateJobId() const
{
    return 3000 + jobCount + 1;
}

int JobPortalSystem::generateApplicationId() const
{
    return 4000 + applicationCount + 1;
}

// View all applications
void JobPortalSystem::viewAllApplications() const
{
    if(applicationCount == 0)
    {
        cout << "\nNo applications found.\n";
        return;
    }

    cout << "\n===== ALL APPLICATIONS =====\n";

    for(int i = 0; i < applicationCount; i++)
    {
        applications[i].displayApplication();
    }
}

// View applications for a specific job
void JobPortalSystem::viewApplicationsByJob()
{
    cout << "\nEnter Job ID: ";
    int jobId = getValidID();

    bool found = false;

    for(int i = 0; i < applicationCount; i++)
    {
        if(applications[i].getJobId() == jobId)
        {
            applications[i].displayApplication();
            found = true;
        }
    }

    if(!found)
    {
        cout << "\nNo applications found for this job.\n";
    }
}

// Approve an application
void JobPortalSystem::approveApplication()
{
    cout << "\n===== Approve Application =====\n";

    cout << "Enter Application ID: ";
    int appId = getValidID();

    for(int i = 0; i < applicationCount; i++)
    {
        if(applications[i].getApplicationId() == appId)
        {
            if(applications[i].getStatus() == "Approved")
            {
                cout << "\nThis application is already Approved.\n";
                return;
            }

            applications[i].setStatus("Approved");

            cout << "\nApplication Approved Successfully.\n";
            return;
        }
    }

    cout << "\nApplication not found.\n";
    pauseScreen();
}

// Reject an application
void JobPortalSystem::rejectApplication()
{
    cout << "\n===== Reject Application =====\n";

    cout << "Enter Application ID: ";
    int appId = getValidID();

    for(int i = 0; i < applicationCount; i++)
    {
        if(applications[i].getApplicationId() == appId)
        {
            if(applications[i].getStatus() == "Rejected")
            {
                cout << "\nThis application is already Rejected.\n";
                return;
            }

            applications[i].setStatus("Rejected");

            cout << "\nApplication Rejected.\n";

            // Show recommendations if rejected
            Candidate* candidate =
                findCandidateById(
                    applications[i].getCandidateId()
                );

            Job* job =
                findJobById(
                    applications[i].getJobId()
                );

            if(candidate != NULL && job != NULL)
            {
                GapAnalyzer analyzer;

                analyzer.findMissingSkills(
                    *candidate,
                    *job
                );

                analyzer.analyzeExperienceGap(
                    *candidate,
                    *job
                );

                JobRecommender recommender;

                recommender.recommendJobs(
                    *candidate,
                    jobs,
                    jobCount,
                    applications[i].getJobId()
                );
            }

            return;
        }
    }

    cout << "\nApplication not found.\n";
    
pauseScreen(); 
}

void JobPortalSystem::loadAllData()
{
    FileManager::loadCandidates(
        candidates,
        candidateCount,
        "candidates.csv"
    );

    FileManager::loadCandidateSkills(
        candidates,
        candidateCount,
        "candidate_skills.csv"
    );

    FileManager::loadHRs(
        hrList,
        hrCount,
        "hrs.csv"
    );

    FileManager::loadJobs(
        jobs,
        jobCount,
        "jobs.csv"
    );

    FileManager::loadJobSkills(
        jobs,
        jobCount,
        "job_skills.csv"
    );

    FileManager::loadApplications(
        applications,
        applicationCount,
        "applications.csv"
    );
}
void JobPortalSystem::saveAllData()
{
    FileManager::saveCandidates(
        candidates,
        candidateCount,
        "candidates.csv"
    );

    FileManager::saveCandidateSkills(
        candidates,
        candidateCount,
        "candidate_skills.csv"
    );

    FileManager::saveHRs(
        hrList,
        hrCount,
        "hrs.csv"
    );

    FileManager::saveJobs(
        jobs,
        jobCount,
        "jobs.csv"
    );

    FileManager::saveJobSkills(
        jobs,
        jobCount,
        "job_skills.csv"
    );

    FileManager::saveApplications(
        applications,
        applicationCount,
        "applications.csv"
    );
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.get();
}