#include "FileManager.h"
#include <sstream>

// Helper: Split string by delimiter
static string getNextToken(string& str, char delimiter)
{
    size_t pos = str.find(delimiter);
    string token;

    if(pos != string::npos)
    {
        token = str.substr(0, pos);
        str = str.substr(pos + 1);
    }
    else
    {
        token = str;
        str = "";
    }

    return token;
}

// ============ CANDIDATES ============

void FileManager::saveCandidates(
    Candidate* candidates,
    int count,
    string filename
)
{
    ofstream file(filename);

    if(!file.is_open())
    {
        cout << "Error opening file: "
             << filename << endl;
        return;
    }

    file << "ID,Name,Email,"
         << "Experience,Education\n";

    for(int i = 0; i < count; i++)
    {
        file << candidates[i].getUserId()
             << ","
             << candidates[i].getName()
             << ","
             << candidates[i].getEmail()
             << ","
             << candidates[i]
                    .getExperienceYears()
             << ","
             << candidates[i]
                    .getEducation()
             << "\n";
    }

    file.close();

    cout << "Candidates saved to "
         << filename << endl;
}

int FileManager::loadCandidates(
    Candidate*& candidates,
    int& count,
    string filename
)
{
    ifstream file(filename);

    if(!file.is_open())
    {
        cout << "No existing candidate file."
             << endl;
        return 0;
    }

    string line;

    // Skip header
    getline(file, line);

    count = 0;

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        string temp = line;

        string idStr =
            getNextToken(temp, ',');
        string name =
            getNextToken(temp, ',');
        string email =
            getNextToken(temp, ',');
        string expStr =
            getNextToken(temp, ',');
        string edu =
            getNextToken(temp, ',');

        int id = stoi(idStr);
        int exp = stoi(expStr);

        Candidate c(id, name, email, exp, edu);

        // Resize array
        Candidate* newArr =
            new Candidate[count + 1];

        for(int i = 0; i < count; i++)
        {
            newArr[i] = candidates[i];
        }

        newArr[count] = c;

        delete[] candidates;

        candidates = newArr;

        count++;
    }

    file.close();

    cout << count
         << " candidates loaded from "
         << filename << endl;

    return count;
}

// ============ CANDIDATE SKILLS ============

void FileManager::saveCandidateSkills(
    Candidate* candidates,
    int count,
    string filename
)
{
    ofstream file(filename);

    if(!file.is_open())
    {
        cout << "Error opening file: "
             << filename << endl;
        return;
    }

    file << "CandidateID,SkillName,SkillLevel\n";

    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < candidates[i].getSkillCount(); j++)
        {
            Skill skill =
                candidates[i].getSkillAt(j);

            file << candidates[i].getUserId()
                 << ","
                 << skill.getSkillName()
                 << ","
                 << skill.getSkillLevel()
                 << "\n";
        }
    }

    file.close();

    cout << "Candidate skills saved to "
         << filename << endl;
}

void FileManager::loadCandidateSkills(
    Candidate* candidates,
    int count,
    string filename
)
{
    ifstream file(filename);

    if(!file.is_open())
    {
        cout << "No existing candidate skills file."
             << endl;
        return;
    }

    string line;

    // Skip header
    getline(file, line);

    while(getline(file, line))
    {
        if(line.empty())
        {
            continue;
        }

        string temp = line;

        string idStr =
            getNextToken(temp, ',');

        string skillName =
            getNextToken(temp, ',');

        string levelStr =
            getNextToken(temp, ',');

        int candidateId = stoi(idStr);
        int skillLevel = stoi(levelStr);

        for(int i = 0; i < count; i++)
        {
            if(candidates[i].getUserId() == candidateId)
            {
                candidates[i].addSkill(
                    skillName,
                    skillLevel
                );

                break;
            }
        }
    }

    file.close();

    cout << "Candidate skills loaded from "
         << filename << endl;
}


// ============ HRs ============

void FileManager::saveHRs(
    HR* hrList,
    int count,
    string filename
)
{
    ofstream file(filename);

    if(!file.is_open())
    {
        cout << "Error opening file: "
             << filename << endl;
        return;
    }

    file << "ID,Name,Email,"
         << "Company,Designation\n";

    for(int i = 0; i < count; i++)
    {
        file << hrList[i].getUserId()
             << ","
             << hrList[i].getName()
             << ","
             << hrList[i].getEmail()
             << ","
             << hrList[i].getCompanyName()
             << ","
             << hrList[i].getDesignation()
             << "\n";
    }

    file.close();

    cout << "HRs saved to "
         << filename << endl;
}

int FileManager::loadHRs(
    HR*& hrList,
    int& count,
    string filename
)
{
    ifstream file(filename);

    if(!file.is_open())
    {
        cout << "No existing HR file."
             << endl;
        return 0;
    }

    string line;

    // Skip header
    getline(file, line);

    count = 0;

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        string temp = line;

        string idStr =
            getNextToken(temp, ',');
        string name =
            getNextToken(temp, ',');
        string email =
            getNextToken(temp, ',');
        string company =
            getNextToken(temp, ',');
        string desig =
            getNextToken(temp, ',');

        int id = stoi(idStr);

        HR h(id, name, email,
             company, desig);

        HR* newArr =
            new HR[count + 1];

        for(int i = 0; i < count; i++)
        {
            newArr[i] = hrList[i];
        }

        newArr[count] = h;

        delete[] hrList;

        hrList = newArr;

        count++;
    }

    file.close();

    cout << count
         << " HRs loaded from "
         << filename << endl;

    return count;
}

// ============ JOBS ============

void FileManager::saveJobs(
    Job* jobs,
    int count,
    string filename
)
{
    ofstream file(filename);

    if(!file.is_open())
    {
        cout << "Error opening file: "
             << filename << endl;
        return;
    }

    file << "ID,HRID,Title,Location,"
         << "Description,Type,"
         << "Experience,Education,"
         << "Status\n";

    for(int i = 0; i < count; i++)
    {
        file << jobs[i].getJobId()
             << ","
             << jobs[i].getHRId()
             << ","
             << jobs[i].getTitle()
             << ","
             << jobs[i].getLocation()
             << ","
             << jobs[i].getDescription()
             << ","
             << jobs[i].getEmploymentType()
             << ","
             << jobs[i]
                    .getRequiredExperience()
             << ","
             << jobs[i]
                    .getRequiredEducation()
             << ","
             << (jobs[i].getStatus()
                     ? "Active"
                     : "Closed")
             << "\n";
    }

    file.close();

    cout << "Jobs saved to "
         << filename << endl;
}

int FileManager::loadJobs(
    Job*& jobs,
    int& count,
    string filename
)
{
    ifstream file(filename);

    if(!file.is_open())
    {
        cout << "No existing job file."
             << endl;
        return 0;
    }

    string line;

    // Skip header
    getline(file, line);

    count = 0;

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        string temp = line;

        string idStr =
            getNextToken(temp, ',');
        string hrIdStr =
            getNextToken(temp, ',');
        string title =
            getNextToken(temp, ',');
        string loc =
            getNextToken(temp, ',');
        string desc =
            getNextToken(temp, ',');
        string type =
            getNextToken(temp, ',');
        string expStr =
            getNextToken(temp, ',');
        string edu =
            getNextToken(temp, ',');
        string statusStr =
            getNextToken(temp, ',');

        int id = stoi(idStr);
        int hrId = stoi(hrIdStr);
        int exp = stoi(expStr);

        Job j(id, hrId, title, loc,
              desc, type, exp, edu);

        if(statusStr == "Closed")
        {
            j.closeJob();
        }

        Job* newArr =
            new Job[count + 1];

        for(int i = 0; i < count; i++)
        {
            newArr[i] = jobs[i];
        }

        newArr[count] = j;

        delete[] jobs;

        jobs = newArr;

        count++;
    }

    file.close();

    cout << count
         << " jobs loaded from "
         << filename << endl;

    return count;
}

// ============ JOB SKILLS ============

void FileManager::saveJobSkills(
    Job* jobs,
    int count,
    string filename
)
{
    ofstream file(filename);

    if(!file.is_open())
    {
        cout << "Error opening file: "
             << filename << endl;
        return;
    }

    file << "JobID,SkillName,SkillLevel\n";

    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < jobs[i].getSkillCount(); j++)
        {
            Skill skill =
                jobs[i].getRequiredSkillAt(j);

            file << jobs[i].getJobId()
                 << ","
                 << skill.getSkillName()
                 << ","
                 << skill.getSkillLevel()
                 << "\n";
        }
    }

    file.close();

    cout << "Job skills saved to "
         << filename << endl;
}

void FileManager::loadJobSkills(
    Job* jobs,
    int count,
    string filename
)
{
    ifstream file(filename);

    if(!file.is_open())
    {
        cout << "No existing job skills file."
             << endl;
        return;
    }

    string line;

    // Skip header
    getline(file, line);

    while(getline(file, line))
    {
        if(line.empty())
        {
            continue;
        }

        string temp = line;

        string idStr =
            getNextToken(temp, ',');

        string skillName =
            getNextToken(temp, ',');

        string levelStr =
            getNextToken(temp, ',');

        int jobId = stoi(idStr);
        int skillLevel = stoi(levelStr);

        for(int i = 0; i < count; i++)
        {
            if(jobs[i].getJobId() == jobId)
            {
                jobs[i].addRequiredSkill(
                    skillName,
                    skillLevel
                );

                break;
            }
        }
    }

    file.close();

    cout << "Job skills loaded from "
         << filename << endl;
}

// ============ APPLICATIONS ============

void FileManager::saveApplications(
    Application* apps,
    int count,
    string filename
)
{
    ofstream file(filename);

    if(!file.is_open())
    {
        cout << "Error opening file: "
             << filename << endl;
        return;
    }

    file << "AppID,CandidateID,"
         << "JobID,Date,Status,MatchScore\n";

    for(int i = 0; i < count; i++)
    {
        file << apps[i].getApplicationId()
             << ","
             << apps[i].getCandidateId()
             << ","
             << apps[i].getJobId()
             << ","
             << apps[i].getApplicationDate()
             << ","
             << apps[i].getStatus()
             << ","
             << apps[i].getMatchScore()
             << "\n";
    }

    file.close();

    cout << "Applications saved to "
         << filename << endl;
}

int FileManager::loadApplications(
    Application*& apps,
    int& count,
    string filename
)
{
    ifstream file(filename);

    if(!file.is_open())
    {
        cout << "No existing application file."
             << endl;
        return 0;
    }

    string line;

    // Skip header
    getline(file, line);

    count = 0;

    while(getline(file, line))
    {
        if(line.empty())
        {
            continue;
        }

        string temp = line;

        string appIdStr =
            getNextToken(temp, ',');

        string cIdStr =
            getNextToken(temp, ',');

        string jIdStr =
            getNextToken(temp, ',');

        string date =
            getNextToken(temp, ',');

        string status =
            getNextToken(temp, ',');

        string scoreStr =
            getNextToken(temp, ',');

        int appId = stoi(appIdStr);
        int cId = stoi(cIdStr);
        int jId = stoi(jIdStr);

        Application a(appId, cId, jId, date);

        a.setStatus(status);

        if(!scoreStr.empty())
        {
            double score = stod(scoreStr);
            a.setMatchScore(score);
        }

        Application* newArr =
            new Application[count + 1];

        for(int i = 0; i < count; i++)
        {
            newArr[i] = apps[i];
        }

        newArr[count] = a;

        delete[] apps;

        apps = newArr;

        count++;
    }

    file.close();

    cout << count
         << " applications loaded from "
         << filename << endl;

    return count;
}